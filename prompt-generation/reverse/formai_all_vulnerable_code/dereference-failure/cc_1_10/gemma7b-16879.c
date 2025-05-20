//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

void solveSudoku(int **board) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] == 0) {
        for (int k = 0; k < 9; k++) {
          if (board[k][j] == board[i][k] && board[i][k] != 0) {
            board[i][j] = board[k][j];
          }
        }
        for (int l = 0; l < 9; l++) {
          if (board[i][l] == board[i][j] && board[i][l] != 0) {
            board[i][j] = board[i][l];
          }
        }
        if (board[j][0] == board[i][j] && board[j][0] != 0) {
          board[i][j] = board[j][0];
        }
        board[i][j] = 1;
        solveSudoku(board);
        board[i][j] = 0;
      }
    }
  }

  return;
}

int main() {
  int board[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                           {6, 0, 0, 1, 9, 5, 0, 0, 0},
                           {0, 9, 8, 0, 0, 0, 0, 0, 0},
                           {8, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0}};

  solveSudoku(board);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }

  return 0;
}