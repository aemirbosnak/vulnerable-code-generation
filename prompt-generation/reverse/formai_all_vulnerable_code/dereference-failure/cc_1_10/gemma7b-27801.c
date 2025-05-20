//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void drawGrid(int **grid, int size) {
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      printf("%c ", grid[r][c] ? '#' : '.');
    }
    printf("\n");
  }
}

int main() {
  int size = MAX_SIZE;
  int **grid = (int **)malloc(size * sizeof(int *));
  for (int r = 0; r < size; r++) {
    grid[r] = (int *)malloc(size * sizeof(int));
  }

  // Initialize the grid
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      grid[r][c] = 0;
    }
  }

  // Create a random pattern
  grid[5][5] = 1;
  grid[5][6] = 1;
  grid[6][5] = 1;
  grid[6][6] = 1;

  // Simulate Game of Life
  for (int t = 0; t < 20; t++) {
    drawGrid(grid, size);
    for (int r = 0; r < size; r++) {
      for (int c = 0; c < size; c++) {
        int neighbors = 0;
        if (r - 1 >= 0) neighbors++;
        if (r + 1 < size) neighbors++;
        if (c - 1 >= 0) neighbors++;
        if (c + 1 < size) neighbors++;

        if (grid[r][c] == 1 && neighbors < 2) grid[r][c] = 0;
        else if (grid[r][c] == 0 && neighbors == 3) grid[r][c] = 1;
      }
    }
  }

  drawGrid(grid, size);

  free(grid);
  return 0;
}