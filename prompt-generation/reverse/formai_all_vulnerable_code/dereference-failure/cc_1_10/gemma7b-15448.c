//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: shape shifting
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int main() {
  int **grid = NULL;
  int x, y, z, i, j, k;
  srand(time(NULL));

  // Allocate memory for the grid
  grid = (int **)malloc(HEIGHT * sizeof(int *));
  for (i = 0; i < HEIGHT; i++) {
    grid[i] = (int *)malloc(WIDTH * sizeof(int));
  }

  // Initialize the grid
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      grid[i][j] = 0;
    }
  }

  // Percolation simulation
  for (k = 0; k < 1000; k++) {
    // Randomly choose a cell
    x = rand() % WIDTH;
    y = rand() % HEIGHT;

    // If the cell is not already occupied and there is water above it
    if (grid[y][x] == 0 && grid[y - 1][x] == 1) {
      // Occupy the cell
      grid[y][x] = 1;

      // Spread water to the neighboring cells
      grid[y + 1][x] = 1;
      grid[y - 1][x] = 1;
      grid[y][x + 1] = 1;
      grid[y][x - 1] = 1;
    }
  }

  // Print the grid
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  // Free the memory
  for (i = 0; i < HEIGHT; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}