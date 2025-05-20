//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void game_of_life(int **grid, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      int neighbors = 0;
      if (i - 1 >= 0) neighbors++;
      if (i + 1 < size) neighbors++;
      if (j - 1 >= 0) neighbors++;
      if (j + 1 < size) neighbors++;

      if (grid[i][j] == 0 && neighbors == 3) grid[i][j] = 1;
      if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) grid[i][j] = 0;
    }
  }
}

int main() {
  int size = MAX;
  int **grid = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < size; i++) grid[i] = (int *)malloc(size * sizeof(int));

  // Initialize the grid
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      grid[i][j] = 0;
    }
  }

  // Set some initial cells to 1
  grid[1][1] = 1;
  grid[2][2] = 1;
  grid[3][3] = 1;

  // Run the game of life for 10 generations
  for (int t = 0; t < 10; t++) {
    game_of_life(grid, size);
  }

  // Print the final grid
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  // Free the memory
  for (int i = 0; i < size; i++) free(grid[i]);
  free(grid);

  return 0;
}