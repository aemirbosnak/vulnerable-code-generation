//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: scientific
#include <stdlib.h>
#include <stdio.h>

// Percolation Simulation

int main() {
  // Create a 2D array to store the state of the grid
  int **grid = NULL;
  int rows, cols;

  // Get the number of rows and columns from the user
  printf("Enter the number of rows: ");
  scanf("%d", &rows);

  printf("Enter the number of columns: ");
  scanf("%d", &cols);

  // Allocate memory for the grid
  grid = malloc(rows * sizeof(int *) + cols * sizeof(int));
  for (int r = 0; r < rows; r++) {
    grid[r] = malloc(cols * sizeof(int));
  }

  // Initialize the grid
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      grid[r][c] = 0;
    }
  }

  // Simulate the percolation process
  for (int t = 0; t < 1000; t++) {
    // Randomly choose a cell
    int r = rand() % rows;
    int c = rand() % cols;

    // If the cell is not already saturated and the sum of its neighbors is greater than the threshold, saturate the cell
    if (grid[r][c] == 0 && (grid[r-1][c] + grid[r+1][c] + grid[r][c-1] + grid[r][c+1] > 5)) {
      grid[r][c] = 1;
    }
  }

  // Print the final state of the grid
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      printf("%d ", grid[r][c]);
    }
    printf("\n");
  }

  // Free the memory allocated for the grid
  for (int r = 0; r < rows; r++) {
    free(grid[r]);
  }
  free(grid);

  return 0;
}