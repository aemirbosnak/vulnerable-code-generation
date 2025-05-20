//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void sudoku_init(Sudoku *s) {
  int i, j;
  for (i = 0; i < s->size; i++) {
    for (j = 0; j < s->size; j++) {
      s->board[i][j] = 0;
    }
  }
}

void sudoku_solve(Sudoku *s) {
  int i, j, k;
  if (s->solved) return;
  for (i = 0; i < s->size; i++) {
    for (j = 0; j < s->size; j++) {
      if (s->board[i][j] == 0) {
        for (k = 0; k < s->size; k++) {
          if (s->board[i][k] == 0 && s->board[k][j] == 0 && s->board[i][j] == 0) {
            s->board[i][j] = 1;
            sudoku_solve(s);
            s->board[i][j] = 0;
          }
        }
      }
    }
  }
  s->solved = 1;
}

int main() {
  Sudoku *s = sudoku_new(9);
  sudoku_init(s);
  sudoku_solve(s);
  for (int i = 0; i < s->size; i++) {
    for (int j = 0; j < s->size; j++) {
      printf("%d ", s->board[i][j]);
    }
    printf("\n");
  }
  return 0;
}