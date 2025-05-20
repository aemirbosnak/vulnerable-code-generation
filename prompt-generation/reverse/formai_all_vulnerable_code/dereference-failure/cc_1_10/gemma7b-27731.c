//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

typedef struct Sudoku {
  int **board;
  int size;
  struct Sudoku *next;
} Sudoku;

Sudoku *sudoku_new(int size) {
  Sudoku *s = malloc(sizeof(Sudoku));
  s->board = malloc(size * size * sizeof(int));
  s->size = size;
  s->next = NULL;
  return s;
}

void sudoku_solve(Sudoku *s) {
  if (s->board[0][0] != 0) {
    return;
  }
  for (int i = 0; i < s->size; i++) {
    for (int j = 0; j < s->size; j++) {
      if (s->board[i][j] == 0) {
        for (int k = 0; k < s->size; k++) {
          if (s->board[i][k] != 0 && s->board[k][j] != 0) {
            if (s->board[i][j] == 0) {
              s->board[i][j] = k + 1;
              sudoku_solve(s);
              s->board[i][j] = 0;
            }
          }
        }
      }
    }
  }
}

int main() {
  Sudoku *s = sudoku_new(9);
  s->board[0][0] = 5;
  s->board[0][1] = 3;
  s->board[0][2] = 4;
  s->board[1][0] = 6;
  s->board[1][1] = 2;
  s->board[1][2] = 8;
  s->board[2][0] = 1;
  s->board[2][1] = 9;
  s->board[2][2] = 7;
  sudoku_solve(s);
  for (int i = 0; i < s->size; i++) {
    for (int j = 0; j < s->size; j++) {
      printf("%d ", s->board[i][j]);
    }
    printf("\n");
  }
  return 0;
}