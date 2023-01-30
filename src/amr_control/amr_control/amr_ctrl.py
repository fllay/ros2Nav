from amr_interface.srv import StartStop
import asyncio
import osrf_pycommon

import rclpy
from rclpy.node import Node

import os
import sys
import time
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument
from ament_index_python.packages import get_package_share_directory
import launch_ros
from launch import LaunchDescription
from launch import LaunchService

#ls = None

class StartStopService(Node):

    def __init__(self):
        super().__init__('minimal_service')
        self.loop = osrf_pycommon.process_utils.get_loop()
        self.srv = self.create_service(StartStop, 'start_stop_launch', self.start_stop_callback)
        
        self.ls = LaunchService()
        config_witmotion = '/home/pi/amr_config/wt61c.yml'
        ekf_config_path = '/home/pi/amr_config/ekf.yaml'

        serial_port = LaunchConfiguration('serial_port', default='/dev/ttyUSB0')
        serial_baudrate = LaunchConfiguration('serial_baudrate', default='256000') #for A3 is 256000
        frame_id = LaunchConfiguration('frame_id', default='laser')
        inverted = LaunchConfiguration('inverted', default='false')
        angle_compensate = LaunchConfiguration('angle_compensate', default='true')
        scan_mode = LaunchConfiguration('scan_mode', default='Sensitivity')

        use_sim_time = LaunchConfiguration('use_sim_time', default='false')
        urdf = '/home/pi/amr_config/eru.urdf'

        # Major refactor of the robot_state_publisher
        # Reference page: https://github.com/ros2/demos/pull/426
        with open(urdf, 'r') as infp:
            robot_desc = infp.read()

        rsp_params = {'robot_description': robot_desc}

        self.ld = LaunchDescription([
            launch_ros.actions.Node(
                package='rplidar_ros2',
                executable='rplidar_scan_publisher',
                name='rplidar_scan_publisher',
                parameters=[{'serial_port': serial_port, 
                            'serial_baudrate': serial_baudrate, 
                            'frame_id': frame_id,
                            'inverted': inverted, 
                            'angle_compensate': angle_compensate, 
                            'scan_mode': scan_mode}],
                output='screen'),
            launch_ros.actions.Node(
                package='micro_ros_agent',
                executable='micro_ros_agent',
                name='micro_ros_agent',
                arguments=["serial", "--dev", "/dev/ttyACM0", "-v6"]
            ),
            launch_ros.actions. Node(
                package = 'witmotion_ros',
                executable = 'witmotion_ros_node',
                parameters = [config_witmotion]
            ),
            launch_ros.actions.Node(
                package='robot_localization',
                executable='ekf_node',
                name='ekf_filter_node',
                output='screen',
                parameters=[
                    ekf_config_path
                ],
                remappings=[("odometry/filtered", "odom")]
            ),
            DeclareLaunchArgument(
                'serial_port',
                default_value=serial_port,
                description='Specifying usb port to connected lidar'),

            DeclareLaunchArgument(
                'serial_baudrate',
                default_value=serial_baudrate,
                description='Specifying usb port baudrate to connected lidar'),
            
            DeclareLaunchArgument(
                'frame_id',
                default_value=frame_id,
                description='Specifying frame_id of lidar'),

            DeclareLaunchArgument(
                'inverted',
                default_value=inverted,
                description='Specifying whether or not to invert scan data'),

            DeclareLaunchArgument(
                'angle_compensate',
                default_value=angle_compensate,
                description='Specifying whether or not to enable angle_compensate of scan data'),

            DeclareLaunchArgument(
                'scan_mode',
                default_value=scan_mode,
                description='Specifying scan mode of lidar'),

            DeclareLaunchArgument(
                'use_sim_time',
                default_value='false',
                description='Use simulation (Gazebo) clock if true'),
            launch_ros.actions.Node(
                package='robot_state_publisher',
                executable='robot_state_publisher',
                output='screen',
                parameters=[rsp_params, {'use_sim_time': use_sim_time}])
        ])
        self.ls.include_launch_description(self.ld)




    def start_stop_callback(self, request, response):
        response.result = True
        self.get_logger().info('Incoming request\nin: %d' % (request.startstop))
        if request.startstop == True:
            self.get_logger().info('Incoming request to Start')
            launch_task = self.loop.create_task(ls.run_async())
            #self.ls.run_async()
            #self.ls.run()
        else:
            self.get_logger().info('Incoming request to Stop')
            self.ls.shutdown()

        return response

def main(args=None):
    rclpy.init(args=args)

    minimal_service = StartStopService()

    rclpy.spin(minimal_service)

    rclpy.shutdown()


if __name__ == '__main__':
    main()
