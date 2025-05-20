//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define SUDO_SIZE 9

int sudoku_solve(int **board) {
  for (int r = 0; r < SUDO_SIZE; r++) {
    for (int c = 0; c < SUDO_SIZE; c++) {
      if (board[r][c] == 0) {
        for (int n = 0; n < SUDO_SIZE; n++) {
          if (board[r][n] == board[n][c] && board[n][n] != 0) {
            board[r][c] = board[n][n];
            if (sudoku_solve(board) == 1) {
              return 1;
            } else {
              board[r][c] = 0;
            }
          }
        }
        return 0;
      }
    }
  }

  return 1;
}

int main() {
  int **board = (int **)malloc(SUDO_SIZE * sizeof(int *));
  for (int i = 0; i < SUDO_SIZE; i++) {
    board[i] = (int *)malloc(SUDO_SIZE * sizeof(int));
  }

  board[0][0] = 5;
  board[0][1] = 3;
  board[0][2] = 0;
  board[0][3] = 0;
  board[0][4] = 0;
  board[0][5] = 0;
  board[0][6] = 0;
  board[0][7] = 0;
  board[0][8] = 0;

  board[1][0] = 6;
  board[1][1] = 0;
  board[1][2] = 0;
  board[1][3] = 0;
  board[1][4] = 0;
  board[1][5] = 0;
  board[1][6] = 0;
  board[1][7] = 0;
  board[1][8] = 0;

  board[2][0] = 0;
  board[2][1] = 0;
  board[2][2] = 0;
  board[2][3] = 0;
  board[2][4] = 0;
  board[2][5] = 0;
  board[2][6] = 0;
  board[2][7] = 0;
  board[2][8] = 0;

  sudoku_solve(board);

  for (int r = 0; r < SUDO_SIZE; r++) {
    for (int c = 0; c < SUDO_SIZE; c++) {
      printf("%d ", board[r][c]);
    }
    printf("\n");
  }

  return 0;
}