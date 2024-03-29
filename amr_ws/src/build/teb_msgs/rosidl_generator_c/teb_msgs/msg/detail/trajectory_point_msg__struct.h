// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from teb_msgs:msg/TrajectoryPointMsg.idl
// generated code does not contain a copyright notice

#ifndef TEB_MSGS__MSG__DETAIL__TRAJECTORY_POINT_MSG__STRUCT_H_
#define TEB_MSGS__MSG__DETAIL__TRAJECTORY_POINT_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'velocity'
// Member 'acceleration'
#include "geometry_msgs/msg/detail/twist__struct.h"
// Member 'time_from_start'
#include "builtin_interfaces/msg/detail/duration__struct.h"

/// Struct defined in msg/TrajectoryPointMsg in the package teb_msgs.
/**
  * Message that contains single point on a trajectory suited for mobile navigation.
  * The trajectory is described by a sequence of poses, velocities,
  * accelerations and temporal information.
 */
typedef struct teb_msgs__msg__TrajectoryPointMsg
{
  /// Why this message type?
  /// nav_msgs/Path describes only a path without temporal information.
  /// trajectory_msgs package contains only messages for joint trajectories.
  /// The pose of the robot
  geometry_msgs__msg__Pose pose;
  /// Corresponding velocity
  geometry_msgs__msg__Twist velocity;
  /// Corresponding acceleration
  geometry_msgs__msg__Twist acceleration;
  builtin_interfaces__msg__Duration time_from_start;
} teb_msgs__msg__TrajectoryPointMsg;

// Struct for a sequence of teb_msgs__msg__TrajectoryPointMsg.
typedef struct teb_msgs__msg__TrajectoryPointMsg__Sequence
{
  teb_msgs__msg__TrajectoryPointMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} teb_msgs__msg__TrajectoryPointMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEB_MSGS__MSG__DETAIL__TRAJECTORY_POINT_MSG__STRUCT_H_
