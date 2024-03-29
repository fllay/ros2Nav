// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from costmap_converter_msgs:msg/ObstacleMsg.idl
// generated code does not contain a copyright notice

#ifndef COSTMAP_CONVERTER_MSGS__MSG__DETAIL__OBSTACLE_MSG__STRUCT_H_
#define COSTMAP_CONVERTER_MSGS__MSG__DETAIL__OBSTACLE_MSG__STRUCT_H_

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
// Member 'polygon'
#include "geometry_msgs/msg/detail/polygon__struct.h"
// Member 'orientation'
#include "geometry_msgs/msg/detail/quaternion__struct.h"
// Member 'velocities'
#include "geometry_msgs/msg/detail/twist_with_covariance__struct.h"

/// Struct defined in msg/ObstacleMsg in the package costmap_converter_msgs.
/**
  * Special types:
  * Polygon with 1 vertex: Point obstacle (you might also specify a non-zero value for radius)
  * Polygon with 2 vertices: Line obstacle
  * Polygon with more than 2 vertices: First and last points are assumed to be connected
 */
typedef struct costmap_converter_msgs__msg__ObstacleMsg
{
  std_msgs__msg__Header header;
  /// Obstacle footprint (polygon descriptions)
  geometry_msgs__msg__Polygon polygon;
  /// Specify the radius for circular/point obstacles
  double radius;
  /// Obstacle ID
  /// Specify IDs in order to provide (temporal) relationships
  /// between obstacles among multiple messages.
  int64_t id;
  /// Individual orientation (centroid)
  geometry_msgs__msg__Quaternion orientation;
  /// Individual velocities (centroid)
  geometry_msgs__msg__TwistWithCovariance velocities;
} costmap_converter_msgs__msg__ObstacleMsg;

// Struct for a sequence of costmap_converter_msgs__msg__ObstacleMsg.
typedef struct costmap_converter_msgs__msg__ObstacleMsg__Sequence
{
  costmap_converter_msgs__msg__ObstacleMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} costmap_converter_msgs__msg__ObstacleMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COSTMAP_CONVERTER_MSGS__MSG__DETAIL__OBSTACLE_MSG__STRUCT_H_
