//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 512
#define HEIGHT 512

int main() {
  int **grid = NULL;
  int x, y;

  // Allocate memory for the grid
  grid = malloc(WIDTH * sizeof(int *) * HEIGHT);
  for (x = 0; x < WIDTH; x++) {
    grid[x] = malloc(HEIGHT * sizeof(int));
  }

  // Initialize the grid
  for (x = 0; x < WIDTH; x++) {
    for (y = 0; y < HEIGHT; y++) {
      grid[x][y] = 0;
    }
  }

  // Seed the random number generator
  srand(time(NULL));

  // Simulate percolation
  for (x = 0; x < WIDTH; x++) {
    for (y = 0; y < HEIGHT; y++) {
      if (rand() % 2 == 0) {
        grid[x][y] = 1;
      }
    }
  }

  // Print the grid
  for (x = 0; x < WIDTH; x++) {
    for (y = 0; y < HEIGHT; y++) {
      printf("%d ", grid[x][y]);
    }
    printf("\n");
  }

  // Free the memory
  for (x = 0; x < WIDTH; x++) {
    free(grid[x]);
  }
  free(grid);

  return 0;
}