#include <micro_ros_arduino.h>
#include <stdio.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>


#include <nav_msgs/msg/odometry.h>
#include <std_msgs/msg/int32.h>

#include <geometry_msgs/msg/twist.h>
#include <geometry_msgs/msg/vector3.h>

#include "odometry.h"

#include <Dynamixel2Arduino.h>
#include "Kinematics.h"


#if defined(__OPENCM904__)
#define DEVICE_NAME "3"  //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP
#elif defined(__OPENCR__)
#define DEVICE_NAME ""
#endif



#define LINO_BASE DIFFERENTIAL_DRIVE  // 2WD and Tracked robot w/ 2 motors
#define MAX_RPM 100                   // motor's maximum RPM
#define WHEEL_DIAMETER 0.066          // wheel's diameter in meters
//#define LR_WHEELS_DISTANCE 0.16       // distance between left and right wheels 0.800
#define LR_WHEELS_DISTANCE 0.12  // distance between left and right wheels 0.800
#define FR_WHEELS_DISTANCE 0.30  // distance between front and rear wheels. Ignore this if you're on 2WD/ACKERMANN



#define BAUDRATE 57600
#define DXL_ID_LEFT 1
#define DXL_ID_RIGHT 2

#define DXL_SERIAL Serial1
#define DEBUG_SERIAL Serial
const int DXL_DIR_PIN = -1;

const float DXL_PROTOCOL_VERSION = 2.0;

uint8_t dxl_id[2] = { DXL_ID_LEFT, DXL_ID_RIGHT };

#define LED_PIN 13

#define RCCHECK(fn) \
  { \
    rcl_ret_t temp_rc = fn; \
    if ((temp_rc != RCL_RET_OK)) { rclErrorLoop(); } \
  }
#define RCSOFTCHECK(fn) \
  { \
    rcl_ret_t temp_rc = fn; \
    if ((temp_rc != RCL_RET_OK)) {} \
  }
#define EXECUTE_EVERY_N_MS(MS, X) \
  do { \
    static volatile int64_t init = -1; \
    if (init == -1) { init = uxr_millis(); } \
    if (uxr_millis() - init > MS) { \
      X; \
      init = uxr_millis(); \
    } \
  } while (0)

rcl_publisher_t odom_publisher;
rcl_publisher_t publisher;
rcl_subscription_t twist_subscriber;

nav_msgs__msg__Odometry odom_msg;
geometry_msgs__msg__Twist twist_msg;


rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;
rcl_timer_t control_timer;

unsigned long long time_offset = 0;
unsigned long prev_cmd_time = 0;
unsigned long prev_odom_update = 0;

Odometry odometry;
int32_t present_velocity[2] = { 0, 0 };
bool result = false;
const uint8_t handler_index = 0;
int currentLeftWheelRPM;
int currentRightWheelRPM;

uint16_t model_number = 0;

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

//This namespace is required to use Control table item names
using namespace ControlTableItem;

Kinematics kinematics(Kinematics::LINO_BASE, MAX_RPM, WHEEL_DIAMETER, FR_WHEELS_DISTANCE, LR_WHEELS_DISTANCE);

enum states {
  WAITING_AGENT,
  AGENT_AVAILABLE,
  AGENT_CONNECTED,
  AGENT_DISCONNECTED
} state;


void setLeftRPM(int rpm) {

  dxl.setGoalVelocity(DXL_ID_LEFT, rpm, UNIT_RPM);
}

void setRightRPM(int rpm) {
  dxl.setGoalVelocity(DXL_ID_RIGHT, -1*rpm, UNIT_RPM);
}


int getLeftRPM(){

  currentLeftWheelRPM = (int) dxl.getPresentVelocity(DXL_ID_LEFT, UNIT_RPM);
  return currentLeftWheelRPM;
}


int getRightRPM() {

  currentRightWheelRPM = -1* ((int) dxl.getPresentVelocity(DXL_ID_RIGHT, UNIT_RPM));
  return -1*currentRightWheelRPM;
}

void setup() {
  const char* log;
  pinMode(LED_PIN, OUTPUT);
  set_microros_transports();

  dxl.begin(57600);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  // Get DYNAMIXEL information
  dxl.ping(DXL_ID_LEFT);

  // Turn off torque when configuring items in EEPROM area
  dxl.torqueOff(DXL_ID_LEFT);
  dxl.setOperatingMode(DXL_ID_LEFT, OP_VELOCITY);
  dxl.torqueOn(DXL_ID_LEFT);
  //dxl.setGoalVelocity(DXL_ID_LEFT, 10.0, UNIT_RPM);
  dxl.setGoalVelocity(DXL_ID_LEFT, 0.0, UNIT_RPM);
  

  dxl.ping(DXL_ID_RIGHT);

  // Turn off torque when configuring items in EEPROM area
  dxl.torqueOff(DXL_ID_RIGHT);
  dxl.setOperatingMode(DXL_ID_RIGHT, OP_VELOCITY);
  dxl.torqueOn(DXL_ID_RIGHT);
  //dxl.setGoalVelocity(DXL_ID_RIGHT, 10.0, UNIT_RPM);
  dxl.setGoalVelocity(DXL_ID_RIGHT, 0.0, UNIT_RPM);


}

