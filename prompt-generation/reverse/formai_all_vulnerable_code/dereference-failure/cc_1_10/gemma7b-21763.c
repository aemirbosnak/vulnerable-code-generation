//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdlib.h>
#include <stdio.h>

void draw_grid(int **grid, int rows, int cols) {
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      printf("%c ", grid[r][c] ? '#' : '.');
    }
    printf("\n");
  }
}

int main() {
  int rows = 5;
  int cols = 5;
  int **grid = (int **)malloc(rows * sizeof(int *));
  for (int r = 0; r < rows; r++) {
    grid[r] = (int *)malloc(cols * sizeof(int));
  }

  // Initialize the grid
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      grid[r][c] = 0;
    }
  }

  // Set some random cells to 1
  grid[2][2] = 1;
  grid[3][3] = 1;
  grid[1][4] = 1;

  // Game of Life rules
  for (int t = 0; t < 5; t++) {
    draw_grid(grid, rows, cols);
    printf("Generation %d:\n", t);

    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        int neighbors = 0;
        if (r - 1 >= 0) neighbors++;
        if (r + 1 < rows) neighbors++;
        if (c - 1 >= 0) neighbors++;
        if (c + 1 < cols) neighbors++;

        if (grid[r][c] == 1 && neighbors < 2) grid[r][c] = 0;
        if (grid[r][c] == 0 && neighbors == 3) grid[r][c] = 1;
      }
    }
  }

  draw_grid(grid, rows, cols);
  printf("Final Generation:\n");

  free(grid);
  return 0;
}