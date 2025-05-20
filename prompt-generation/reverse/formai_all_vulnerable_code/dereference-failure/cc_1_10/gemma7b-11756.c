//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: artistic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
  // Set the seed for the random number generator
  srand(time(NULL));

  // Create a 2D array to store the grid of cells
  int **grid = NULL;
  grid = malloc(10 * sizeof(int *));
  for (int i = 0; i < 10; i++) {
    grid[i] = malloc(10 * sizeof(int));
  }

  // Initialize the grid with random values
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      grid[i][j] = rand() % 2;
    }
  }

  // Percolation simulation
  int iterations = 0;
  while (!percolation(grid, 10, 10, &iterations)) {
    iterations++;
  }

  // Print the final grid
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the grid
  for (int i = 0; i < 10; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}

int percolation(int **grid, int rows, int cols, int *iterations) {
  // Check if the grid is saturated
  if (saturation(grid, rows, cols)) {
    return 1;
  }

  // Choose a random cell
  int x = rand() % rows;
  int y = rand() % cols;

  // If the cell is not occupied and the neighboring cells are occupied, occupy the cell
  if (grid[x][y] == 0 && occupation(grid, x, y, rows, cols) == 1) {
    grid[x][y] = 1;
    *iterations++;
    return 0;
  }

  return 1;
}

int saturation(int **grid, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (grid[i][j] == 0) {
        return 0;
      }
    }
  }

  return 1;
}

int occupation(int **grid, int x, int y, int rows, int cols) {
  // Check if the cell is on the border of the grid
  if (x == 0 || x == rows - 1 || y == 0 || y == cols - 1) {
    return 1;
  }

  // Check if the cell is occupied
  return grid[x][y] == 1;
}