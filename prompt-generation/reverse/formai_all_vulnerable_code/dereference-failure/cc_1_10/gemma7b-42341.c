//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: modular
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Define the Percolation Simulation module
void percol_sim(int n, int p) {
  // Allocate memory for the grid
  int **grid = malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    grid[i] = malloc(n * sizeof(int));
  }

  // Initialize the grid
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      grid[i][j] = 0;
    }
  }

  // Simulate the percolation process
  for (int t = 0; t < 1000; t++) {
    // Randomly select a site
    int x = rand() % n;
    int y = rand() % n;

    // If the site is not occupied and there is a chance of occupation
    if (grid[x][y] == 0 && rand() % p == 0) {
      // Occupy the site
      grid[x][y] = 1;
    }
  }

  // Print the grid
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  // Free memory
  for (int i = 0; i < n; i++) {
    free(grid[i]);
  }
  free(grid);
}

int main() {
  // Simulate the percol_sim module
  percol_sim(5, 50);

  return 0;
}