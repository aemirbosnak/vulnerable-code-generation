//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: creative
#include <stdlib.h>
#include <time.h>

int main() {
  // Create a 2D array to store the grid of cells
  int **grid = NULL;
  int rows = 10;
  int cols = 10;
  grid = (int **)malloc(rows * sizeof(int *) + rows * cols * sizeof(int));
  for (int r = 0; r < rows; r++) {
    grid[r] = (int *)malloc(cols * sizeof(int));
  }

  // Initialize the grid with random values
  srand(time(NULL));
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      grid[r][c] = rand() % 2;
    }
  }

  // Percolation simulation
  int iterations = 0;
  while (!percolation(grid, rows, cols)) {
    iterations++;
  }

  // Print the final grid
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      printf("%d ", grid[r][c]);
    }
    printf("\n");
  }

  // Free the memory
  for (int r = 0; r < rows; r++) {
    free(grid[r]);
  }
  free(grid);

  return 0;
}

int percolation(int **grid, int rows, int cols) {
  // Check if the grid is saturated
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (grid[r][c] == 0) {
        return 0;
      }
    }
  }

  // The grid is saturated
  return 1;
}