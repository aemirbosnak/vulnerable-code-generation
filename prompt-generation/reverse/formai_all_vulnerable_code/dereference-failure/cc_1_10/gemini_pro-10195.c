//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Robot's dimensions
#define WIDTH 10
#define HEIGHT 10

// Arena's dimensions
#define ARENA_WIDTH 100
#define ARENA_HEIGHT 100

// Robot's movement directions
typedef enum {
  UP,
  DOWN,
  LEFT,
  RIGHT
} Direction;

// Robot data structure
typedef struct {
  int x;
  int y;
  Direction direction;
} Robot;

// Arena data structure
typedef struct {
  int width;
  int height;
} Arena;

// Function to create a new robot
Robot *robot_new(int x, int y, Direction direction) {
  Robot *robot = malloc(sizeof(Robot));
  robot->x = x;
  robot->y = y;
  robot->direction = direction;
  return robot;
}

// Function to free a robot
void robot_free(Robot *robot) {
  free(robot);
}

// Function to create a new arena
Arena *arena_new(int width, int height) {
  Arena *arena = malloc(sizeof(Arena));
  arena->width = width;
  arena->height = height;
  return arena;
}

// Function to free an arena
void arena_free(Arena *arena) {
  free(arena);
}

// Function to move the robot one step forward in the specified direction
void robot_move(Robot *robot, Arena *arena) {
  switch (robot->direction) {
    case UP:
      if (robot->y < arena->height - 1) {
        robot->y++;
      }
      break;
    case DOWN:
      if (robot->y > 0) {
        robot->y--;
      }
      break;
    case LEFT:
      if (robot->x > 0) {
        robot->x--;
      }
      break;
    case RIGHT:
      if (robot->x < arena->width - 1) {
        robot->x++;
      }
      break;
  }
}

// Function to turn the robot left or right by 90 degrees
void robot_turn(Robot *robot, int direction) {
  switch (robot->direction) {
    case UP:
      if (direction == LEFT) {
        robot->direction = LEFT;
      } else if (direction == RIGHT) {
        robot->direction = RIGHT;
      }
      break;
    case DOWN:
      if (direction == LEFT) {
        robot->direction = RIGHT;
      } else if (direction == RIGHT) {
        robot->direction = LEFT;
      }
      break;
    case LEFT:
      if (direction == LEFT) {
        robot->direction = DOWN;
      } else if (direction == RIGHT) {
        robot->direction = UP;
      }
      break;
    case RIGHT:
      if (direction == LEFT) {
        robot->direction = UP;
      } else if (direction == RIGHT) {
        robot->direction = DOWN;
      }
      break;
  }
}

// Function to print the robot's position and direction
void robot_print(Robot *robot) {
  printf("Robot is at (%d, %d) facing ", robot->x, robot->y);
  switch (robot->direction) {
    case UP:
      printf("up\n");
      break;
    case DOWN:
      printf("down\n");
      break;
    case LEFT:
      printf("left\n");
      break;
    case RIGHT:
      printf("right\n");
      break;
  }
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create a new robot and arena
  Robot *robot = robot_new(0, 0, UP);
  Arena *arena = arena_new(ARENA_WIDTH, ARENA_HEIGHT);

  // Move the robot around the arena for 100 steps
  for (int i = 0; i < 100; i++) {
    // Get a random direction
    int direction = rand() % 4;

    // Move the robot in the random direction
    robot_move(robot, arena);

    // Turn the robot left or right by 90 degrees
    robot_turn(robot, rand() % 2);

    // Print the robot's position and direction
    robot_print(robot);
  }

  // Free the robot and arena
  robot_free(robot);
  arena_free(arena);

  return 0;
}