//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9

typedef struct Sudoku_board {
  int **board;
  int size;
} Sudoku_board;

Sudoku_board *create_sudoku_board(int size) {
  Sudoku_board *board = malloc(sizeof(Sudoku_board));
  board->board = malloc(size * size * sizeof(int));
  board->size = size;
  return board;
}

void solve_sudoku(Sudoku_board *board) {
  int i, j, k, l, num, found = 0;
  for (i = 0; i < board->size; i++) {
    for (j = 0; j < board->size; j++) {
      if (board->board[i][j] == 0) {
        for (k = 0; k < board->size; k++) {
          for (l = 0; l < board->size; l++) {
            if (k != i && l != j && board->board[k][l] == board->board[i][j]) {
              num = board->board[k][l] + 1;
              if (num <= board->size && board->board[i][j] == 0) {
                board->board[i][j] = num;
                solve_sudoku(board);
                board->board[i][j] = 0;
                found = 1;
              }
            }
          }
        }
        if (!found) {
          return;
        }
      }
    }
  }
  return;
}

int main() {
  Sudoku_board *board = create_sudoku_board(MAX_SIZE);
  board->board[0][0] = 5;
  board->board[0][1] = 3;
  board->board[0][2] = 0;
  board->board[1][0] = 6;
  board->board[1][1] = 0;
  board->board[1][2] = 0;
  board->board[2][0] = 0;
  board->board[2][1] = 0;
  board->board[2][2] = 0;
  solve_sudoku(board);
  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      printf("%d ", board->board[i][j]);
    }
    printf("\n");
  }
  return 0;
}