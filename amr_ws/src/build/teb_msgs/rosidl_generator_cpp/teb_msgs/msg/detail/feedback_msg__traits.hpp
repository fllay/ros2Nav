// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from teb_msgs:msg/FeedbackMsg.idl
// generated code does not contain a copyright notice

#ifndef TEB_MSGS__MSG__DETAIL__FEEDBACK_MSG__TRAITS_HPP_
#define TEB_MSGS__MSG__DETAIL__FEEDBACK_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "teb_msgs/msg/detail/feedback_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'trajectories'
#include "teb_msgs/msg/detail/trajectory_msg__traits.hpp"
// Member 'obstacles_msg'
#include "costmap_converter_msgs/msg/detail/obstacle_array_msg__traits.hpp"

namespace teb_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const FeedbackMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: trajectories
  {
    if (msg.trajectories.size() == 0) {
      out << "trajectories: []";
    } else {
      out << "trajectories: [";
      size_t pending_items = msg.trajectories.size();
      for (auto item : msg.trajectories) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: selected_trajectory_idx
  {
    out << "selected_trajectory_idx: ";
    rosidl_generator_traits::value_to_yaml(msg.selected_trajectory_idx, out);
    out << ", ";
  }

  // member: obstacles_msg
  {
    out << "obstacles_msg: ";
    to_flow_style_yaml(msg.obstacles_msg, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FeedbackMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: trajectories
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.trajectories.size() == 0) {
      out << "trajectories: []\n";
    } else {
      out << "trajectories:\n";
      for (auto item : msg.trajectories) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: selected_trajectory_idx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "selected_trajectory_idx: ";
    rosidl_generator_traits::value_to_yaml(msg.selected_trajectory_idx, out);
    out << "\n";
  }

  // member: obstacles_msg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obstacles_msg:\n";
    to_block_style_yaml(msg.obstacles_msg, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FeedbackMsg & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace teb_msgs

namespace rosidl_generator_traits
{

[[deprecated("use teb_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const teb_msgs::msg::FeedbackMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  teb_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use teb_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const teb_msgs::msg::FeedbackMsg & msg)
{
  return teb_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<teb_msgs::msg::FeedbackMsg>()
{
  return "teb_msgs::msg::FeedbackMsg";
}

template<>
inline const char * name<teb_msgs::msg::FeedbackMsg>()
{
  return "teb_msgs/msg/FeedbackMsg";
}

template<>
struct has_fixed_size<teb_msgs::msg::FeedbackMsg>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<teb_msgs::msg::FeedbackMsg>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<teb_msgs::msg::FeedbackMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TEB_MSGS__MSG__DETAIL__FEEDBACK_MSG__TRAITS_HPP_
