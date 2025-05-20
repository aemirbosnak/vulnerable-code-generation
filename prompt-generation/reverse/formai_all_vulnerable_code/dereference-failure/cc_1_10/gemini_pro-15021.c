//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cyberpunk maze generation algorithm
void generate_maze(int width, int height, char **maze) {
  // Initialize the maze with walls
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      maze[i][j] = '#';
    }
  }

  // Create a stack to store the cells to be visited
  int stack[width * height];
  int stack_size = 0;

  // Start at a random cell
  int x = rand() % width;
  int y = rand() % height;

  // Mark the starting cell as visited
  maze[y][x] = '.';

  // Push the starting cell onto the stack
  stack[stack_size++] = y * width + x;

  // While the stack is not empty
  while (stack_size > 0) {
    // Pop the top cell from the stack
    int cell = stack[--stack_size];

    // Convert the cell index to x and y coordinates
    x = cell % width;
    y = cell / width;

    // Get a list of the unvisited neighbors of the current cell
    int neighbors[4];
    int num_neighbors = 0;
    if (x > 0 && maze[y][x - 1] == '#') {
      neighbors[num_neighbors++] = y * width + x - 1;
    }
    if (y > 0 && maze[y - 1][x] == '#') {
      neighbors[num_neighbors++] = (y - 1) * width + x;
    }
    if (x < width - 1 && maze[y][x + 1] == '#') {
      neighbors[num_neighbors++] = y * width + x + 1;
    }
    if (y < height - 1 && maze[y + 1][x] == '#') {
      neighbors[num_neighbors++] = (y + 1) * width + x;
    }

    // If there are no unvisited neighbors, continue
    if (num_neighbors == 0) {
      continue;
    }

    // Choose a random unvisited neighbor
    int neighbor = neighbors[rand() % num_neighbors];

    // Mark the neighbor as visited
    maze[neighbor / width][neighbor % width] = '.';

    // Push the neighbor onto the stack
    stack[stack_size++] = neighbor;
  }
}

// Print the maze
void print_maze(int width, int height, char **maze) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Set the seed for the random number generator
  srand(time(NULL));

  // Define the width and height of the maze
  int width = 100;
  int height = 100;

  // Allocate memory for the maze
  char **maze = malloc(height * sizeof(char *));
  for (int i = 0; i < height; i++) {
    maze[i] = malloc(width * sizeof(char));
  }

  // Generate the maze
  generate_maze(width, height, maze);

  // Print the maze
  print_maze(width, height, maze);

  // Free the memory allocated for the maze
  for (int i = 0; i < height; i++) {
    free(maze[i]);
  }
  free(maze);

  return 0;
}