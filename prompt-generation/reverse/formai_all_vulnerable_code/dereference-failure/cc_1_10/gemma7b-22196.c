//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: rigorous
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 50

int main() {
  int **grid = NULL;
  int x, y, w, h, seed;

  // Allocate memory for the grid
  grid = malloc(MAX_WIDTH * MAX_HEIGHT * sizeof(int));
  if (grid == NULL) {
    return 1;
  }

  // Initialize the grid
  for (x = 0; x < MAX_WIDTH; x++) {
    for (y = 0; y < MAX_HEIGHT; y++) {
      grid[x][y] = 0;
    }
  }

  // Set the seed for the random number generator
  srand(time(NULL));

  // Percolation simulation
  for (w = 0; w < MAX_WIDTH; w++) {
    for (h = 0; h < MAX_HEIGHT; h++) {
      if (grid[w][h] == 0) {
        // Randomly decide whether to fill the cell
        if (rand() % 2 == 0) {
          grid[w][h] = 1;
        }
      }
    }
  }

  // Print the grid
  for (x = 0; x < MAX_WIDTH; x++) {
    for (y = 0; y < MAX_HEIGHT; y++) {
      printf("%d ", grid[x][y]);
    }
    printf("\n");
  }

  // Free the memory allocated for the grid
  free(grid);

  return 0;
}