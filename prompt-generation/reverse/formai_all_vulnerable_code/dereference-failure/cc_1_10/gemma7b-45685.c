//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: scalable
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
  for (i = 0; i < s->size; i++) {
    for (j = 0; j < s->size; j++) {
      if (s->board[i][j] == 0) {
        for (k = 0; k < s->size; k++) {
          if (s->board[k][j] == 0 && k != i) {
            if (sudoku_valid(s, i, j, k)) {
              s->board[i][j] = k + 1;
              sudoku_solve(s);
              s->board[i][j] = 0;
            }
          }
        }
      }
    }
  }
  s->solved = 1;
}

int sudoku_valid(Sudoku *s, int i, int j, int k) {
  int l, m;
  for (l = 0; l < s->size; l++) {
    if (s->board[l][j] == k) {
      return 0;
    }
  }
  for (m = 0; m < s->size; m++) {
    if (s->board[i][m] == k) {
      return 0;
    }
  }
  return 1;
}

int main() {
  Sudoku *s = sudoku_new(MAX_SIZE);
  sudoku_init(s);
  sudoku_solve(s);
  if (s->solved) {
    printf("Solution:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
      for (int j = 0; j < MAX_SIZE; j++) {
        printf("%d ", s->board[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("No solution found.\n");
  }
  return 0;
}