void loop() {
  switch (state) {
    case WAITING_AGENT:
      EXECUTE_EVERY_N_MS(500, state = (RMW_RET_OK == rmw_uros_ping_agent(100, 1)) ? AGENT_AVAILABLE : WAITING_AGENT;);
      break;
    case AGENT_AVAILABLE:
      state = (true == createEntities()) ? AGENT_CONNECTED : WAITING_AGENT;
      if (state == WAITING_AGENT) {
        destroyEntities();
      }
      break;
    case AGENT_CONNECTED:
      EXECUTE_EVERY_N_MS(200, state = (RMW_RET_OK == rmw_uros_ping_agent(100, 1)) ? AGENT_CONNECTED : AGENT_DISCONNECTED;);
      if (state == AGENT_CONNECTED) {
        rclc_executor_spin_some(&executor, RCL_MS_TO_NS(20));
      }
      break;
    case AGENT_DISCONNECTED:
      destroyEntities();
      state = WAITING_AGENT;
      break;
    default:
      break;
  }
}

void controlCallback(rcl_timer_t* timer, int64_t last_call_time) {
  RCLC_UNUSED(last_call_time);
  if (timer != NULL) {
    moveBase();
  }
}

void twistCallback(const void* msgin) {
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  Kinematics::rpm req_rpm = kinematics.getRPM(
    twist_msg.linear.x,
    twist_msg.linear.y,
    twist_msg.angular.z);

  setLeftRPM(req_rpm.motor1);
  setRightRPM(req_rpm.motor2);
  prev_cmd_time = millis();
}

void moveBase() {

  /*if (((millis() - prev_cmd_time) >= 200)) {
    twist_msg.linear.x = 0.0;
    twist_msg.linear.y = 0.0;
    twist_msg.angular.z = 0.0;

    digitalWrite(LED_PIN, HIGH);
  }*/
  // get the required rpm for each motor based on required velocities, and base used
 
  getRightRPM();
  getLeftRPM();
  int current_rpm1 = currentLeftWheelRPM;   //rightWheel.getRPM();
  int current_rpm2 = currentRightWheelRPM;  //leftWheel.getRPM();
  int current_rpm3 = 0;
  int current_rpm4 = 0;


  Kinematics::velocities current_vel = kinematics.getVelocities(current_rpm1, current_rpm2, current_rpm3, current_rpm4);
  //current_vel = kinematics.getVelocities(50, 50, 0, 0);




  unsigned long now = millis();
  float vel_dt = (now - prev_odom_update) / 1000.0;
  prev_odom_update = now;
  odometry.update(
    vel_dt,
    current_vel.linear_x,
    current_vel.linear_y,
    current_vel.angular_z);

  odom_msg = odometry.getData();
  struct timespec time_stamp = getTime();
  odom_msg.header.stamp.sec = time_stamp.tv_sec;
  odom_msg.header.stamp.nanosec = time_stamp.tv_nsec;
  RCSOFTCHECK(rcl_publish(&odom_publisher, &odom_msg, NULL));
}

bool createEntities() {
  allocator = rcl_get_default_allocator();
  //create init_options
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));
  // create node
  RCCHECK(rclc_node_init_default(&node, "move_base_node", "", &support));
  // create odometry publisher
  RCCHECK(rclc_publisher_init_default(
    &odom_publisher,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(nav_msgs, msg, Odometry),
    "odom/unfiltered"));


  // create twist command subscriber
  RCCHECK(rclc_subscription_init_default(
    &twist_subscriber,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
    "cmd_vel"));

  // create timer for actuating the motors at 50 Hz (1000/20)
  const unsigned int control_timeout_odom = 40;
  RCCHECK(rclc_timer_init_default(
    &control_timer,
    &support,
    RCL_MS_TO_NS(control_timeout_odom),
    controlCallback));

  executor = rclc_executor_get_zero_initialized_executor();
  RCCHECK(rclc_executor_init(&executor, &support.context, 2, &allocator));



  RCCHECK(rclc_executor_add_subscription(
    &executor,
    &twist_subscriber,
    &twist_msg,
    &twistCallback,
    ON_NEW_DATA));

  RCCHECK(rclc_executor_add_timer(&executor, &control_timer));

  // synchronize time with the agent
  syncTime();
  digitalWrite(LED_PIN, HIGH);

  return true;
}

bool destroyEntities() {
  rmw_context_t* rmw_context = rcl_context_get_rmw_context(&support.context);
  (void)rmw_uros_set_context_entity_destroy_session_timeout(rmw_context, 0);

  rcl_publisher_fini(&odom_publisher, &node);
  rcl_node_fini(&node);
  rcl_timer_fini(&control_timer);
  rclc_executor_fini(&executor);
  rclc_support_fini(&support);

  digitalWrite(LED_PIN, HIGH);

  return true;
}


void syncTime() {
  // get the current time from the agent
  unsigned long now = millis();
  RCCHECK(rmw_uros_sync_session(10));
  unsigned long long ros_time_ms = rmw_uros_epoch_millis();
  // now we can find the difference between ROS time and uC time
  time_offset = ros_time_ms - now;
}

struct timespec getTime() {
  struct timespec tp = { 0 };
  // add time difference between uC time and ROS time to
  // synchronize time with ROS
  unsigned long long now = millis() + time_offset;
  tp.tv_sec = now / 1000;
  tp.tv_nsec = (now % 1000) * 1000000;

  return tp;
}

void rclErrorLoop() {
  while (1) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    delay(100);
  }
}