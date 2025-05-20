//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: light-weight
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

int main() {
  int **grid = NULL;
  int x, y;
  int seed;
  time_t t;

  // Allocate memory for the grid
  grid = (int**)malloc(HEIGHT * sizeof(int*));
  for (y = 0; y < HEIGHT; y++) {
    grid[y] = (int*)malloc(WIDTH * sizeof(int));
  }

  // Seed the random number generator
  seed = time(NULL);
  srand(seed);

  // Percolation simulation
  for (t = 0; t < 1000; t++) {
    // Randomly select two cells
    x = rand() % WIDTH;
    y = rand() % HEIGHT;

    // If both cells are wet, make them dry
    if (grid[y][x] == 1) {
      grid[y][x] = 0;
    }
  }

  // Print the grid
  for (y = 0; y < HEIGHT; y++) {
    for (x = 0; x < WIDTH; x++) {
      printf("%d ", grid[y][x]);
    }
    printf("\n");
  }

  // Free memory
  for (y = 0; y < HEIGHT; y++) {
    free(grid[y]);
  }
  free(grid);

  return 0;
}