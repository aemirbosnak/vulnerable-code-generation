//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: shape shifting
#include <stdlib.h>
#include <time.h>

// Define the maximum number of iterations
#define MAX_ITERATIONS 1000

// Define the grid size
#define GRID_SIZE 50

// Define the shape function
int shape(int x, int y) {
  return (x - y) * (x - y) / 2;
}

int main() {
  // Allocate the grid
  int **grid = (int *)malloc(GRID_SIZE * GRID_SIZE * sizeof(int));
  for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
    grid[i] = 0;
  }

  // Initialize the seed
  srand(time(NULL));

  // Percolation simulation
  for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
    // Randomly select a site
    int x = rand() % GRID_SIZE;
    int y = rand() % GRID_SIZE;

    // If the site is not occupied and the shape function returns a positive value
    if (grid[x * GRID_SIZE + y] == 0 && shape(x, y) > 0) {
      // Occupy the site
      grid[x * GRID_SIZE + y] = 1;
    }
  }

  // Print the grid
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      printf("%d ", grid[i * GRID_SIZE + j]);
    }
    printf("\n");
  }

  // Free the grid
  free(grid);

  return 0;
}