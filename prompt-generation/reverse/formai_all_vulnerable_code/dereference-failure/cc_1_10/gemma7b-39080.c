//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

void solveSudoku(int **board, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (board[i][j] == 0) {
        for (int k = 0; k < size; k++) {
          if (board[k][j] != 0 && board[i][k] != 0) {
            if (board[k][j] == board[i][k]) {
              board[i][j] = board[k][j];
            }
          }
        }
        board[i][j] = 1;
        solveSudoku(board, size);
        board[i][j] = 0;
      }
    }
  }
  return;
}

int main() {
  int size = 9;
  int **board = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < size; i++) {
    board[i] = (int *)malloc(size * sizeof(int));
  }

  board[0][0] = 5;
  board[0][1] = 3;
  board[0][2] = 0;
  board[1][0] = 6;
  board[1][1] = 0;
  board[1][2] = 0;
  board[2][0] = 0;
  board[2][1] = 0;
  board[2][2] = 0;

  solveSudoku(board, size);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }

  return 0;
}