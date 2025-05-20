//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 9

typedef struct Sudoku {
  int **board;
  int size;
} Sudoku;

Sudoku* sudoku_new(int size) {
  Sudoku* s = malloc(sizeof(Sudoku));
  s->board = malloc(size * size * sizeof(int));
  s->size = size;
  return s;
}

void sudoku_solve(Sudoku* s) {
  for (int r = 0; r < s->size; r++) {
    for (int c = 0; c < s->size; c++) {
      if (s->board[r][c] == 0) {
        for (int i = 0; i < s->size; i++) {
          for (int j = 0; j < s->size; j++) {
            if (s->board[i][j] != 0 && i != r && j != c) {
              int k = (s->board[i][j] - 1) / MAX;
              if ((s->board[r][c] & k) == 0) {
                s->board[r][c] = k + 1;
                sudoku_solve(s);
                s->board[r][c] = 0;
              }
            }
          }
        }
      }
    }
  }
  return;
}

int main() {
  Sudoku* s = sudoku_new(9);
  s->board = malloc(9 * 9 * sizeof(int));
  s->board[0][0] = 5;
  s->board[0][1] = 3;
  s->board[0][2] = 0;
  s->board[1][0] = 6;
  s->board[1][1] = 0;
  s->board[1][2] = 0;
  s->board[2][0] = 0;
  s->board[2][1] = 0;
  s->board[2][2] = 0;
  sudoku_solve(s);
  for (int r = 0; r < s->size; r++) {
    for (int c = 0; c < s->size; c++) {
      printf("%d ", s->board[r][c]);
    }
    printf("\n");
  }
  return 0;
}