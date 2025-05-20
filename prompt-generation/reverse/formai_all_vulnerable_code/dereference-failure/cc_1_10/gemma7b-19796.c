//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9

typedef struct Sudoku {
  int **board;
  int size;
  int solved;
} Sudoku;

Sudoku *sudoku_new(int size) {
  Sudoku *s = malloc(sizeof(Sudoku));
  s->board = malloc(size * size * sizeof(int));
  s->size = size;
  s->solved = 0;
  return s;
}

void sudoku_solve(Sudoku *s) {
  for (int r = 0; r < s->size; r++) {
    for (int c = 0; c < s->size; c++) {
      if (s->board[r][c] == 0) {
        for (int n = 0; n < s->size; n++) {
          if (s->board[r][n] != 0 && s->board[n][c] != 0) {
            if (s->board[r][n] == s->board[n][c]) {
              s->board[r][c] = s->board[r][n];
              sudoku_solve(s);
              s->board[r][c] = 0;
            }
          }
        }
      }
    }
  }
  s->solved = 1;
}

int main() {
  Sudoku *s = sudoku_new(MAX_SIZE);
  s->board[0][0] = 5;
  s->board[0][2] = 3;
  s->board[0][4] = 4;
  s->board[1][0] = 6;
  s->board[1][2] = 8;
  s->board[1][4] = 1;
  s->board[2][0] = 9;
  s->board[2][2] = 2;
  s->board[2][4] = 6;
  s->board[3][0] = 1;
  s->board[3][2] = 4;
  s->board[3][4] = 9;
  s->board[4][0] = 3;
  s->board[4][2] = 9;
  s->board[4][4] = 5;
  sudoku_solve(s);
  if (s->solved) {
    for (int r = 0; r < MAX_SIZE; r++) {
      for (int c = 0; c < MAX_SIZE; c++) {
        printf("%d ", s->board[r][c]);
      }
      printf("\n");
    }
  } else {
    printf("No solution found.\n");
  }
  return 0;
}