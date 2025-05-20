//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Define the maze dimensions
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// Define the possible directions
typedef enum {
  UP,
  DOWN,
  LEFT,
  RIGHT
} Direction;

// Define the maze structure
typedef struct {
  int width;
  int height;
  int **maze;
} Maze;

// Create a new maze
Maze *create_maze(int width, int height) {
  Maze *maze = malloc(sizeof(Maze));
  maze->width = width;
  maze->height = height;
  maze->maze = malloc(sizeof(int *) * height);
  for (int i = 0; i < height; i++) {
    maze->maze[i] = malloc(sizeof(int) * width);
  }
  return maze;
}

// Free the memory allocated for the maze
void free_maze(Maze *maze) {
  for (int i = 0; i < maze->height; i++) {
    free(maze->maze[i]);
  }
  free(maze->maze);
  free(maze);
}

// Print the maze to the console
void print_maze(Maze *maze) {
  for (int i = 0; i < maze->height; i++) {
    for (int j = 0; j < maze->width; j++) {
      printf("%d ", maze->maze[i][j]);
    }
    printf("\n");
  }
}

// Check if the given coordinates are within the maze bounds
int is_within_bounds(Maze *maze, int x, int y) {
  return x >= 0 && x < maze->width && y >= 0 && y < maze->height;
}

// Check if the given coordinates are a valid path
int is_valid_path(Maze *maze, int x, int y) {
  return is_within_bounds(maze, x, y) && maze->maze[y][x] == 0;
}

// Find a path through the maze using a recursive backtracking algorithm
int find_path(Maze *maze, int x, int y, int **visited) {
  // Mark the current cell as visited
  visited[y][x] = 1;

  // Check if the current cell is the exit
  if (x == maze->width - 1 && y == maze->height - 1) {
    return 1;
  }

  // Try all possible directions
  for (Direction direction = UP; direction <= RIGHT; direction++) {
    int new_x = x;
    int new_y = y;

    switch (direction) {
      case UP:
        new_y--;
        break;
      case DOWN:
        new_y++;
        break;
      case LEFT:
        new_x--;
        break;
      case RIGHT:
        new_x++;
        break;
    }

    // Check if the new coordinates are a valid path
    if (is_valid_path(maze, new_x, new_y) && !visited[new_y][new_x]) {
      // Recursively call the find_path function with the new coordinates
      if (find_path(maze, new_x, new_y, visited)) {
        return 1;
      }
    }
  }

  // No path was found, so unmark the current cell as visited
  visited[y][x] = 0;
  return 0;
}

// Find a path through the maze and print the solution to the console
void solve_maze(Maze *maze) {
  // Create a visited array to keep track of which cells have been visited
  int **visited = malloc(sizeof(int *) * maze->height);
  for (int i = 0; i < maze->height; i++) {
    visited[i] = malloc(sizeof(int) * maze->width);
    for (int j = 0; j < maze->width; j++) {
      visited[i][j] = 0;
    }
  }

  // Find a path through the maze
  int found_path = find_path(maze, 0, 0, visited);

  // Print the solution to the console
  if (found_path) {
    printf("Solution found:\n");
    for (int i = 0; i < maze->height; i++) {
      for (int j = 0; j < maze->width; j++) {
        if (visited[i][j]) {
          printf("1 ");
        } else {
          printf("0 ");
        }
      }
      printf("\n");
    }
  } else {
    printf("No solution found.\n");
  }

  // Free the memory allocated for the visited array
  for (int i = 0; i < maze->height; i++) {
    free(visited[i]);
  }
  free(visited);
}

// Main function
int main() {
  // Create a new maze
  Maze *maze = create_maze(MAZE_WIDTH, MAZE_HEIGHT);

  // Set the maze values
  for (int i = 0; i < maze->height; i++) {
    for (int j = 0; j < maze->width; j++) {
      maze->maze[i][j] = rand() % 2;
    }
  }

  // Print the maze to the console
  printf("Maze:\n");
  print_maze(maze);

  // Solve the maze
  solve_maze(maze);

  // Free the memory allocated for the maze
  free_maze(maze);

  return 0;
}