//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the Game of Life rules
void game_of_life(int **grid, int rows, int cols) {
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      int neighbors = 0;
      // Check the neighbors
      for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
          if (r + dr >= 0 && r + dr < rows && c + dc >= 0 && c + dc < cols && grid[r + dr][c + dc] == 1) {
            neighbors++;
          }
        }
      }
      // Apply the rules
      if (neighbors < 2) {
        grid[r][c] = 0;
      } else if (neighbors == 2) {
        grid[r][c] = 1;
      } else if (neighbors > 3) {
        grid[r][c] = 0;
      }
    }
  }
}

int main() {
  // Create a 2D array to represent the game grid
  int **grid = NULL;
  int rows = 5;
  int cols = 5;
  grid = (int **)malloc(rows * sizeof(int *));
  for (int r = 0; r < rows; r++) {
    grid[r] = (int *)malloc(cols * sizeof(int));
  }

  // Initialize the grid
  grid[1][1] = 1;
  grid[2][2] = 1;
  grid[2][3] = 1;

  // Play the game for 10 generations
  for (int gen = 0; gen < 10; gen++) {
    game_of_life(grid, rows, cols);
  }

  // Print the final grid
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      printf("%d ", grid[r][c]);
    }
    printf("\n");
  }

  // Free the memory
  for (int r = 0; r < rows; r++) {
    free(grid[r]);
  }
  free(grid);

  return 0;
}