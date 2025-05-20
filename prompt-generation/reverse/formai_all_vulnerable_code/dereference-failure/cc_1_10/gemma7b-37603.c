//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
  int **grid;
  int width, height, iterations;
  int seed;

  // Allocate memory for the grid
  width = 10;
  height = 10;
  grid = (int **)malloc(height * sizeof(int *) + height);
  for (int i = 0; i < height; i++) {
    grid[i] = (int *)malloc(width * sizeof(int) + width);
  }

  // Initialize the grid
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      grid[i][j] = 0;
    }
  }

  // Set the seed
  seed = time(NULL);
  srand(seed);

  // Percolation
  iterations = 1000;
  for (int i = 0; i < iterations; i++) {
    int x, y;
    x = rand() % width;
    y = rand() % height;

    if (grid[y][x] == 0) {
      grid[y][x] = 1;
    }
  }

  // Print the grid
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  // Free the memory
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      free(grid[i][j]);
    }
    free(grid[i]);
  }
  free(grid);

  return 0;
}