//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAZE_SIZE 10

// Define the maze structure
typedef struct {
  int maze[MAZE_SIZE][MAZE_SIZE];
  int start_row;
  int start_col;
  int end_row;
  int end_col;
} Maze;

// Function to create a new maze
Maze *create_maze() {
  // Allocate memory for the maze
  Maze *maze = (Maze *)malloc(sizeof(Maze));

  // Initialize the maze with walls
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      maze->maze[i][j] = 1;
    }
  }

  // Create the start and end points
  maze->start_row = 0;
  maze->start_col = 0;
  maze->end_row = MAZE_SIZE - 1;
  maze->end_col = MAZE_SIZE - 1;

  // Create some open spaces in the maze
  maze->maze[1][1] = 0;
  maze->maze[2][2] = 0;
  maze->maze[3][3] = 0;
  maze->maze[4][4] = 0;

  return maze;
}

// Function to print the maze
void print_maze(Maze *maze) {
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      printf("%d ", maze->maze[i][j]);
    }
    printf("\n");
  }
}

// Function to find a path through the maze
bool find_path(Maze *maze, int row, int col) {
  // Check if we have reached the end of the maze
  if (row == maze->end_row && col == maze->end_col) {
    return true;
  }

  // Check if the current cell is a wall
  if (maze->maze[row][col] == 1) {
    return false;
  }

  // Mark the current cell as visited
  maze->maze[row][col] = 2;

  // Try to find a path to the right
  if (find_path(maze, row, col + 1)) {
    return true;
  }

  // Try to find a path to the down
  if (find_path(maze, row + 1, col)) {
    return true;
  }

  // Try to find a path to the left
  if (find_path(maze, row, col - 1)) {
    return true;
  }

  // Try to find a path to the up
  if (find_path(maze, row - 1, col)) {
    return true;
  }

  // No path found, backtrack
  maze->maze[row][col] = 0;
  return false;
}

// Main function
int main() {
  // Create a new maze
  Maze *maze = create_maze();

  // Print the maze
  printf("Original maze:\n");
  print_maze(maze);

  // Find a path through the maze
  bool path_found = find_path(maze, maze->start_row, maze->start_col);

  // Print the maze with the path
  printf("Maze with path:\n");
  print_maze(maze);

  // Free the memory allocated for the maze
  free(maze);

  if (path_found) {
    printf("Path found!\n");
  } else {
    printf("No path found.\n");
  }

  return 0;
}