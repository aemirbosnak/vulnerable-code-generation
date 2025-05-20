//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: light-weight
#include <stdlib.h>
#include <stdio.h>

int main() {
  // Create a 2D array to store the water levels
  int **water_levels = NULL;
  int rows, cols;
  scanf("Enter the number of rows: ", &rows);
  scanf("Enter the number of columns: ", &cols);
  water_levels = (int**)malloc(rows * sizeof(int*));
  for (int r = 0; r < rows; r++) {
    water_levels[r] = (int*)malloc(cols * sizeof(int));
  }

  // Initialize the water levels
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      water_levels[r][c] = 0;
    }
  }

  // Simulate the percolation
  int num_simulations;
  scanf("Enter the number of simulations: ", &num_simulations);
  for (int s = 0; s < num_simulations; s++) {
    // Randomly choose a row and column
    int row = rand() % rows;
    int col = rand() % cols;

    // If the water level at that position is 0, increase it by 1
    if (water_levels[row][col] == 0) {
      water_levels[row][col] = 1;
    }
  }

  // Print the water levels
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      printf("%d ", water_levels[r][c]);
    }
    printf("\n");
  }

  // Free the memory
  for (int r = 0; r < rows; r++) {
    free(water_levels[r]);
  }
  free(water_levels);

  return 0;
}