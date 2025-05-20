//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 9

typedef struct Sudoku {
  int **board;
  int size;
  int **sol;
} Sudoku;

Sudoku *sudoku_new(int size) {
  Sudoku *s = malloc(sizeof(Sudoku));
  s->board = malloc(size * size * sizeof(int));
  s->size = size;
  s->sol = malloc(size * size * sizeof(int));

  return s;
}

void sudoku_init(Sudoku *s) {
  for (int i = 0; i < s->size; i++) {
    for (int j = 0; j < s->size; j++) {
      s->board[i][j] = 0;
      s->sol[i][j] = 0;
    }
  }
}

void sudoku_solve(Sudoku *s) {
  int **used = malloc(s->size * s->size * sizeof(int));
  for (int i = 0; i < s->size; i++) {
    for (int j = 0; j < s->size; j++) {
      if (s->board[i][j] == 0) {
        used[i][j] = 1;
      }
    }
  }

  int found = 0;
  for (int k = 1; k <= s->size; k++) {
    for (int i = 0; i < s->size; i++) {
      for (int j = 0; j < s->size; j++) {
        if (s->board[i][j] == k && used[i][j] == 0) {
          s->board[i][j] = k;
          used[i][j] = 1;
          sudoku_solve(s);
          s->board[i][j] = 0;
          used[i][j] = 0;
          if (found) {
            return;
          }
        }
      }
    }
  }

  s->sol = NULL;
  return;
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