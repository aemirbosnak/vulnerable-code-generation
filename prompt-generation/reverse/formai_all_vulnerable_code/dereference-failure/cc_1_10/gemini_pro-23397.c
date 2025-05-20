//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define the robot's state
enum robot_state {
  IDLE,
  MOVING,
  STOPPED
};

// Define the robot's direction
enum robot_direction {
  NORTH,
  EAST,
  SOUTH,
  WEST
};

// Define the robot's speed
enum robot_speed {
  SLOW,
  MEDIUM,
  FAST
};

// Define the robot's structure
struct robot {
  enum robot_state state;
  enum robot_direction direction;
  enum robot_speed speed;
  int x;
  int y;
};

// Create a new robot
struct robot *create_robot() {
  struct robot *robot = malloc(sizeof(struct robot));
  if (robot == NULL) {
    return NULL;
  }

  robot->state = IDLE;
  robot->direction = NORTH;
  robot->speed = SLOW;
  robot->x = 0;
  robot->y = 0;

  return robot;
}

// Destroy a robot
void destroy_robot(struct robot *robot) {
  if (robot != NULL) {
    free(robot);
  }
}

// Move the robot forward
void move_forward(struct robot *robot) {
  if (robot->state != MOVING) {
    return;
  }

  switch (robot->direction) {
    case NORTH:
      robot->y += robot->speed;
      break;
    case EAST:
      robot->x += robot->speed;
      break;
    case SOUTH:
      robot->y -= robot->speed;
      break;
    case WEST:
      robot->x -= robot->speed;
      break;
  }
}

// Move the robot backward
void move_backward(struct robot *robot) {
  if (robot->state != MOVING) {
    return;
  }

  switch (robot->direction) {
    case NORTH:
      robot->y -= robot->speed;
      break;
    case EAST:
      robot->x -= robot->speed;
      break;
    case SOUTH:
      robot->y += robot->speed;
      break;
    case WEST:
      robot->x += robot->speed;
      break;
  }
}

// Turn the robot left
void turn_left(struct robot *robot) {
  if (robot->state != MOVING) {
    return;
  }

  switch (robot->direction) {
    case NORTH:
      robot->direction = WEST;
      break;
    case EAST:
      robot->direction = NORTH;
      break;
    case SOUTH:
      robot->direction = EAST;
      break;
    case WEST:
      robot->direction = SOUTH;
      break;
  }
}

// Turn the robot right
void turn_right(struct robot *robot) {
  if (robot->state != MOVING) {
    return;
  }

  switch (robot->direction) {
    case NORTH:
      robot->direction = EAST;
      break;
    case EAST:
      robot->direction = SOUTH;
      break;
    case SOUTH:
      robot->direction = WEST;
      break;
    case WEST:
      robot->direction = NORTH;
      break;
  }
}

// Set the robot's speed
void set_speed(struct robot *robot, enum robot_speed speed) {
  robot->speed = speed;
}

// Get the robot's speed
enum robot_speed get_speed(struct robot *robot) {
  return robot->speed;
}

// Get the robot's direction
enum robot_direction get_direction(struct robot *robot) {
  return robot->direction;
}

// Get the robot's state
enum robot_state get_state(struct robot *robot) {
  return robot->state;
}

// Print the robot's state
void print_robot_state(struct robot *robot) {
  printf("Robot state: ");
  switch (robot->state) {
    case IDLE:
      printf("IDLE");
      break;
    case MOVING:
      printf("MOVING");
      break;
    case STOPPED:
      printf("STOPPED");
      break;
  }
  printf("\n");
}

// Print the robot's direction
void print_robot_direction(struct robot *robot) {
  printf("Robot direction: ");
  switch (robot->direction) {
    case NORTH:
      printf("NORTH");
      break;
    case EAST:
      printf("EAST");
      break;
    case SOUTH:
      printf("SOUTH");
      break;
    case WEST:
      printf("WEST");
      break;
  }
  printf("\n");
}

// Print the robot's speed
void print_robot_speed(struct robot *robot) {
  printf("Robot speed: ");
  switch (robot->speed) {
    case SLOW:
      printf("SLOW");
      break;
    case MEDIUM:
      printf("MEDIUM");
      break;
    case FAST:
      printf("FAST");
      break;
  }
  printf("\n");
}

// Print the robot's position
void print_robot_position(struct robot *robot) {
  printf("Robot position: (%d, %d)\n", robot->x, robot->y);
}

// Main function
int main() {
  // Create a new robot
  struct robot *robot = create_robot();

  // Set the robot's speed
  set_speed(robot, MEDIUM);

  // Move the robot forward
  move_forward(robot);

  // Turn the robot left
  turn_left(robot);

  // Move the robot forward
  move_forward(robot);

  // Turn the robot right
  turn_right(robot);

  // Move the robot backward
  move_backward(robot);

  // Stop the robot
  robot->state = STOPPED;

  // Print the robot's state
  print_robot_state(robot);

  // Print the robot's direction
  print_robot_direction(robot);

  // Print the robot's speed
  print_robot_speed(robot);

  // Print the robot's position
  print_robot_position(robot);

  // Destroy the robot
  destroy_robot(robot);

  return 0;
}