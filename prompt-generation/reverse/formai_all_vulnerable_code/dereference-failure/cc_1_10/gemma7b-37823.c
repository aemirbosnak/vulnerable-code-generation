//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

typedef struct Sudoku_board {
  int board[MAX][MAX];
  int solved;
  struct Sudoku_board* next;
} Sudoku_board;

Sudoku_board* sudoku_solve(Sudoku_board* board) {
  if (board->solved) {
    return board;
  }

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      if (board->board[i][j] == 0) {
        for (int k = 0; k < MAX; k++) {
          if (board->board[i][k] == board->board[k][j] && board->board[i][k] != 0) {
            board->board[i][j] = k + 1;
            sudoku_solve(board);
            board->board[i][j] = 0;
          }
        }
      }
    }
  }

  if (sudoku_solve(board) != NULL) {
    board->solved = 1;
    return board;
  } else {
    return NULL;
  }
}

int main() {
  Sudoku_board* board = malloc(sizeof(Sudoku_board));
  board->board[0][0] = 5;
  board->board[0][1] = 3;
  board->board[0][2] = 0;
  board->board[1][0] = 6;
  board->board[1][1] = 0;
  board->board[1][2] = 0;
  board->board[2][0] = 0;
  board->board[2][1] = 0;
  board->board[2][2] = 0;

  sudoku_solve(board);

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      printf("%d ", board->board[i][j]);
    }
    printf("\n");
  }

  return 0;
}