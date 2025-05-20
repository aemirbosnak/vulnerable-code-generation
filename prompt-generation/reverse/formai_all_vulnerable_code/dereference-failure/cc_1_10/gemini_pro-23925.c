//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: all-encompassing
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Define the size of the maze
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// Define the possible directions
enum direction {
  NORTH,
  EAST,
  SOUTH,
  WEST
};

// Define the structure of a cell
typedef struct cell {
  int x;
  int y;
  int walls;
} cell;

// Create a new maze
cell** create_maze() {
  // Allocate memory for the maze
  cell** maze = malloc(sizeof(cell*) * MAZE_HEIGHT);
  for (int i = 0; i < MAZE_HEIGHT; i++) {
    maze[i] = malloc(sizeof(cell) * MAZE_WIDTH);
  }

  // Initialize the maze
  for (int i = 0; i < MAZE_HEIGHT; i++) {
    for (int j = 0; j < MAZE_WIDTH; j++) {
      maze[i][j].x = j;
      maze[i][j].y = i;
      maze[i][j].walls = 0xF;
    }
  }

  // Create the maze
  srand(time(NULL));
  for (int i = 0; i < MAZE_HEIGHT; i++) {
    for (int j = 0; j < MAZE_WIDTH; j++) {
      // Get a random direction
      enum direction direction = rand() % 4;

      // Break down the wall in the given direction
      switch (direction) {
        case NORTH:
          maze[i][j].walls &= ~0x1;
          maze[i - 1][j].walls &= ~0x8;
          break;
        case EAST:
          maze[i][j].walls &= ~0x2;
          maze[i][j + 1].walls &= ~0x4;
          break;
        case SOUTH:
          maze[i][j].walls &= ~0x8;
          maze[i + 1][j].walls &= ~0x1;
          break;
        case WEST:
          maze[i][j].walls &= ~0x4;
          maze[i][j - 1].walls &= ~0x2;
          break;
      }
    }
  }

  // Return the maze
  return maze;
}

// Print the maze
void print_maze(cell** maze) {
  // Print the top border
  for (int i = 0; i < MAZE_WIDTH; i++) {
    printf("+---");
  }
  printf("+\n");

  // Print the maze
  for (int i = 0; i < MAZE_HEIGHT; i++) {
    // Print the left border
    printf("|");

    // Print the cells
    for (int j = 0; j < MAZE_WIDTH; j++) {
      // Print the top wall
      if (maze[i][j].walls & 0x1) {
        printf("   ");
      } else {
        printf(" _ ");
      }

      // Print the right wall
      if (maze[i][j].walls & 0x2) {
        printf("|");
      } else {
        printf(" ");
      }
    }

    // Print the right border
    printf("|\n");

    // Print the bottom wall
    for (int j = 0; j < MAZE_WIDTH; j++) {
      if (maze[i][j].walls & 0x8) {
        printf("+---+");
      } else {
        printf("+   +");
      }
    }
    printf("+\n");
  }
}

// Free the memory allocated for the maze
void free_maze(cell** maze) {
  for (int i = 0; i < MAZE_HEIGHT; i++) {
    free(maze[i]);
  }
  free(maze);
}

// Main function
int main() {
  // Create the maze
  cell** maze = create_maze();

  // Print the maze
  print_maze(maze);

  // Free the memory allocated for the maze
  free_maze(maze);

  return 0;
}