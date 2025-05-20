//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: real-life
#include <stdlib.h>
#include <time.h>

// Define the Game of Life rules
void game_of_life(int **grid, int rows, int cols) {
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      int neighbors = 0;
      // Check the four neighbors
      if (r > 0) neighbors++;
      if (r < rows - 1) neighbors++;
      if (c > 0) neighbors++;
      if (c < cols - 1) neighbors++;

      // Apply the rules
      if (grid[r][c] == 0 && neighbors == 3) grid[r][c] = 1;
      if (grid[r][c] == 1 && (neighbors < 2 || neighbors > 3)) grid[r][c] = 0;
    }
  }
}

int main() {
  // Create a 2D array to store the game grid
  int **grid = NULL;
  int rows = 10;
  int cols = 10;
  grid = (int **)malloc(rows * sizeof(int *));
  for (int r = 0; r < rows; r++) {
    grid[r] = (int *)malloc(cols * sizeof(int));
  }

  // Initialize the grid with random values
  srand(time(NULL));
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      grid[r][c] = rand() % 2;
    }
  }

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