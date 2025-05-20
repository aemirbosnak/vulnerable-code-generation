//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

void solveSudoku(int **grid, int idx) {
  if (idx == MAX * MAX) {
    for (int r = 0; r < MAX; r++) {
      for (int c = 0; c < MAX; c++) {
        printf("%d ", grid[r][c]);
      }
    }
    printf("\n");
    return;
  }

  for (int n = 0; n < MAX; n++) {
    if (grid[idx / MAX][n] == 0 && isSafe(grid, idx, n)) {
      grid[idx / MAX][n] = idx + 1;
      solveSudoku(grid, idx + 1);
      grid[idx / MAX][n] = 0;
    }
  }
}

int isSafe(int **grid, int idx, int n) {
  for (int r = 0; r < MAX; r++) {
    if (grid[r][n] != 0 && grid[r][n] == idx + 1) {
      return 0;
    }
  }

  for (int c = 0; c < MAX; c++) {
    if (grid[idx / MAX][c] != 0 && grid[idx / MAX][c] == idx + 1) {
      return 0;
    }
  }

  return 1;
}

int main() {
  int **grid = (int **)malloc(MAX * sizeof(int *));
  for (int i = 0; i < MAX; i++) {
    grid[i] = (int *)malloc(MAX * sizeof(int));
  }

  solveSudoku(grid, 0);

  return 0;
}