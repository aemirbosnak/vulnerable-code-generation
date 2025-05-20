//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid dimensions
#define WIDTH 20
#define HEIGHT 20

// Probability of a cell being open
#define P 0.5

// Cell states
#define OPEN 1
#define CLOSED 0

// Function to generate a random grid
int** generate_grid(int width, int height, float p) {
  int** grid = malloc(height * sizeof(int*));
  for (int i = 0; i < height; i++) {
    grid[i] = malloc(width * sizeof(int));
    for (int j = 0; j < width; j++) {
      grid[i][j] = (rand() / (RAND_MAX + 1.0)) < p ? OPEN : CLOSED;
    }
  }
  return grid;
}

// Function to print the grid
void print_grid(int** grid, int width, int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a cell is open
int is_open(int** grid, int x, int y) {
  return grid[y][x] == OPEN;
}

// Function to check if a cell is closed
int is_closed(int** grid, int x, int y) {
  return grid[y][x] == CLOSED;
}

// Function to check if a cell is on the left edge of the grid
int is_left_edge(int x) {
  return x == 0;
}

// Function to check if a cell is on the right edge of the grid
int is_right_edge(int x, int width) {
  return x == width - 1;
}

// Function to check if a cell is on the top edge of the grid
int is_top_edge(int y) {
  return y == 0;
}

// Function to check if a cell is on the bottom edge of the grid
int is_bottom_edge(int y, int height) {
  return y == height - 1;
}

// Function to check if a cell is percolating
int is_percolating(int** grid, int width, int height) {
  // Check if any cell on the top edge is open
  for (int i = 0; i < width; i++) {
    if (is_open(grid, i, 0)) {
      return 1;
    }
  }

  // Check if any cell on the bottom edge is open
  for (int i = 0; i < width; i++) {
    if (is_open(grid, i, height - 1)) {
      return 1;
    }
  }

  return 0;
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random grid
  int** grid = generate_grid(WIDTH, HEIGHT, P);

  // Print the grid
  print_grid(grid, WIDTH, HEIGHT);

  // Check if the grid is percolating
  int percolating = is_percolating(grid, WIDTH, HEIGHT);

  // Print the result
  printf("The grid is %s percolating.\n", percolating ? "" : "not");

  // Free the grid
  for (int i = 0; i < HEIGHT; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}