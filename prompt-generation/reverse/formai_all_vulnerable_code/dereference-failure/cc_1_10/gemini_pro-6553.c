//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define the size of the maze
#define MAZE_SIZE 10

// Define the possible directions
typedef enum {
  NORTH,
  EAST,
  SOUTH,
  WEST
} Direction;

// Define the maze structure
typedef struct {
  int maze[MAZE_SIZE][MAZE_SIZE];
  int start_row;
  int start_col;
  int end_row;
  int end_col;
} Maze;

// Create a new maze
Maze* create_maze() {
  Maze* maze = malloc(sizeof(Maze));
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      maze->maze[i][j] = 0;
    }
  }
  maze->start_row = 0;
  maze->start_col = 0;
  maze->end_row = MAZE_SIZE - 1;
  maze->end_col = MAZE_SIZE - 1;
  return maze;
}

// Print the maze
void print_maze(Maze* maze) {
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      printf("%d ", maze->maze[i][j]);
    }
    printf("\n");
  }
}

// Solve the maze using a recursive backtracking algorithm
int solve_maze(Maze* maze, int row, int col) {
  // Check if we have reached the end of the maze
  if (row == maze->end_row && col == maze->end_col) {
    return 1;
  }

  // Mark the current cell as visited
  maze->maze[row][col] = 1;

  // Try all possible directions
  for (Direction direction = NORTH; direction <= WEST; direction++) {
    // Get the next cell in the given direction
    int next_row = row;
    int next_col = col;
    switch (direction) {
      case NORTH:
        next_row--;
        break;
      case EAST:
        next_col++;
        break;
      case SOUTH:
        next_row++;
        break;
      case WEST:
        next_col--;
        break;
    }

    // Check if the next cell is valid
    if (next_row >= 0 && next_row < MAZE_SIZE &&
        next_col >= 0 && next_col < MAZE_SIZE &&
        maze->maze[next_row][next_col] == 0) {
      // Try to solve the maze from the next cell
      if (solve_maze(maze, next_row, next_col)) {
        return 1;
      }
    }
  }

  // Unmark the current cell as visited
  maze->maze[row][col] = 0;

  // We have not found a solution from this cell
  return 0;
}

int main() {
  // Create a new maze
  Maze* maze = create_maze();

  // Print the maze
  print_maze(maze);

  // Solve the maze
  if (solve_maze(maze, maze->start_row, maze->start_col)) {
    printf("Maze solved!\n");
  } else {
    printf("No solution found.\n");
  }

  // Free the maze
  free(maze);

  return 0;
}