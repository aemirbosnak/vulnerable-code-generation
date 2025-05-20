//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: careful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_GENERATIONS 100
#define GRID_SIZE 10

// Define the Percolation Simulation function
void percolationsim(int **grid, int size) {
  // Allocate memory for the grid
  grid = malloc(size * size * sizeof(int));
  for (int i = 0; i < size * size; i++) {
    grid[i] = 0;
  }

  // Generate the initial state of the grid
  srand(time(NULL));
  for (int i = 0; i < size * size; i++) {
    grid[i] = rand() % 2;
  }

  // Simulate generations
  for (int generation = 0; generation < MAX_GENERATIONS; generation++) {
    // Iterate over the grid
    for (int r = 0; r < size; r++) {
      for (int c = 0; c < size; c++) {
        // Check if the cell is alive
        if (grid[r * size + c] == 1) {
          // If the cell has at least one neighbor alive, it survives
          int neighbors = 0;
          for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
              if (r + dr >= 0 && r + dr < size && c + dc >= 0 && c + dc < size && grid[(r + dr) * size + (c + dc)] == 1) {
                neighbors++;
              }
            }
          }
          // If the cell has no neighbors alive, it dies
          if (neighbors == 0) {
            grid[r * size + c] = 0;
          }
        }
      }
    }
  }

  // Print the final state of the grid
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      printf("%d ", grid[r * size + c]);
    }
    printf("\n");
  }

  // Free the memory allocated for the grid
  free(grid);
}

int main() {
  int **grid;
  percolationsim(grid, GRID_SIZE);
  return 0;
}