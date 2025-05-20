//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: Cryptic
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

// Percolation status
#define PERCOLATES 1
#define DOES_NOT_PERCOLATE 0

// Function to generate a random grid
int **generate_grid(int width, int height) {
  int **grid = malloc(height * sizeof(int *));
  for (int i = 0; i < height; i++) {
    grid[i] = malloc(width * sizeof(int));
    for (int j = 0; j < width; j++) {
      grid[i][j] = (rand() < RAND_MAX * P) ? OPEN : CLOSED;
    }
  }
  return grid;
}

// Function to print the grid
void print_grid(int **grid, int width, int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", grid[i][j] ? 'O' : 'X');
    }
    printf("\n");
  }
}

// Function to check if a cell is open
int is_open(int **grid, int x, int y, int width, int height) {
  return (x >= 0 && x < width && y >= 0 && y < height && grid[y][x] == OPEN);
}

// Function to check if the grid percolates
int does_percolate(int **grid, int width, int height) {
  // Check if the top row has any open cells
  for (int i = 0; i < width; i++) {
    if (is_open(grid, i, 0, width, height)) {
      // Recursively check if there is a path to the bottom row
      if (check_path(grid, i, 0, width, height)) {
        return PERCOLATES;
      }
    }
  }
  return DOES_NOT_PERCOLATE;
}

// Function to check if there is a path to the bottom row
int check_path(int **grid, int x, int y, int width, int height) {
  // Check if we have reached the bottom row
  if (y == height - 1) {
    return 1;
  }

  // Check if the current cell is open
  if (!is_open(grid, x, y, width, height)) {
    return 0;
  }

  // Recursively check the neighbors of the current cell
  return check_path(grid, x + 1, y, width, height) || check_path(grid, x - 1, y, width, height) || check_path(grid, x, y + 1, width, height);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random grid
  int **grid = generate_grid(WIDTH, HEIGHT);

  // Print the grid
  print_grid(grid, WIDTH, HEIGHT);

  // Check if the grid percolates
  int percolates = does_percolate(grid, WIDTH, HEIGHT);

  // Print the result
  printf("Percolates: %s\n", percolates ? "yes" : "no");

  // Free the grid
  for (int i = 0; i < HEIGHT; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}