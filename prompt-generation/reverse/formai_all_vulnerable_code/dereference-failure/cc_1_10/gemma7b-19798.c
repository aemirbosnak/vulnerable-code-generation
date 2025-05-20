//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9

typedef struct Sudoku {
  int **board;
  int size;
} Sudoku;

void sudoku_init(Sudoku *sudoku, int size) {
  sudoku->size = size;
  sudoku->board = (int **)malloc(size * size * sizeof(int *));
  for (int i = 0; i < size; i++) {
    sudoku->board[i] = (int *)malloc(size * sizeof(int));
  }
}

void sudoku_solve(Sudoku *sudoku) {
  for (int r = 0; r < sudoku->size; r++) {
    for (int c = 0; c < sudoku->size; c++) {
      if (sudoku->board[r][c] == 0) {
        for (int n = 0; n < sudoku->size; n++) {
          if (sudoku->board[r][n] != 0 && sudoku->board[n][c] != 0) {
            int flag = 0;
            for (int i = 0; i < sudoku->size; i++) {
              if (sudoku->board[i][c] != 0 && sudoku->board[r][i] != 0) {
                flag = 1;
              }
            }
            if (flag == 0) {
              sudoku->board[r][c] = 1;
              sudoku_solve(sudoku);
              sudoku->board[r][c] = 0;
            }
          }
        }
      }
    }
  }
  return;
}

int main() {
  Sudoku sudoku;
  sudoku_init(&sudoku, MAX_SIZE);
  sudoku_solve(&sudoku);
  for (int r = 0; r < sudoku.size; r++) {
    for (int c = 0; c < sudoku.size; c++) {
      printf("%d ", sudoku.board[r][c]);
    }
    printf("\n");
  }
  return 0;
}