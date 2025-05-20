//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the robot's state
typedef struct {
  int x;
  int y;
  int facing; // 0 = north, 1 = east, 2 = south, 3 = west
} Robot;

// Define the environment
typedef struct {
  int width;
  int height;
  char **grid; // A 2D array of characters representing the environment
} Environment;

// Create a new robot
Robot *create_robot(int x, int y, int facing) {
  Robot *robot = malloc(sizeof(Robot));
  robot->x = x;
  robot->y = y;
  robot->facing = facing;
  return robot;
}

// Create a new environment
Environment *create_environment(int width, int height) {
  Environment *environment = malloc(sizeof(Environment));
  environment->width = width;
  environment->height = height;
  environment->grid = malloc(sizeof(char *) * height);
  for (int i = 0; i < height; i++) {
    environment->grid[i] = malloc(sizeof(char) * width);
  }
  return environment;
}

// Free the memory allocated for the robot
void free_robot(Robot *robot) {
  free(robot);
}

// Free the memory allocated for the environment
void free_environment(Environment *environment) {
  for (int i = 0; i < environment->height; i++) {
    free(environment->grid[i]);
  }
  free(environment->grid);
  free(environment);
}

// Print the robot's state
void print_robot(Robot *robot) {
  printf("Robot is at (%d, %d) facing %d\n", robot->x, robot->y, robot->facing);
}

// Print the environment
void print_environment(Environment *environment) {
  for (int i = 0; i < environment->height; i++) {
    for (int j = 0; j < environment->width; j++) {
      printf("%c", environment->grid[i][j]);
    }
    printf("\n");
  }
}

// Move the robot forward one space
void move_forward(Robot *robot, Environment *environment) {
  switch (robot->facing) {
    case 0: // North
      if (robot->y > 0) {
        robot->y--;
      }
      break;
    case 1: // East
      if (robot->x < environment->width - 1) {
        robot->x++;
      }
      break;
    case 2: // South
      if (robot->y < environment->height - 1) {
        robot->y++;
      }
      break;
    case 3: // West
      if (robot->x > 0) {
        robot->x--;
      }
      break;
  }
}

// Turn the robot left
void turn_left(Robot *robot) {
  robot->facing = (robot->facing + 3) % 4;
}

// Turn the robot right
void turn_right(Robot *robot) {
  robot->facing = (robot->facing + 1) % 4;
}

// Get a random number between 0 and max
int get_random_number(int max) {
  return rand() % max;
}

// Set a cell in the environment to a character
void set_cell(Environment *environment, int x, int y, char character) {
  environment->grid[y][x] = character;
}

// Get a character from a cell in the environment
char get_cell(Environment *environment, int x, int y) {
  return environment->grid[y][x];
}

// Check if a cell is occupied
int is_cell_occupied(Environment *environment, int x, int y) {
  return get_cell(environment, x, y) != ' ';
}

// Check if the robot is at a wall
int is_at_wall(Robot *robot, Environment *environment) {
  switch (robot->facing) {
    case 0: // North
      return robot->y == 0;
    case 1: // East
      return robot->x == environment->width - 1;
    case 2: // South
      return robot->y == environment->height - 1;
    case 3: // West
      return robot->x == 0;
  }
}

// Check if the robot is at a goal
int is_at_goal(Robot *robot, Environment *environment) {
  return get_cell(environment, robot->x, robot->y) == 'G';
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create the environment
  Environment *environment = create_environment(10, 10);

  // Set up the environment with walls and a goal
  for (int i = 0; i < environment->width; i++) {
    set_cell(environment, i, 0, '#');
    set_cell(environment, i, environment->height - 1, '#');
  }
  for (int i = 0; i < environment->height; i++) {
    set_cell(environment, 0, i, '#');
    set_cell(environment, environment->width - 1, i, '#');
  }
  set_cell(environment, 5, 5, 'G');

  // Create the robot
  Robot *robot = create_robot(1, 1, 0);

  // Print the initial state of the environment and the robot
  print_environment(environment);
  print_robot(robot);

  // Loop until the robot reaches the goal or hits a wall
  while (!is_at_goal(robot, environment) && !is_at_wall(robot, environment)) {
    // Get a random number to determine the robot's next move
    int random_number = get_random_number(4);

    // Move the robot forward, left, or right based on the random number
    switch (random_number) {
      case 0:
        move_forward(robot, environment);
        break;
      case 1:
        turn_left(robot);
        break;
      case 2:
        turn_right(robot);
        break;
    }

    // Print the new state of the environment and the robot
    print_environment(environment);
    print_robot(robot);
  }

  // Print a message indicating whether the robot reached the goal or hit a wall
  if (is_at_goal(robot, environment)) {
    printf("The robot reached the goal!\n");
  } else {
    printf("The robot hit a wall.\n");
  }

  // Free the memory allocated for the robot and the environment
  free_robot(robot);
  free_environment(environment);

  return 0;
}