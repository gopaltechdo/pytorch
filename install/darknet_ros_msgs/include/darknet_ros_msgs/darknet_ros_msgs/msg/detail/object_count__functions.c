// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from darknet_ros_msgs:msg/ObjectCount.idl
// generated code does not contain a copyright notice
#include "darknet_ros_msgs/msg/detail/object_count__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
darknet_ros_msgs__msg__ObjectCount__init(darknet_ros_msgs__msg__ObjectCount * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    darknet_ros_msgs__msg__ObjectCount__fini(msg);
    return false;
  }
  // count
  return true;
}

void
darknet_ros_msgs__msg__ObjectCount__fini(darknet_ros_msgs__msg__ObjectCount * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // count
}

bool
darknet_ros_msgs__msg__ObjectCount__are_equal(const darknet_ros_msgs__msg__ObjectCount * lhs, const darknet_ros_msgs__msg__ObjectCount * rhs)
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
  // count
  if (lhs->count != rhs->count) {
    return false;
  }
  return true;
}

bool
darknet_ros_msgs__msg__ObjectCount__copy(
  const darknet_ros_msgs__msg__ObjectCount * input,
  darknet_ros_msgs__msg__ObjectCount * output)
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
  // count
  output->count = input->count;
  return true;
}

darknet_ros_msgs__msg__ObjectCount *
darknet_ros_msgs__msg__ObjectCount__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__msg__ObjectCount * msg = (darknet_ros_msgs__msg__ObjectCount *)allocator.allocate(sizeof(darknet_ros_msgs__msg__ObjectCount), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(darknet_ros_msgs__msg__ObjectCount));
  bool success = darknet_ros_msgs__msg__ObjectCount__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
darknet_ros_msgs__msg__ObjectCount__destroy(darknet_ros_msgs__msg__ObjectCount * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    darknet_ros_msgs__msg__ObjectCount__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
darknet_ros_msgs__msg__ObjectCount__Sequence__init(darknet_ros_msgs__msg__ObjectCount__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__msg__ObjectCount * data = NULL;

  if (size) {
    data = (darknet_ros_msgs__msg__ObjectCount *)allocator.zero_allocate(size, sizeof(darknet_ros_msgs__msg__ObjectCount), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = darknet_ros_msgs__msg__ObjectCount__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        darknet_ros_msgs__msg__ObjectCount__fini(&data[i - 1]);
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
darknet_ros_msgs__msg__ObjectCount__Sequence__fini(darknet_ros_msgs__msg__ObjectCount__Sequence * array)
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
      darknet_ros_msgs__msg__ObjectCount__fini(&array->data[i]);
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

darknet_ros_msgs__msg__ObjectCount__Sequence *
darknet_ros_msgs__msg__ObjectCount__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__msg__ObjectCount__Sequence * array = (darknet_ros_msgs__msg__ObjectCount__Sequence *)allocator.allocate(sizeof(darknet_ros_msgs__msg__ObjectCount__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = darknet_ros_msgs__msg__ObjectCount__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
darknet_ros_msgs__msg__ObjectCount__Sequence__destroy(darknet_ros_msgs__msg__ObjectCount__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    darknet_ros_msgs__msg__ObjectCount__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
darknet_ros_msgs__msg__ObjectCount__Sequence__are_equal(const darknet_ros_msgs__msg__ObjectCount__Sequence * lhs, const darknet_ros_msgs__msg__ObjectCount__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!darknet_ros_msgs__msg__ObjectCount__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
darknet_ros_msgs__msg__ObjectCount__Sequence__copy(
  const darknet_ros_msgs__msg__ObjectCount__Sequence * input,
  darknet_ros_msgs__msg__ObjectCount__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(darknet_ros_msgs__msg__ObjectCount);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    darknet_ros_msgs__msg__ObjectCount * data =
      (darknet_ros_msgs__msg__ObjectCount *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!darknet_ros_msgs__msg__ObjectCount__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          darknet_ros_msgs__msg__ObjectCount__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!darknet_ros_msgs__msg__ObjectCount__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
