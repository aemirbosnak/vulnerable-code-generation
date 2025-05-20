//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the drone's states.
enum drone_state {
  DRONE_STATE_IDLE,
  DRONE_STATE_TAKEOFF,
  DRONE_STATE_FLYING,
  DRONE_STATE_LANDING,
  DRONE_STATE_CRASHED
};

// Define the drone's commands.
enum drone_command {
  DRONE_COMMAND_TAKEOFF,
  DRONE_COMMAND_LAND,
  DRONE_COMMAND_UP,
  DRONE_COMMAND_DOWN,
  DRONE_COMMAND_LEFT,
  DRONE_COMMAND_RIGHT,
  DRONE_COMMAND_FLIP,
  DRONE_COMMAND_CRASH
};

// Define the drone's structure.
struct drone {
  enum drone_state state;
  int altitude;
  int speed;
  int x;
  int y;
};

// Create a new drone.
struct drone *drone_new() {
  struct drone *drone = malloc(sizeof(struct drone));
  drone->state = DRONE_STATE_IDLE;
  drone->altitude = 0;
  drone->speed = 0;
  drone->x = 0;
  drone->y = 0;
  return drone;
}

// Destroy a drone.
void drone_destroy(struct drone *drone) {
  free(drone);
}

// Take off the drone.
void drone_takeoff(struct drone *drone) {
  if (drone->state == DRONE_STATE_IDLE) {
    drone->state = DRONE_STATE_TAKEOFF;
    drone->altitude = 1;
    drone->speed = 1;
  }
}

// Land the drone.
void drone_land(struct drone *drone) {
  if (drone->state == DRONE_STATE_FLYING) {
    drone->state = DRONE_STATE_LANDING;
    drone->altitude = 0;
    drone->speed = 0;
  }
}

// Move the drone up.
void drone_up(struct drone *drone) {
  if (drone->state == DRONE_STATE_FLYING) {
    drone->altitude++;
  }
}

// Move the drone down.
void drone_down(struct drone *drone) {
  if (drone->state == DRONE_STATE_FLYING) {
    drone->altitude--;
  }
}

// Move the drone left.
void drone_left(struct drone *drone) {
  if (drone->state == DRONE_STATE_FLYING) {
    drone->x--;
  }
}

// Move the drone right.
void drone_right(struct drone *drone) {
  if (drone->state == DRONE_STATE_FLYING) {
    drone->x++;
  }
}

// Flip the drone.
void drone_flip(struct drone *drone) {
  if (drone->state == DRONE_STATE_FLYING) {
    drone->speed = -drone->speed;
  }
}

// Crash the drone.
void drone_crash(struct drone *drone) {
  drone->state = DRONE_STATE_CRASHED;
}

// Print the drone's state.
void drone_print_state(struct drone *drone) {
  switch (drone->state) {
    case DRONE_STATE_IDLE:
      printf("The drone is idle.\n");
      break;
    case DRONE_STATE_TAKEOFF:
      printf("The drone is taking off.\n");
      break;
    case DRONE_STATE_FLYING:
      printf("The drone is flying.\n");
      break;
    case DRONE_STATE_LANDING:
      printf("The drone is landing.\n");
      break;
    case DRONE_STATE_CRASHED:
      printf("The drone has crashed.\n");
      break;
  }
}

// Parse a command from a string.
enum drone_command drone_parse_command(char *command) {
  if (strcmp(command, "takeoff") == 0) {
    return DRONE_COMMAND_TAKEOFF;
  } else if (strcmp(command, "land") == 0) {
    return DRONE_COMMAND_LAND;
  } else if (strcmp(command, "up") == 0) {
    return DRONE_COMMAND_UP;
  } else if (strcmp(command, "down") == 0) {
    return DRONE_COMMAND_DOWN;
  } else if (strcmp(command, "left") == 0) {
    return DRONE_COMMAND_LEFT;
  } else if (strcmp(command, "right") == 0) {
    return DRONE_COMMAND_RIGHT;
  } else if (strcmp(command, "flip") == 0) {
    return DRONE_COMMAND_FLIP;
  } else if (strcmp(command, "crash") == 0) {
    return DRONE_COMMAND_CRASH;
  } else {
    return -1;
  }
}

// Execute a command on a drone.
void drone_execute_command(struct drone *drone, enum drone_command command) {
  switch (command) {
    case DRONE_COMMAND_TAKEOFF:
      drone_takeoff(drone);
      break;
    case DRONE_COMMAND_LAND:
      drone_land(drone);
      break;
    case DRONE_COMMAND_UP:
      drone_up(drone);
      break;
    case DRONE_COMMAND_DOWN:
      drone_down(drone);
      break;
    case DRONE_COMMAND_LEFT:
      drone_left(drone);
      break;
    case DRONE_COMMAND_RIGHT:
      drone_right(drone);
      break;
    case DRONE_COMMAND_FLIP:
      drone_flip(drone);
      break;
    case DRONE_COMMAND_CRASH:
      drone_crash(drone);
      break;
  }
}

// Get a command from the user.
enum drone_command drone_get_command() {
  char command[100];
  printf("Enter a command: ");
  scanf("%s", command);
  return drone_parse_command(command);
}

// Main function.
int main() {
  // Create a new drone.
  struct drone *drone = drone_new();

  // Loop until the drone crashes.
  while (drone->state != DRONE_STATE_CRASHED) {
    // Get a command from the user.
    enum drone_command command = drone_get_command();

    // Execute the command on the drone.
    drone_execute_command(drone, command);

    // Print the drone's state.
    drone_print_state(drone);
  }

  // Destroy the drone.
  drone_destroy(drone);

  return 0;
}