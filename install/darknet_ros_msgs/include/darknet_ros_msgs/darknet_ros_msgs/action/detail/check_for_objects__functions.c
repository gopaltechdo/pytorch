// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from darknet_ros_msgs:action/CheckForObjects.idl
// generated code does not contain a copyright notice
#include "darknet_ros_msgs/action/detail/check_for_objects__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `image`
#include "sensor_msgs/msg/detail/image__functions.h"

bool
darknet_ros_msgs__action__CheckForObjects_Goal__init(darknet_ros_msgs__action__CheckForObjects_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // image
  if (!sensor_msgs__msg__Image__init(&msg->image)) {
    darknet_ros_msgs__action__CheckForObjects_Goal__fini(msg);
    return false;
  }
  return true;
}

void
darknet_ros_msgs__action__CheckForObjects_Goal__fini(darknet_ros_msgs__action__CheckForObjects_Goal * msg)
{
  if (!msg) {
    return;
  }
  // id
  // image
  sensor_msgs__msg__Image__fini(&msg->image);
}

bool
darknet_ros_msgs__action__CheckForObjects_Goal__are_equal(const darknet_ros_msgs__action__CheckForObjects_Goal * lhs, const darknet_ros_msgs__action__CheckForObjects_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->image), &(rhs->image)))
  {
    return false;
  }
  return true;
}

bool
darknet_ros_msgs__action__CheckForObjects_Goal__copy(
  const darknet_ros_msgs__action__CheckForObjects_Goal * input,
  darknet_ros_msgs__action__CheckForObjects_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // image
  if (!sensor_msgs__msg__Image__copy(
      &(input->image), &(output->image)))
  {
    return false;
  }
  return true;
}

