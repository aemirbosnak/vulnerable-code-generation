//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

void solveSudoku(int **grid) {
  for (int r = 0; r < MAX; r++) {
    for (int c = 0; c < MAX; c++) {
      if (grid[r][c] == 0) {
        for (int n = 1; n <= MAX; n++) {
          if (isValid(grid, r, c, n)) {
            grid[r][c] = n;
            solveSudoku(grid);
            grid[r][c] = 0;
          }
        }
      }
    }
  }
  return;
}

int isValid(int **grid, int r, int c, int n) {
  // Row validation
  for (int i = 0; i < MAX; i++) {
    if (grid[r][i] == n) {
      return 0;
    }
  }

  // Column validation
  for (int j = 0; j < MAX; j++) {
    if (grid[j][c] == n) {
      return 0;
    }
  }

  // Subgrid validation
  int sr = r / 3;
  int sc = c / 3;
  for (int i = sr * 3; i < sr * 3 + 3; i++) {
    for (int j = sc * 3; j < sc * 3 + 3; j++) {
      if (grid[i][j] == n) {
        return 0;
      }
    }
  }

  return 1;
}

int main() {
  int **grid = (int **)malloc(MAX * MAX * sizeof(int));
  for (int i = 0; i < MAX; i++) {
    grid[i] = (int *)malloc(MAX * sizeof(int));
  }

  solveSudoku(grid);

  for (int r = 0; r < MAX; r++) {
    for (int c = 0; c < MAX; c++) {
      printf("%d ", grid[r][c]);
    }
    printf("\n");
  }

  return 0;
}