//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Robot struct with position and orientation
typedef struct {
  float x;
  float y;
  float theta;
} Robot;

// Function to create a new Robot
Robot* robot_create(float x, float y, float theta) {
  Robot* robot = malloc(sizeof(Robot));
  robot->x = x;
  robot->y = y;
  robot->theta = theta;
  return robot;
}

// Function to move the robot forward by a certain distance
void robot_move_forward(Robot* robot, float distance) {
  robot->x += distance * cos(robot->theta);
  robot->y += distance * sin(robot->theta);
}

// Function to turn the robot by a certain angle
void robot_turn(Robot* robot, float angle) {
  robot->theta += angle;
}

// Function to print the robot's position and orientation
void robot_print_info(Robot* robot) {
  printf("Robot is at position (%f, %f) and facing an angle of %f degrees.\n", robot->x, robot->y, robot->theta * 180 / M_PI);
}

// Main function
int main() {
  // Create a new robot
  Robot* robot = robot_create(0, 0, 0);

  // Move the robot forward by 10 units
  robot_move_forward(robot, 10);

  // Turn the robot by 90 degrees
  robot_turn(robot, M_PI / 2);

  // Move the robot forward by another 10 units
  robot_move_forward(robot, 10);

  // Print the robot's position and orientation
  robot_print_info(robot);

  // Free the robot's memory
  free(robot);

  return 0;
}