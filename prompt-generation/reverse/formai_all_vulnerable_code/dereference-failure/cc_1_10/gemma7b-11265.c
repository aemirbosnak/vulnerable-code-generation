//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 9

typedef struct Sudoku {
  int **board;
  int size;
  int solved;
} Sudoku;

Sudoku *sudoku_init(int size) {
  Sudoku *s = malloc(sizeof(Sudoku));
  s->board = malloc(size * size * sizeof(int));
  s->size = size;
  s->solved = 0;

  for (int i = 0; i < size * size; i++) {
    s->board[i] = 0;
  }

  return s;
}

void sudoku_solve(Sudoku *s) {
  if (s->solved) {
    return;
  }

  for (int i = 0; i < s->size * s->size; i++) {
    if (s->board[i] == 0) {
      for (int n = 1; n <= s->size; n++) {
        if (sudoku_valid(s, i, n)) {
          s->board[i] = n;
          sudoku_solve(s);
          s->board[i] = 0;
        }
      }
    }
  }

  s->solved = 1;
}

int sudoku_valid(Sudoku *s, int idx, int num) {
  int x = idx / s->size;
  int y = idx % s->size;

  for (int i = 0; i < s->size; i++) {
    if (s->board[idx] == num) {
      return 0;
    }
  }

  for (int i = 0; i < s->size; i++) {
    if (s->board[x * s->size + i] == num) {
      return 0;
    }
  }

  return 1;
}

int main() {
  Sudoku *s = sudoku_init(9);
  sudoku_solve(s);

  for (int i = 0; i < 81; i++) {
    printf("%d ", s->board[i]);
  }

  printf("\n");

  return 0;
}