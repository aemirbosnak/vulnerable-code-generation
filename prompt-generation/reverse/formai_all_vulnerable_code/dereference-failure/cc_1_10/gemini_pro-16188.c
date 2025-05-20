//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maze dimensions
#define MAZE_WIDTH  10
#define MAZE_HEIGHT 10

// Define the possible directions
enum direction {
  NORTH,
  EAST,
  SOUTH,
  WEST
};

// Define the cell states
enum cell_state {
  WALL,
  OPEN
};

// Define the maze structure
struct maze {
  enum cell_state cells[MAZE_WIDTH][MAZE_HEIGHT];
  int start_x;
  int start_y;
  int end_x;
  int end_y;
};

// Function to generate a new maze
struct maze* generate_maze(void) {
  // Create a new maze
  struct maze* maze = malloc(sizeof(struct maze));

  // Initialize the maze cells to WALL
  for (int i = 0; i < MAZE_WIDTH; i++) {
    for (int j = 0; j < MAZE_HEIGHT; j++) {
      maze->cells[i][j] = WALL;
    }
  }

  // Set the start and end points
  maze->start_x = 0;
  maze->start_y = 0;
  maze->end_x = MAZE_WIDTH - 1;
  maze->end_y = MAZE_HEIGHT - 1;

  // Generate the maze
  int x = maze->start_x;
  int y = maze->start_y;
  while (x != maze->end_x || y != maze->end_y) {
    // Choose a random direction
    enum direction direction = rand() % 4;

    // Move in the chosen direction
    switch (direction) {
      case NORTH:
        if (y > 0 && maze->cells[x][y - 1] == WALL) {
          maze->cells[x][y - 1] = OPEN;
          y--;
        }
        break;
      case EAST:
        if (x < MAZE_WIDTH - 1 && maze->cells[x + 1][y] == WALL) {
          maze->cells[x + 1][y] = OPEN;
          x++;
        }
        break;
      case SOUTH:
        if (y < MAZE_HEIGHT - 1 && maze->cells[x][y + 1] == WALL) {
          maze->cells[x][y + 1] = OPEN;
          y++;
        }
        break;
      case WEST:
        if (x > 0 && maze->cells[x - 1][y] == WALL) {
          maze->cells[x - 1][y] = OPEN;
          x--;
        }
        break;
    }
  }

  // Return the maze
  return maze;
}

// Function to print the maze
void print_maze(struct maze* maze) {
  // Print the top border
  for (int i = 0; i < MAZE_WIDTH * 2 + 1; i++) {
    printf("#");
  }
  printf("\n");

  // Print the maze cells
  for (int i = 0; i < MAZE_HEIGHT; i++) {
    // Print the left border
    printf("#");

    // Print the maze cells
    for (int j = 0; j < MAZE_WIDTH; j++) {
      if (maze->cells[j][i] == WALL) {
        printf("##");
      } else {
        printf("  ");
      }
    }

    // Print the right border
    printf("#\n");
  }

  // Print the bottom border
  for (int i = 0; i < MAZE_WIDTH * 2 + 1; i++) {
    printf("#");
  }
  printf("\n");
}

// Function to solve the maze
int solve_maze(struct maze* maze) {
  // Create a stack to store the visited cells
  int stack_size = MAZE_WIDTH * MAZE_HEIGHT;
  int* stack = malloc(stack_size * sizeof(int));
  int top = -1;

  // Push the start cell onto the stack
  stack[++top] = maze->start_x + maze->start_y * MAZE_WIDTH;

  // While the stack is not empty
  while (top != -1) {
    // Pop the top cell from the stack
    int cell = stack[top--];

    // Get the x and y coordinates of the cell
    int x = cell % MAZE_WIDTH;
    int y = cell / MAZE_WIDTH;

    // If the cell is the end cell, return true
    if (x == maze->end_x && y == maze->end_y) {
      free(stack);
      return 1;
    }

    // If the cell is not a wall, mark it as visited and push its neighbors onto the stack
    if (maze->cells[x][y] == OPEN) {
      maze->cells[x][y] = WALL;

      // Push the north neighbor onto the stack
      if (y > 0 && maze->cells[x][y - 1] == OPEN) {
        stack[++top] = x + (y - 1) * MAZE_WIDTH;
      }

      // Push the east neighbor onto the stack
      if (x < MAZE_WIDTH - 1 && maze->cells[x + 1][y] == OPEN) {
        stack[++top] = x + 1 + y * MAZE_WIDTH;
      }

      // Push the south neighbor onto the stack
      if (y < MAZE_HEIGHT - 1 && maze->cells[x][y + 1] == OPEN) {
        stack[++top] = x + (y + 1) * MAZE_WIDTH;
      }

      // Push the west neighbor onto the stack
      if (x > 0 && maze->cells[x - 1][y] == OPEN) {
        stack[++top] = x - 1 + y * MAZE_WIDTH;
      }
    }
  }

  // Free the stack
  free(stack);

  // Return false if the maze is not solvable
  return 0;
}

// Main function
int main(void) {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a new maze
  struct maze* maze = generate_maze();

  // Print the maze
  print_maze(maze);

  // Solve the maze
  int solved = solve_maze(maze);

  // Print the solution
  if (solved) {
    printf("The maze has been solved!\n");
  } else {
    printf("The maze is not solvable.\n");
  }

  // Free the maze
  free(maze);

  // Return 0
  return 0;
}