//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the maze structure
typedef struct {
  int width;
  int height;
  int **maze;
} Maze;

// Function to create a new maze
Maze *create_maze(int width, int height) {
  Maze *maze = (Maze *)malloc(sizeof(Maze));
  maze->width = width;
  maze->height = height;

  // Allocate memory for the maze data
  maze->maze = (int **)malloc(sizeof(int *) * height);
  for (int i = 0; i < height; i++) {
    maze->maze[i] = (int *)malloc(sizeof(int) * width);
  }

  // Initialize the maze data to 0 (indicating no walls)
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      maze->maze[i][j] = 0;
    }
  }

  return maze;
}

// Function to print the maze
void print_maze(Maze *maze) {
  for (int i = 0; i < maze->height; i++) {
    for (int j = 0; j < maze->width; j++) {
      printf("%d ", maze->maze[i][j]);
    }
    printf("\n");
  }
}

// Function to find a path through the maze using recursion
int find_path(Maze *maze, int x, int y) {
  // Check if we have reached the end of the maze
  if (x == maze->width - 1 && y == maze->height - 1) {
    return 1;
  }

  // Check if the current cell is a wall
  if (maze->maze[y][x] == 1) {
    return 0;
  }

  // Try all possible moves from the current cell
  int found_path = 0;
  if (x + 1 < maze->width) {
    found_path = find_path(maze, x + 1, y);
  }
  if (!found_path && y + 1 < maze->height) {
    found_path = find_path(maze, x, y + 1);
  }
  if (!found_path && x - 1 >= 0) {
    found_path = find_path(maze, x - 1, y);
  }
  if (!found_path && y - 1 >= 0) {
    found_path = find_path(maze, x, y - 1);
  }

  // If a path was found, mark the current cell as part of the path
  if (found_path) {
    maze->maze[y][x] = 2;
  }

  return found_path;
}

// Function to solve the maze
int solve_maze(Maze *maze) {
  // Find the starting cell
  int x = 0, y = 0;
  for (int i = 0; i < maze->height; i++) {
    for (int j = 0; j < maze->width; j++) {
      if (maze->maze[i][j] == 0) {
        x = j;
        y = i;
        break;
      }
    }
  }

  // Try to find a path through the maze
  int found_path = find_path(maze, x, y);

  // Print the maze with the path marked
  print_maze(maze);

  return found_path;
}

// Function to free the memory allocated for the maze
void free_maze(Maze *maze) {
  for (int i = 0; i < maze->height; i++) {
    free(maze->maze[i]);
  }
  free(maze->maze);
  free(maze);
}

int main() {
  // Create a new maze
  Maze *maze = create_maze(10, 10);

  // Set some walls in the maze
  maze->maze[0][1] = 1;
  maze->maze[2][2] = 1;
  maze->maze[3][3] = 1;
  maze->maze[4][4] = 1;

  // Print the maze
  printf("Original Maze:\n");
  print_maze(maze);

  // Solve the maze
  int found_path = solve_maze(maze);

  // Free the memory allocated for the maze
  free_maze(maze);

  return 0;
}