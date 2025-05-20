//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: decentralized
#include <stdlib.h>
#include <time.h>

// Define the grid size
#define GRID_SIZE 10

// Define the probability of a cell being wet
#define PROB_WET 0.5

// Create a grid of cells
int **grid = NULL;

// Function to simulate percolation
void simulatePercolation() {
  // Allocate memory for the grid
  grid = (int **)malloc(GRID_SIZE * sizeof(int *));
  for (int i = 0; i < GRID_SIZE; i++) {
    grid[i] = (int *)malloc(GRID_SIZE * sizeof(int));
  }

  // Initialize the grid
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      grid[i][j] = 0;
    }
  }

  // Simulate the wet cells
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      if (rand() % 1000 < PROB_WET) {
        grid[i][j] = 1;
      }
    }
  }

  // Print the grid
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  // Free the memory
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      free(grid[i][j]);
    }
    free(grid[i]);
  }
  free(grid);
}

int main() {
  // Simulate percolation
  simulatePercolation();

  return 0;
}