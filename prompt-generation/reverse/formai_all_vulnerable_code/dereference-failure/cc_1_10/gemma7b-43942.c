//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: scientific
#include <stdlib.h>
#include <stdio.h>

// Percolation Simulation Parameters
#define NUM_ROWS 20
#define NUM_COLS 20
#define MAX_ITERATIONS 1000

// Define the Percolation Function
void percolate(int **grid, int row, int col) {
  // If the cell is not already wet and the row and column are within bounds
  if (grid[row][col] == 0 && row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS) {
    // Make the cell wet
    grid[row][col] = 1;

    // Percolate to the north
    percolate(grid, row - 1, col);

    // Percolate to the south
    percolate(grid, row + 1, col);

    // Percolate to the east
    percolate(grid, row, col + 1);

    // Percolate to the west
    percolate(grid, row, col - 1);
  }
}

int main() {
  // Allocate memory for the grid
  int **grid = (int **)malloc(NUM_ROWS * sizeof(int *));
  for (int r = 0; r < NUM_ROWS; r++) {
    grid[r] = (int *)malloc(NUM_COLS * sizeof(int));
  }

  // Initialize the grid
  for (int r = 0; r < NUM_ROWS; r++) {
    for (int c = 0; c < NUM_COLS; c++) {
      grid[r][c] = 0;
    }
  }

  // Percolation simulation
  percolate(grid, 0, 0);

  // Print the wet cells
  for (int r = 0; r < NUM_ROWS; r++) {
    for (int c = 0; c < NUM_COLS; c++) {
      if (grid[r][c] == 1) {
        printf("%d ", grid[r][c]);
      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }

  // Free the memory
  for (int r = 0; r < NUM_ROWS; r++) {
    free(grid[r]);
  }
  free(grid);

  return 0;
}