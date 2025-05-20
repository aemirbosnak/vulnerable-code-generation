//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define the grid size
#define GRID_SIZE 10

// Define the life cycle functions
void birth(int grid[GRID_SIZE][GRID_SIZE], int i, int j) {
  // If the cell is empty, set it to alive
  if (grid[i][j] == 0) {
    grid[i][j] = 1;
  }
}

void death(int grid[GRID_SIZE][GRID_SIZE], int i, int j) {
  // If the cell is alive, set it to dead
  if (grid[i][j] == 1) {
    grid[i][j] = 0;
  }
}

void update(int grid[GRID_SIZE][GRID_SIZE]) {
  // Loop through each cell in the grid
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      // Check the neighbors of the current cell
      int aliveNeighbors = 0;
      for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
          if (k == 0 || l == 0) continue;
          if (grid[i + k][j + l] == 1) {
            aliveNeighbors++;
          }
        }
      }
      
      // Apply the rules
      if (aliveNeighbors < 2 && aliveNeighbors > 0) {
        death(grid, i, j);
      } else if (aliveNeighbors == 2) {
        birth(grid, i, j);
      }
    }
  }
}

int main() {
  // Initialize the grid
  int grid[GRID_SIZE][GRID_SIZE] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

  // Run the game of life for 10 generations
  for (int generation = 0; generation < 10; generation++) {
    update(grid);
  }

  // Print the final state of the grid
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  return 0;
}