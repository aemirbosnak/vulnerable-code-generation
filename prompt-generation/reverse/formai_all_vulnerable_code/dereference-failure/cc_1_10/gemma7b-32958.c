//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: invasive
#include <stdlib.h>
#include <time.h>

#define MAX_ITERATIONS 1000

// Define a 2D array
int **grid;

// Define the percolation function
void percolate(int x, int y) {
  // If the cell is not occupied or has already percolated, return
  if (grid[x][y] == 0 || grid[x][y] == 2) {
    return;
  }

  // Occupy the cell
  grid[x][y] = 2;

  // Percolate vertically
  percolate(x, y - 1);

  // Percolate horizontally
  percolate(x - 1, y);
}

int main() {
  // Allocate memory for the grid
  grid = (int**)malloc(10 * sizeof(int*));
  for (int i = 0; i < 10; i++) {
    grid[i] = (int*)malloc(10 * sizeof(int));
  }

  // Initialize the grid
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      grid[i][j] = 0;
    }
  }

  // Randomly occupy some cells
  srand(time(NULL));
  for (int i = 0; i < 100; i++) {
    grid[rand() % 10][rand() % 10] = 1;
  }

  // Percolate the cells
  for (int i = 0; i < MAX_ITERATIONS; i++) {
    for (int x = 0; x < 10; x++) {
      for (int y = 0; y < 10; y++) {
        if (grid[x][y] == 1) {
          percolate(x, y);
        }
      }
    }
  }

  // Print the percolated cells
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  // Free the memory
  for (int i = 0; i < 10; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}