darknet_ros_msgs__action__CheckForObjects_Goal *
darknet_ros_msgs__action__CheckForObjects_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_Goal * msg = (darknet_ros_msgs__action__CheckForObjects_Goal *)allocator.allocate(sizeof(darknet_ros_msgs__action__CheckForObjects_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(darknet_ros_msgs__action__CheckForObjects_Goal));
  bool success = darknet_ros_msgs__action__CheckForObjects_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
darknet_ros_msgs__action__CheckForObjects_Goal__destroy(darknet_ros_msgs__action__CheckForObjects_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    darknet_ros_msgs__action__CheckForObjects_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
darknet_ros_msgs__action__CheckForObjects_Goal__Sequence__init(darknet_ros_msgs__action__CheckForObjects_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_Goal * data = NULL;

  if (size) {
    data = (darknet_ros_msgs__action__CheckForObjects_Goal *)allocator.zero_allocate(size, sizeof(darknet_ros_msgs__action__CheckForObjects_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = darknet_ros_msgs__action__CheckForObjects_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        darknet_ros_msgs__action__CheckForObjects_Goal__fini(&data[i - 1]);
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
darknet_ros_msgs__action__CheckForObjects_Goal__Sequence__fini(darknet_ros_msgs__action__CheckForObjects_Goal__Sequence * array)
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
      darknet_ros_msgs__action__CheckForObjects_Goal__fini(&array->data[i]);
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

darknet_ros_msgs__action__CheckForObjects_Goal__Sequence *
darknet_ros_msgs__action__CheckForObjects_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_Goal__Sequence * array = (darknet_ros_msgs__action__CheckForObjects_Goal__Sequence *)allocator.allocate(sizeof(darknet_ros_msgs__action__CheckForObjects_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = darknet_ros_msgs__action__CheckForObjects_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
darknet_ros_msgs__action__CheckForObjects_Goal__Sequence__destroy(darknet_ros_msgs__action__CheckForObjects_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    darknet_ros_msgs__action__CheckForObjects_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
darknet_ros_msgs__action__CheckForObjects_Goal__Sequence__are_equal(const darknet_ros_msgs__action__CheckForObjects_Goal__Sequence * lhs, const darknet_ros_msgs__action__CheckForObjects_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!darknet_ros_msgs__action__CheckForObjects_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
darknet_ros_msgs__action__CheckForObjects_Goal__Sequence__copy(
  const darknet_ros_msgs__action__CheckForObjects_Goal__Sequence * input,
  darknet_ros_msgs__action__CheckForObjects_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(darknet_ros_msgs__action__CheckForObjects_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    darknet_ros_msgs__action__CheckForObjects_Goal * data =
      (darknet_ros_msgs__action__CheckForObjects_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!darknet_ros_msgs__action__CheckForObjects_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          darknet_ros_msgs__action__CheckForObjects_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!darknet_ros_msgs__action__CheckForObjects_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `bounding_boxes`
#include "darknet_ros_msgs/msg/detail/bounding_boxes__functions.h"

bool
darknet_ros_msgs__action__CheckForObjects_Result__init(darknet_ros_msgs__action__CheckForObjects_Result * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // bounding_boxes
  if (!darknet_ros_msgs__msg__BoundingBoxes__init(&msg->bounding_boxes)) {
    darknet_ros_msgs__action__CheckForObjects_Result__fini(msg);
    return false;
  }
  return true;
}

void
darknet_ros_msgs__action__CheckForObjects_Result__fini(darknet_ros_msgs__action__CheckForObjects_Result * msg)
{
  if (!msg) {
    return;
  }
  // id
  // bounding_boxes
  darknet_ros_msgs__msg__BoundingBoxes__fini(&msg->bounding_boxes);
}

bool
darknet_ros_msgs__action__CheckForObjects_Result__are_equal(const darknet_ros_msgs__action__CheckForObjects_Result * lhs, const darknet_ros_msgs__action__CheckForObjects_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // bounding_boxes
  if (!darknet_ros_msgs__msg__BoundingBoxes__are_equal(
      &(lhs->bounding_boxes), &(rhs->bounding_boxes)))
  {
    return false;
  }
  return true;
}

bool
darknet_ros_msgs__action__CheckForObjects_Result__copy(
  const darknet_ros_msgs__action__CheckForObjects_Result * input,
  darknet_ros_msgs__action__CheckForObjects_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // bounding_boxes
  if (!darknet_ros_msgs__msg__BoundingBoxes__copy(
      &(input->bounding_boxes), &(output->bounding_boxes)))
  {
    return false;
  }
  return true;
}

darknet_ros_msgs__action__CheckForObjects_Result *
darknet_ros_msgs__action__CheckForObjects_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_Result * msg = (darknet_ros_msgs__action__CheckForObjects_Result *)allocator.allocate(sizeof(darknet_ros_msgs__action__CheckForObjects_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(darknet_ros_msgs__action__CheckForObjects_Result));
  bool success = darknet_ros_msgs__action__CheckForObjects_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
darknet_ros_msgs__action__CheckForObjects_Result__destroy(darknet_ros_msgs__action__CheckForObjects_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    darknet_ros_msgs__action__CheckForObjects_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
darknet_ros_msgs__action__CheckForObjects_Result__Sequence__init(darknet_ros_msgs__action__CheckForObjects_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_Result * data = NULL;

  if (size) {
    data = (darknet_ros_msgs__action__CheckForObjects_Result *)allocator.zero_allocate(size, sizeof(darknet_ros_msgs__action__CheckForObjects_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = darknet_ros_msgs__action__CheckForObjects_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        darknet_ros_msgs__action__CheckForObjects_Result__fini(&data[i - 1]);
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
darknet_ros_msgs__action__CheckForObjects_Result__Sequence__fini(darknet_ros_msgs__action__CheckForObjects_Result__Sequence * array)
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
      darknet_ros_msgs__action__CheckForObjects_Result__fini(&array->data[i]);
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

darknet_ros_msgs__action__CheckForObjects_Result__Sequence *
darknet_ros_msgs__action__CheckForObjects_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_Result__Sequence * array = (darknet_ros_msgs__action__CheckForObjects_Result__Sequence *)allocator.allocate(sizeof(darknet_ros_msgs__action__CheckForObjects_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = darknet_ros_msgs__action__CheckForObjects_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
darknet_ros_msgs__action__CheckForObjects_Result__Sequence__destroy(darknet_ros_msgs__action__CheckForObjects_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    darknet_ros_msgs__action__CheckForObjects_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
darknet_ros_msgs__action__CheckForObjects_Result__Sequence__are_equal(const darknet_ros_msgs__action__CheckForObjects_Result__Sequence * lhs, const darknet_ros_msgs__action__CheckForObjects_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!darknet_ros_msgs__action__CheckForObjects_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
darknet_ros_msgs__action__CheckForObjects_Result__Sequence__copy(
  const darknet_ros_msgs__action__CheckForObjects_Result__Sequence * input,
  darknet_ros_msgs__action__CheckForObjects_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(darknet_ros_msgs__action__CheckForObjects_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    darknet_ros_msgs__action__CheckForObjects_Result * data =
      (darknet_ros_msgs__action__CheckForObjects_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!darknet_ros_msgs__action__CheckForObjects_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          darknet_ros_msgs__action__CheckForObjects_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!darknet_ros_msgs__action__CheckForObjects_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
darknet_ros_msgs__action__CheckForObjects_Feedback__init(darknet_ros_msgs__action__CheckForObjects_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
darknet_ros_msgs__action__CheckForObjects_Feedback__fini(darknet_ros_msgs__action__CheckForObjects_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
darknet_ros_msgs__action__CheckForObjects_Feedback__are_equal(const darknet_ros_msgs__action__CheckForObjects_Feedback * lhs, const darknet_ros_msgs__action__CheckForObjects_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
darknet_ros_msgs__action__CheckForObjects_Feedback__copy(
  const darknet_ros_msgs__action__CheckForObjects_Feedback * input,
  darknet_ros_msgs__action__CheckForObjects_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

darknet_ros_msgs__action__CheckForObjects_Feedback *
darknet_ros_msgs__action__CheckForObjects_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_Feedback * msg = (darknet_ros_msgs__action__CheckForObjects_Feedback *)allocator.allocate(sizeof(darknet_ros_msgs__action__CheckForObjects_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(darknet_ros_msgs__action__CheckForObjects_Feedback));
  bool success = darknet_ros_msgs__action__CheckForObjects_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
darknet_ros_msgs__action__CheckForObjects_Feedback__destroy(darknet_ros_msgs__action__CheckForObjects_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    darknet_ros_msgs__action__CheckForObjects_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
darknet_ros_msgs__action__CheckForObjects_Feedback__Sequence__init(darknet_ros_msgs__action__CheckForObjects_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_Feedback * data = NULL;

  if (size) {
    data = (darknet_ros_msgs__action__CheckForObjects_Feedback *)allocator.zero_allocate(size, sizeof(darknet_ros_msgs__action__CheckForObjects_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = darknet_ros_msgs__action__CheckForObjects_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        darknet_ros_msgs__action__CheckForObjects_Feedback__fini(&data[i - 1]);
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
darknet_ros_msgs__action__CheckForObjects_Feedback__Sequence__fini(darknet_ros_msgs__action__CheckForObjects_Feedback__Sequence * array)
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
      darknet_ros_msgs__action__CheckForObjects_Feedback__fini(&array->data[i]);
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

darknet_ros_msgs__action__CheckForObjects_Feedback__Sequence *
darknet_ros_msgs__action__CheckForObjects_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_Feedback__Sequence * array = (darknet_ros_msgs__action__CheckForObjects_Feedback__Sequence *)allocator.allocate(sizeof(darknet_ros_msgs__action__CheckForObjects_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = darknet_ros_msgs__action__CheckForObjects_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
darknet_ros_msgs__action__CheckForObjects_Feedback__Sequence__destroy(darknet_ros_msgs__action__CheckForObjects_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    darknet_ros_msgs__action__CheckForObjects_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
darknet_ros_msgs__action__CheckForObjects_Feedback__Sequence__are_equal(const darknet_ros_msgs__action__CheckForObjects_Feedback__Sequence * lhs, const darknet_ros_msgs__action__CheckForObjects_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!darknet_ros_msgs__action__CheckForObjects_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
darknet_ros_msgs__action__CheckForObjects_Feedback__Sequence__copy(
  const darknet_ros_msgs__action__CheckForObjects_Feedback__Sequence * input,
  darknet_ros_msgs__action__CheckForObjects_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(darknet_ros_msgs__action__CheckForObjects_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    darknet_ros_msgs__action__CheckForObjects_Feedback * data =
      (darknet_ros_msgs__action__CheckForObjects_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!darknet_ros_msgs__action__CheckForObjects_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          darknet_ros_msgs__action__CheckForObjects_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!darknet_ros_msgs__action__CheckForObjects_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "darknet_ros_msgs/action/detail/check_for_objects__functions.h"

bool
darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__init(darknet_ros_msgs__action__CheckForObjects_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!darknet_ros_msgs__action__CheckForObjects_Goal__init(&msg->goal)) {
    darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__fini(darknet_ros_msgs__action__CheckForObjects_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  darknet_ros_msgs__action__CheckForObjects_Goal__fini(&msg->goal);
}

bool
darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__are_equal(const darknet_ros_msgs__action__CheckForObjects_SendGoal_Request * lhs, const darknet_ros_msgs__action__CheckForObjects_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!darknet_ros_msgs__action__CheckForObjects_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__copy(
  const darknet_ros_msgs__action__CheckForObjects_SendGoal_Request * input,
  darknet_ros_msgs__action__CheckForObjects_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!darknet_ros_msgs__action__CheckForObjects_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

darknet_ros_msgs__action__CheckForObjects_SendGoal_Request *
darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_SendGoal_Request * msg = (darknet_ros_msgs__action__CheckForObjects_SendGoal_Request *)allocator.allocate(sizeof(darknet_ros_msgs__action__CheckForObjects_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(darknet_ros_msgs__action__CheckForObjects_SendGoal_Request));
  bool success = darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__destroy(darknet_ros_msgs__action__CheckForObjects_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__Sequence__init(darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_SendGoal_Request * data = NULL;

  if (size) {
    data = (darknet_ros_msgs__action__CheckForObjects_SendGoal_Request *)allocator.zero_allocate(size, sizeof(darknet_ros_msgs__action__CheckForObjects_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__fini(&data[i - 1]);
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
darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__Sequence__fini(darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__Sequence * array)
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
      darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__fini(&array->data[i]);
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

darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__Sequence *
darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__Sequence * array = (darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__Sequence *)allocator.allocate(sizeof(darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__Sequence__destroy(darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__Sequence__are_equal(const darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__Sequence * lhs, const darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__Sequence__copy(
  const darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__Sequence * input,
  darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(darknet_ros_msgs__action__CheckForObjects_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    darknet_ros_msgs__action__CheckForObjects_SendGoal_Request * data =
      (darknet_ros_msgs__action__CheckForObjects_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!darknet_ros_msgs__action__CheckForObjects_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__init(darknet_ros_msgs__action__CheckForObjects_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__fini(darknet_ros_msgs__action__CheckForObjects_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__are_equal(const darknet_ros_msgs__action__CheckForObjects_SendGoal_Response * lhs, const darknet_ros_msgs__action__CheckForObjects_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__copy(
  const darknet_ros_msgs__action__CheckForObjects_SendGoal_Response * input,
  darknet_ros_msgs__action__CheckForObjects_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

darknet_ros_msgs__action__CheckForObjects_SendGoal_Response *
darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_SendGoal_Response * msg = (darknet_ros_msgs__action__CheckForObjects_SendGoal_Response *)allocator.allocate(sizeof(darknet_ros_msgs__action__CheckForObjects_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(darknet_ros_msgs__action__CheckForObjects_SendGoal_Response));
  bool success = darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__destroy(darknet_ros_msgs__action__CheckForObjects_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__Sequence__init(darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_SendGoal_Response * data = NULL;

  if (size) {
    data = (darknet_ros_msgs__action__CheckForObjects_SendGoal_Response *)allocator.zero_allocate(size, sizeof(darknet_ros_msgs__action__CheckForObjects_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__fini(&data[i - 1]);
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
darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__Sequence__fini(darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__Sequence * array)
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
      darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__fini(&array->data[i]);
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

darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__Sequence *
darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__Sequence * array = (darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__Sequence *)allocator.allocate(sizeof(darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__Sequence__destroy(darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__Sequence__are_equal(const darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__Sequence * lhs, const darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__Sequence__copy(
  const darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__Sequence * input,
  darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(darknet_ros_msgs__action__CheckForObjects_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    darknet_ros_msgs__action__CheckForObjects_SendGoal_Response * data =
      (darknet_ros_msgs__action__CheckForObjects_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!darknet_ros_msgs__action__CheckForObjects_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
darknet_ros_msgs__action__CheckForObjects_GetResult_Request__init(darknet_ros_msgs__action__CheckForObjects_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    darknet_ros_msgs__action__CheckForObjects_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
darknet_ros_msgs__action__CheckForObjects_GetResult_Request__fini(darknet_ros_msgs__action__CheckForObjects_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
darknet_ros_msgs__action__CheckForObjects_GetResult_Request__are_equal(const darknet_ros_msgs__action__CheckForObjects_GetResult_Request * lhs, const darknet_ros_msgs__action__CheckForObjects_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
darknet_ros_msgs__action__CheckForObjects_GetResult_Request__copy(
  const darknet_ros_msgs__action__CheckForObjects_GetResult_Request * input,
  darknet_ros_msgs__action__CheckForObjects_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

darknet_ros_msgs__action__CheckForObjects_GetResult_Request *
darknet_ros_msgs__action__CheckForObjects_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_GetResult_Request * msg = (darknet_ros_msgs__action__CheckForObjects_GetResult_Request *)allocator.allocate(sizeof(darknet_ros_msgs__action__CheckForObjects_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(darknet_ros_msgs__action__CheckForObjects_GetResult_Request));
  bool success = darknet_ros_msgs__action__CheckForObjects_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
darknet_ros_msgs__action__CheckForObjects_GetResult_Request__destroy(darknet_ros_msgs__action__CheckForObjects_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    darknet_ros_msgs__action__CheckForObjects_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
darknet_ros_msgs__action__CheckForObjects_GetResult_Request__Sequence__init(darknet_ros_msgs__action__CheckForObjects_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_GetResult_Request * data = NULL;

  if (size) {
    data = (darknet_ros_msgs__action__CheckForObjects_GetResult_Request *)allocator.zero_allocate(size, sizeof(darknet_ros_msgs__action__CheckForObjects_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = darknet_ros_msgs__action__CheckForObjects_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        darknet_ros_msgs__action__CheckForObjects_GetResult_Request__fini(&data[i - 1]);
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
darknet_ros_msgs__action__CheckForObjects_GetResult_Request__Sequence__fini(darknet_ros_msgs__action__CheckForObjects_GetResult_Request__Sequence * array)
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
      darknet_ros_msgs__action__CheckForObjects_GetResult_Request__fini(&array->data[i]);
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

darknet_ros_msgs__action__CheckForObjects_GetResult_Request__Sequence *
darknet_ros_msgs__action__CheckForObjects_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_GetResult_Request__Sequence * array = (darknet_ros_msgs__action__CheckForObjects_GetResult_Request__Sequence *)allocator.allocate(sizeof(darknet_ros_msgs__action__CheckForObjects_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = darknet_ros_msgs__action__CheckForObjects_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
darknet_ros_msgs__action__CheckForObjects_GetResult_Request__Sequence__destroy(darknet_ros_msgs__action__CheckForObjects_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    darknet_ros_msgs__action__CheckForObjects_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
darknet_ros_msgs__action__CheckForObjects_GetResult_Request__Sequence__are_equal(const darknet_ros_msgs__action__CheckForObjects_GetResult_Request__Sequence * lhs, const darknet_ros_msgs__action__CheckForObjects_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!darknet_ros_msgs__action__CheckForObjects_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
darknet_ros_msgs__action__CheckForObjects_GetResult_Request__Sequence__copy(
  const darknet_ros_msgs__action__CheckForObjects_GetResult_Request__Sequence * input,
  darknet_ros_msgs__action__CheckForObjects_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(darknet_ros_msgs__action__CheckForObjects_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    darknet_ros_msgs__action__CheckForObjects_GetResult_Request * data =
      (darknet_ros_msgs__action__CheckForObjects_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!darknet_ros_msgs__action__CheckForObjects_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          darknet_ros_msgs__action__CheckForObjects_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!darknet_ros_msgs__action__CheckForObjects_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "darknet_ros_msgs/action/detail/check_for_objects__functions.h"

bool
darknet_ros_msgs__action__CheckForObjects_GetResult_Response__init(darknet_ros_msgs__action__CheckForObjects_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!darknet_ros_msgs__action__CheckForObjects_Result__init(&msg->result)) {
    darknet_ros_msgs__action__CheckForObjects_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
darknet_ros_msgs__action__CheckForObjects_GetResult_Response__fini(darknet_ros_msgs__action__CheckForObjects_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  darknet_ros_msgs__action__CheckForObjects_Result__fini(&msg->result);
}

bool
darknet_ros_msgs__action__CheckForObjects_GetResult_Response__are_equal(const darknet_ros_msgs__action__CheckForObjects_GetResult_Response * lhs, const darknet_ros_msgs__action__CheckForObjects_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!darknet_ros_msgs__action__CheckForObjects_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
darknet_ros_msgs__action__CheckForObjects_GetResult_Response__copy(
  const darknet_ros_msgs__action__CheckForObjects_GetResult_Response * input,
  darknet_ros_msgs__action__CheckForObjects_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!darknet_ros_msgs__action__CheckForObjects_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

darknet_ros_msgs__action__CheckForObjects_GetResult_Response *
darknet_ros_msgs__action__CheckForObjects_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_GetResult_Response * msg = (darknet_ros_msgs__action__CheckForObjects_GetResult_Response *)allocator.allocate(sizeof(darknet_ros_msgs__action__CheckForObjects_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(darknet_ros_msgs__action__CheckForObjects_GetResult_Response));
  bool success = darknet_ros_msgs__action__CheckForObjects_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
darknet_ros_msgs__action__CheckForObjects_GetResult_Response__destroy(darknet_ros_msgs__action__CheckForObjects_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    darknet_ros_msgs__action__CheckForObjects_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
darknet_ros_msgs__action__CheckForObjects_GetResult_Response__Sequence__init(darknet_ros_msgs__action__CheckForObjects_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_GetResult_Response * data = NULL;

  if (size) {
    data = (darknet_ros_msgs__action__CheckForObjects_GetResult_Response *)allocator.zero_allocate(size, sizeof(darknet_ros_msgs__action__CheckForObjects_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = darknet_ros_msgs__action__CheckForObjects_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        darknet_ros_msgs__action__CheckForObjects_GetResult_Response__fini(&data[i - 1]);
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
darknet_ros_msgs__action__CheckForObjects_GetResult_Response__Sequence__fini(darknet_ros_msgs__action__CheckForObjects_GetResult_Response__Sequence * array)
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
      darknet_ros_msgs__action__CheckForObjects_GetResult_Response__fini(&array->data[i]);
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

darknet_ros_msgs__action__CheckForObjects_GetResult_Response__Sequence *
darknet_ros_msgs__action__CheckForObjects_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_GetResult_Response__Sequence * array = (darknet_ros_msgs__action__CheckForObjects_GetResult_Response__Sequence *)allocator.allocate(sizeof(darknet_ros_msgs__action__CheckForObjects_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = darknet_ros_msgs__action__CheckForObjects_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
darknet_ros_msgs__action__CheckForObjects_GetResult_Response__Sequence__destroy(darknet_ros_msgs__action__CheckForObjects_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    darknet_ros_msgs__action__CheckForObjects_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
darknet_ros_msgs__action__CheckForObjects_GetResult_Response__Sequence__are_equal(const darknet_ros_msgs__action__CheckForObjects_GetResult_Response__Sequence * lhs, const darknet_ros_msgs__action__CheckForObjects_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!darknet_ros_msgs__action__CheckForObjects_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
darknet_ros_msgs__action__CheckForObjects_GetResult_Response__Sequence__copy(
  const darknet_ros_msgs__action__CheckForObjects_GetResult_Response__Sequence * input,
  darknet_ros_msgs__action__CheckForObjects_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(darknet_ros_msgs__action__CheckForObjects_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    darknet_ros_msgs__action__CheckForObjects_GetResult_Response * data =
      (darknet_ros_msgs__action__CheckForObjects_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!darknet_ros_msgs__action__CheckForObjects_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          darknet_ros_msgs__action__CheckForObjects_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!darknet_ros_msgs__action__CheckForObjects_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "darknet_ros_msgs/action/detail/check_for_objects__functions.h"

bool
darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__init(darknet_ros_msgs__action__CheckForObjects_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!darknet_ros_msgs__action__CheckForObjects_Feedback__init(&msg->feedback)) {
    darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__fini(darknet_ros_msgs__action__CheckForObjects_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  darknet_ros_msgs__action__CheckForObjects_Feedback__fini(&msg->feedback);
}

bool
darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__are_equal(const darknet_ros_msgs__action__CheckForObjects_FeedbackMessage * lhs, const darknet_ros_msgs__action__CheckForObjects_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!darknet_ros_msgs__action__CheckForObjects_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__copy(
  const darknet_ros_msgs__action__CheckForObjects_FeedbackMessage * input,
  darknet_ros_msgs__action__CheckForObjects_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!darknet_ros_msgs__action__CheckForObjects_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

darknet_ros_msgs__action__CheckForObjects_FeedbackMessage *
darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_FeedbackMessage * msg = (darknet_ros_msgs__action__CheckForObjects_FeedbackMessage *)allocator.allocate(sizeof(darknet_ros_msgs__action__CheckForObjects_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(darknet_ros_msgs__action__CheckForObjects_FeedbackMessage));
  bool success = darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__destroy(darknet_ros_msgs__action__CheckForObjects_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__Sequence__init(darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_FeedbackMessage * data = NULL;

  if (size) {
    data = (darknet_ros_msgs__action__CheckForObjects_FeedbackMessage *)allocator.zero_allocate(size, sizeof(darknet_ros_msgs__action__CheckForObjects_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__fini(&data[i - 1]);
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
darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__Sequence__fini(darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__Sequence * array)
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
      darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__fini(&array->data[i]);
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

darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__Sequence *
darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__Sequence * array = (darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__Sequence *)allocator.allocate(sizeof(darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__Sequence__destroy(darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__Sequence__are_equal(const darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__Sequence * lhs, const darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__Sequence__copy(
  const darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__Sequence * input,
  darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(darknet_ros_msgs__action__CheckForObjects_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    darknet_ros_msgs__action__CheckForObjects_FeedbackMessage * data =
      (darknet_ros_msgs__action__CheckForObjects_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!darknet_ros_msgs__action__CheckForObjects_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
