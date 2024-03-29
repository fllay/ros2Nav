// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from teb_msgs:msg/TrajectoryMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "teb_msgs/msg/detail/trajectory_msg__rosidl_typesupport_introspection_c.h"
#include "teb_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "teb_msgs/msg/detail/trajectory_msg__functions.h"
#include "teb_msgs/msg/detail/trajectory_msg__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `trajectory`
#include "teb_msgs/msg/trajectory_point_msg.h"
// Member `trajectory`
#include "teb_msgs/msg/detail/trajectory_point_msg__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__TrajectoryMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  teb_msgs__msg__TrajectoryMsg__init(message_memory);
}

void teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__TrajectoryMsg_fini_function(void * message_memory)
{
  teb_msgs__msg__TrajectoryMsg__fini(message_memory);
}

size_t teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__size_function__TrajectoryMsg__trajectory(
  const void * untyped_member)
{
  const teb_msgs__msg__TrajectoryPointMsg__Sequence * member =
    (const teb_msgs__msg__TrajectoryPointMsg__Sequence *)(untyped_member);
  return member->size;
}

const void * teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__get_const_function__TrajectoryMsg__trajectory(
  const void * untyped_member, size_t index)
{
  const teb_msgs__msg__TrajectoryPointMsg__Sequence * member =
    (const teb_msgs__msg__TrajectoryPointMsg__Sequence *)(untyped_member);
  return &member->data[index];
}

void * teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__get_function__TrajectoryMsg__trajectory(
  void * untyped_member, size_t index)
{
  teb_msgs__msg__TrajectoryPointMsg__Sequence * member =
    (teb_msgs__msg__TrajectoryPointMsg__Sequence *)(untyped_member);
  return &member->data[index];
}

void teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__fetch_function__TrajectoryMsg__trajectory(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const teb_msgs__msg__TrajectoryPointMsg * item =
    ((const teb_msgs__msg__TrajectoryPointMsg *)
    teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__get_const_function__TrajectoryMsg__trajectory(untyped_member, index));
  teb_msgs__msg__TrajectoryPointMsg * value =
    (teb_msgs__msg__TrajectoryPointMsg *)(untyped_value);
  *value = *item;
}

void teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__assign_function__TrajectoryMsg__trajectory(
  void * untyped_member, size_t index, const void * untyped_value)
{
  teb_msgs__msg__TrajectoryPointMsg * item =
    ((teb_msgs__msg__TrajectoryPointMsg *)
    teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__get_function__TrajectoryMsg__trajectory(untyped_member, index));
  const teb_msgs__msg__TrajectoryPointMsg * value =
    (const teb_msgs__msg__TrajectoryPointMsg *)(untyped_value);
  *item = *value;
}

bool teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__resize_function__TrajectoryMsg__trajectory(
  void * untyped_member, size_t size)
{
  teb_msgs__msg__TrajectoryPointMsg__Sequence * member =
    (teb_msgs__msg__TrajectoryPointMsg__Sequence *)(untyped_member);
  teb_msgs__msg__TrajectoryPointMsg__Sequence__fini(member);
  return teb_msgs__msg__TrajectoryPointMsg__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__TrajectoryMsg_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(teb_msgs__msg__TrajectoryMsg, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "trajectory",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(teb_msgs__msg__TrajectoryMsg, trajectory),  // bytes offset in struct
    NULL,  // default value
    teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__size_function__TrajectoryMsg__trajectory,  // size() function pointer
    teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__get_const_function__TrajectoryMsg__trajectory,  // get_const(index) function pointer
    teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__get_function__TrajectoryMsg__trajectory,  // get(index) function pointer
    teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__fetch_function__TrajectoryMsg__trajectory,  // fetch(index, &value) function pointer
    teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__assign_function__TrajectoryMsg__trajectory,  // assign(index, value) function pointer
    teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__resize_function__TrajectoryMsg__trajectory  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__TrajectoryMsg_message_members = {
  "teb_msgs__msg",  // message namespace
  "TrajectoryMsg",  // message name
  2,  // number of fields
  sizeof(teb_msgs__msg__TrajectoryMsg),
  teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__TrajectoryMsg_message_member_array,  // message members
  teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__TrajectoryMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__TrajectoryMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__TrajectoryMsg_message_type_support_handle = {
  0,
  &teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__TrajectoryMsg_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_teb_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, teb_msgs, msg, TrajectoryMsg)() {
  teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__TrajectoryMsg_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__TrajectoryMsg_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, teb_msgs, msg, TrajectoryPointMsg)();
  if (!teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__TrajectoryMsg_message_type_support_handle.typesupport_identifier) {
    teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__TrajectoryMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &teb_msgs__msg__TrajectoryMsg__rosidl_typesupport_introspection_c__TrajectoryMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
