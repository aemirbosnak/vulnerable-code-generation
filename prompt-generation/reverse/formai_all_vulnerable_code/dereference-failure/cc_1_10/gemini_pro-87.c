//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Robot movement control example program

// Define the robot's state
typedef struct {
  double x;
  double y;
  double theta;
} RobotState;

// Define the robot's movement commands
typedef enum {
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT,
  STOP
} RobotCommand;

// Define the robot's movement parameters
typedef struct {
  double speed;
  double angular_speed;
} RobotParameters;

// Create a new robot state
RobotState *robot_state_new() {
  RobotState *state = malloc(sizeof(RobotState));
  state->x = 0.0;
  state->y = 0.0;
  state->theta = 0.0;
  return state;
}

// Free a robot state
void robot_state_free(RobotState *state) {
  free(state);
}

// Update the robot's state based on a movement command
void robot_state_update(RobotState *state, RobotCommand command, RobotParameters *params) {
  switch (command) {
    case FORWARD:
      state->x += params->speed * cos(state->theta);
      state->y += params->speed * sin(state->theta);
      break;
    case BACKWARD:
      state->x -= params->speed * cos(state->theta);
      state->y -= params->speed * sin(state->theta);
      break;
    case LEFT:
      state->theta -= params->angular_speed;
      break;
    case RIGHT:
      state->theta += params->angular_speed;
      break;
    case STOP:
      break;
  }
}

// Print the robot's state
void robot_state_print(RobotState *state) {
  printf("x: %.2f, y: %.2f, theta: %.2f\n", state->x, state->y, state->theta);
}

// Main function
int main() {
  // Create a new robot state
  RobotState *state = robot_state_new();

  // Define the robot's movement parameters
  RobotParameters params;
  params.speed = 1.0;
  params.angular_speed = M_PI / 4.0;

  // Update the robot's state based on a movement command
  robot_state_update(state, FORWARD, &params);
  robot_state_update(state, LEFT, &params);
  robot_state_update(state, BACKWARD, &params);
  robot_state_update(state, RIGHT, &params);

  // Print the robot's state
  robot_state_print(state);

  // Free the robot state
  robot_state_free(state);

  return 0;
}