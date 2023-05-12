// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from teb_msgs:msg/TrajectoryMsg.idl
// generated code does not contain a copyright notice
#include "teb_msgs/msg/detail/trajectory_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `trajectory`
#include "teb_msgs/msg/detail/trajectory_point_msg__functions.h"

bool
teb_msgs__msg__TrajectoryMsg__init(teb_msgs__msg__TrajectoryMsg * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    teb_msgs__msg__TrajectoryMsg__fini(msg);
    return false;
  }
  // trajectory
  if (!teb_msgs__msg__TrajectoryPointMsg__Sequence__init(&msg->trajectory, 0)) {
    teb_msgs__msg__TrajectoryMsg__fini(msg);
    return false;
  }
  return true;
}

void
teb_msgs__msg__TrajectoryMsg__fini(teb_msgs__msg__TrajectoryMsg * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // trajectory
  teb_msgs__msg__TrajectoryPointMsg__Sequence__fini(&msg->trajectory);
}

bool
teb_msgs__msg__TrajectoryMsg__are_equal(const teb_msgs__msg__TrajectoryMsg * lhs, const teb_msgs__msg__TrajectoryMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // trajectory
  if (!teb_msgs__msg__TrajectoryPointMsg__Sequence__are_equal(
      &(lhs->trajectory), &(rhs->trajectory)))
  {
    return false;
  }
  return true;
}

bool
teb_msgs__msg__TrajectoryMsg__copy(
  const teb_msgs__msg__TrajectoryMsg * input,
  teb_msgs__msg__TrajectoryMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // trajectory
  if (!teb_msgs__msg__TrajectoryPointMsg__Sequence__copy(
      &(input->trajectory), &(output->trajectory)))
  {
    return false;
  }
  return true;
}

teb_msgs__msg__TrajectoryMsg *
teb_msgs__msg__TrajectoryMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  teb_msgs__msg__TrajectoryMsg * msg = (teb_msgs__msg__TrajectoryMsg *)allocator.allocate(sizeof(teb_msgs__msg__TrajectoryMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(teb_msgs__msg__TrajectoryMsg));
  bool success = teb_msgs__msg__TrajectoryMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
teb_msgs__msg__TrajectoryMsg__destroy(teb_msgs__msg__TrajectoryMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    teb_msgs__msg__TrajectoryMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
teb_msgs__msg__TrajectoryMsg__Sequence__init(teb_msgs__msg__TrajectoryMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  teb_msgs__msg__TrajectoryMsg * data = NULL;

  if (size) {
    data = (teb_msgs__msg__TrajectoryMsg *)allocator.zero_allocate(size, sizeof(teb_msgs__msg__TrajectoryMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = teb_msgs__msg__TrajectoryMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        teb_msgs__msg__TrajectoryMsg__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
teb_msgs__msg__TrajectoryMsg__Sequence__fini(teb_msgs__msg__TrajectoryMsg__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      teb_msgs__msg__TrajectoryMsg__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

teb_msgs__msg__TrajectoryMsg__Sequence *
teb_msgs__msg__TrajectoryMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  teb_msgs__msg__TrajectoryMsg__Sequence * array = (teb_msgs__msg__TrajectoryMsg__Sequence *)allocator.allocate(sizeof(teb_msgs__msg__TrajectoryMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = teb_msgs__msg__TrajectoryMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
teb_msgs__msg__TrajectoryMsg__Sequence__destroy(teb_msgs__msg__TrajectoryMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    teb_msgs__msg__TrajectoryMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
teb_msgs__msg__TrajectoryMsg__Sequence__are_equal(const teb_msgs__msg__TrajectoryMsg__Sequence * lhs, const teb_msgs__msg__TrajectoryMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!teb_msgs__msg__TrajectoryMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
teb_msgs__msg__TrajectoryMsg__Sequence__copy(
  const teb_msgs__msg__TrajectoryMsg__Sequence * input,
  teb_msgs__msg__TrajectoryMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(teb_msgs__msg__TrajectoryMsg);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    teb_msgs__msg__TrajectoryMsg * data =
      (teb_msgs__msg__TrajectoryMsg *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!teb_msgs__msg__TrajectoryMsg__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          teb_msgs__msg__TrajectoryMsg__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!teb_msgs__msg__TrajectoryMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
