//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: cheerful
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 50

int main() {
  // Initialize the grid
  int **grid = (int **)malloc(MAX_WIDTH * sizeof(int *));
  for (int i = 0; i < MAX_WIDTH; i++) {
    grid[i] = (int *)malloc(MAX_HEIGHT * sizeof(int));
  }

  // Seed the random number generator
  srand(time(NULL));

  // Percolation simulation
  for (int t = 0; t < 1000; t++) {
    for (int x = 0; x < MAX_WIDTH; x++) {
      for (int y = 0; y < MAX_HEIGHT; y++) {
        // Randomly decide whether to open the cell
        if (rand() % 2 == 0) {
          grid[x][y] = 1;
        } else {
          grid[x][y] = 0;
        }
      }
    }

    // Check if the top row is wet
    int is_wet = 0;
    for (int x = 0; x < MAX_WIDTH; x++) {
      if (grid[x][0] == 1) {
        is_wet = 1;
      }
    }

    // If the top row is wet, print "Wet!"
    if (is_wet) {
      printf("Wet!\n");
    } else {
      printf("Dry.\n");
    }
  }

  // Free the memory
  for (int i = 0; i < MAX_WIDTH; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}