// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from teb_msgs:msg/FeedbackMsg.idl
// generated code does not contain a copyright notice

#ifndef TEB_MSGS__MSG__DETAIL__FEEDBACK_MSG__STRUCT_H_
#define TEB_MSGS__MSG__DETAIL__FEEDBACK_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'trajectories'
#include "teb_msgs/msg/detail/trajectory_msg__struct.h"
// Member 'obstacles_msg'
#include "costmap_converter_msgs/msg/detail/obstacle_array_msg__struct.h"

/// Struct defined in msg/FeedbackMsg in the package teb_msgs.
/**
  * Message that contains intermediate results 
  * and diagnostics of the (predictive) planner.
 */
typedef struct teb_msgs__msg__FeedbackMsg
{
  std_msgs__msg__Header header;
  /// The planned trajectory (or if multiple plans exist, all of them)
  teb_msgs__msg__TrajectoryMsg__Sequence trajectories;
  /// Index of the trajectory in 'trajectories' that is selected currently
  uint16_t selected_trajectory_idx;
  /// List of active obstacles
  costmap_converter_msgs__msg__ObstacleArrayMsg obstacles_msg;
} teb_msgs__msg__FeedbackMsg;

// Struct for a sequence of teb_msgs__msg__FeedbackMsg.
typedef struct teb_msgs__msg__FeedbackMsg__Sequence
{
  teb_msgs__msg__FeedbackMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} teb_msgs__msg__FeedbackMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEB_MSGS__MSG__DETAIL__FEEDBACK_MSG__STRUCT_H_
