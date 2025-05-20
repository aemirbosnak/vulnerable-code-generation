//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: mind-bending
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the robot's state
typedef struct {
  int x, y; // Position
  int angle; // Angle in degrees
} RobotState;

// Define the world
typedef struct {
  int width, height; // Dimensions
  char **grid;      // Grid of characters
} World;

// Create a new robot state
RobotState *new_robot_state(int x, int y, int angle) {
  RobotState *state = malloc(sizeof(RobotState));
  state->x = x;
  state->y = y;
  state->angle = angle;
  return state;
}

// Create a new world
World *new_world(int width, int height) {
  World *world = malloc(sizeof(World));
  world->width = width;
  world->height = height;
  world->grid = malloc(sizeof(char *) * height);
  for (int i = 0; i < height; i++) {
    world->grid[i] = malloc(sizeof(char) * width);
  }
  return world;
}

// Free the robot state
void free_robot_state(RobotState *state) { free(state); }

// Free the world
void free_world(World *world) {
  for (int i = 0; i < world->height; i++) { free(world->grid[i]); }
  free(world->grid);
  free(world);
}

// Print the world
void print_world(World *world) {
  for (int i = 0; i < world->height; i++) {
    for (int j = 0; j < world->width; j++) {
      printf("%c", world->grid[i][j]);
    }
    printf("\n");
  }
}

// Move the robot forward
void move_forward(RobotState *state, World *world) {
  int dx = 0, dy = 0;
  switch (state->angle) {
  case 0: // North
    dy = -1;
    break;
  case 90: // East
    dx = 1;
    break;
  case 180: // South
    dy = 1;
    break;
  case 270: // West
    dx = -1;
    break;
  }
  if (state->x + dx >= 0 && state->x + dx < world->width &&
      state->y + dy >= 0 && state->y + dy < world->height) {
    state->x += dx;
    state->y += dy;
  }
}

// Turn the robot left
void turn_left(RobotState *state) { state->angle = (state->angle + 90) % 360; }

// Turn the robot right
void turn_right(RobotState *state) { state->angle = (state->angle - 90) % 360; }

// Main function
int main() {
  srand(time(NULL));

  // Create a new world
  World *world = new_world(10, 10);

  // Create a new robot state
  RobotState *state = new_robot_state(5, 5, 0);

  // Run the simulation
  for (int i = 0; i < 1000; i++) {
    // Move the robot forward
    move_forward(state, world);

    // Turn the robot left or right
    if (rand() % 2 == 0) {
      turn_left(state);
    } else {
      turn_right(state);
    }

    // Print the world
    print_world(world);

    // Sleep for a short period of time
    usleep(100000);
  }

  // Free the robot state and the world
  free_robot_state(state);
  free_world(world);

  return 0;
}