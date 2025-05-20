//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the drone's state machine states
enum drone_state {
  DRONE_STATE_IDLE,
  DRONE_STATE_TAKING_OFF,
  DRONE_STATE_FLYING,
  DRONE_STATE_LANDING,
  DRONE_STATE_ERROR
};

// Define the drone's remote control commands
enum drone_command {
  DRONE_COMMAND_TAKE_OFF,
  DRONE_COMMAND_LAND,
  DRONE_COMMAND_FLY_UP,
  DRONE_COMMAND_FLY_DOWN,
  DRONE_COMMAND_FLY_LEFT,
  DRONE_COMMAND_FLY_RIGHT,
  DRONE_COMMAND_STOP
};

// Define the drone's shape-shifting modes
enum drone_shape_mode {
  DRONE_SHAPE_MODE_QUADCOPTER,
  DRONE_SHAPE_MODE_AIRPLANE,
  DRONE_SHAPE_MODE_CAR
};

// Define the drone's structure
struct drone {
  enum drone_state state;
  enum drone_command command;
  enum drone_shape_mode shape_mode;
  int altitude;
  int speed;
  int position_x;
  int position_y;
  int position_z;
};

// Create a new drone
struct drone *drone_new() {
  struct drone *drone = malloc(sizeof(struct drone));
  drone->state = DRONE_STATE_IDLE;
  drone->command = DRONE_COMMAND_STOP;
  drone->shape_mode = DRONE_SHAPE_MODE_QUADCOPTER;
  drone->altitude = 0;
  drone->speed = 0;
  drone->position_x = 0;
  drone->position_y = 0;
  drone->position_z = 0;
  return drone;
}

// Delete a drone
void drone_delete(struct drone *drone) {
  free(drone);
}

// Send a command to the drone
void drone_send_command(struct drone *drone, enum drone_command command) {
  drone->command = command;
}

// Update the drone's state machine
void drone_update(struct drone *drone) {
  switch (drone->state) {
    case DRONE_STATE_IDLE:
      if (drone->command == DRONE_COMMAND_TAKE_OFF) {
        drone->state = DRONE_STATE_TAKING_OFF;
      }
      break;
    case DRONE_STATE_TAKING_OFF:
      if (drone->altitude >= 10) {
        drone->state = DRONE_STATE_FLYING;
      }
      break;
    case DRONE_STATE_FLYING:
      switch (drone->command) {
        case DRONE_COMMAND_LAND:
          drone->state = DRONE_STATE_LANDING;
          break;
        case DRONE_COMMAND_FLY_UP:
          drone->altitude++;
          break;
        case DRONE_COMMAND_FLY_DOWN:
          drone->altitude--;
          break;
        case DRONE_COMMAND_FLY_LEFT:
          drone->position_x--;
          break;
        case DRONE_COMMAND_FLY_RIGHT:
          drone->position_x++;
          break;
        case DRONE_COMMAND_STOP:
          drone->speed = 0;
          break;
      }
      break;
    case DRONE_STATE_LANDING:
      if (drone->altitude == 0) {
        drone->state = DRONE_STATE_IDLE;
      }
      break;
    case DRONE_STATE_ERROR:
      // Handle error state
      break;
  }
}

// Print the drone's state
void drone_print_state(struct drone *drone) {
  switch (drone->state) {
    case DRONE_STATE_IDLE:
      printf("Drone is idle.\n");
      break;
    case DRONE_STATE_TAKING_OFF:
      printf("Drone is taking off.\n");
      break;
    case DRONE_STATE_FLYING:
      printf("Drone is flying.\n");
      break;
    case DRONE_STATE_LANDING:
      printf("Drone is landing.\n");
      break;
    case DRONE_STATE_ERROR:
      printf("Drone is in error state.\n");
      break;
  }
}

// Main function
int main() {
  // Create a new drone
  struct drone *drone = drone_new();

  // Send commands to the drone
  drone_send_command(drone, DRONE_COMMAND_TAKE_OFF);
  drone_send_command(drone, DRONE_COMMAND_FLY_UP);
  drone_send_command(drone, DRONE_COMMAND_FLY_RIGHT);
  drone_send_command(drone, DRONE_COMMAND_FLY_DOWN);
  drone_send_command(drone, DRONE_COMMAND_FLY_LEFT);
  drone_send_command(drone, DRONE_COMMAND_LAND);

  // Update the drone's state machine
  drone_update(drone);

  // Print the drone's state
  drone_print_state(drone);

  // Delete the drone
  drone_delete(drone);

  return 0;
}