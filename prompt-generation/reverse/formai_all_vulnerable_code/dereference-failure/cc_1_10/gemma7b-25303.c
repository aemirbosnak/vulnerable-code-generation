//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: active
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIM_SIZE 20

int main() {
  int sim_size, num_percolations, **grid, x, y, z, seed;

  // Allocate memory for the grid
  grid = (int **)malloc(MAX_SIM_SIZE * sizeof(int *));
  for (x = 0; x < MAX_SIM_SIZE; x++) {
    grid[x] = (int *)malloc(MAX_SIM_SIZE * sizeof(int));
  }

  // Initialize the grid
  for (x = 0; x < MAX_SIM_SIZE; x++) {
    for (y = 0; y < MAX_SIM_SIZE; y++) {
      grid[x][y] = 0;
    }
  }

  // Set the seed for the random number generator
  seed = time(NULL);
  srand(seed);

  // Simulate a number of percolations
  num_percolations = 10;
  for (z = 0; z < num_percolations; z++) {
    // Generate a random location for the percolating water
    x = rand() % MAX_SIM_SIZE;
    y = rand() % MAX_SIM_SIZE;

    // If the location is empty, set it to wet
    if (grid[x][y] == 0) {
      grid[x][y] = 1;
    }
  }

  // Print the grid
  for (x = 0; x < MAX_SIM_SIZE; x++) {
    for (y = 0; y < MAX_SIM_SIZE; y++) {
      printf("%d ", grid[x][y]);
    }
    printf("\n");
  }

  // Free the memory allocated for the grid
  for (x = 0; x < MAX_SIM_SIZE; x++) {
    free(grid[x]);
  }
  free(grid);

  return 0;
}