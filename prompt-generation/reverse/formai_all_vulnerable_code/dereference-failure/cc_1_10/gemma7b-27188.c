//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

void solveSudoku(int **grid) {
  for (int r = 0; r < MAX; r++) {
    for (int c = 0; c < MAX; c++) {
      if (grid[r][c] == 0) {
        for (int i = 0; i < MAX; i++) {
          if (grid[r][i] != 0 && grid[i][c] != 0 && grid[i][c] != grid[r][c]) {
            grid[r][c] = i + 1;
            solveSudoku(grid);
            grid[r][c] = 0;
          }
        }
      }
    }
  }
  return;
}

int main() {
  int **grid = (int **)malloc(MAX * MAX * sizeof(int));
  for (int r = 0; r < MAX; r++) {
    grid[r] = (int *)malloc(MAX * sizeof(int));
    for (int c = 0; c < MAX; c++) {
      grid[r][c] = 0;
    }
  }

  grid[0][0] = 5;
  grid[0][1] = 3;
  grid[0][2] = 0;
  grid[1][0] = 6;
  grid[1][1] = 0;
  grid[1][2] = 0;
  grid[2][0] = 0;
  grid[2][1] = 0;
  grid[2][2] = 0;

  solveSudoku(grid);

  for (int r = 0; r < MAX; r++) {
    for (int c = 0; c < MAX; c++) {
      printf("%d ", grid[r][c]);
    }
    printf("\n");
  }

  return 0;
}