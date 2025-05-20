//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: inquisitive
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
  if (s->solved) {
    return;
  }
  for (i = 0; i < s->size; i++) {
    for (j = 0; j < s->size; j++) {
      if (s->board[i][j] == 0) {
        for (k = 1; k <= s->size; k++) {
          if (sudoku_valid(s, i, j, k)) {
            s->board[i][j] = k;
            sudoku_solve(s);
            s->board[i][j] = 0;
          }
        }
      }
    }
  }
  s->solved = 1;
}

int sudoku_valid(Sudoku *s, int i, int j, int k) {
  int r, c, g;
  for (r = 0; r < s->size; r++) {
    if (s->board[r][j] == k) {
      return 0;
    }
  }
  for (c = 0; c < s->size; c++) {
    if (s->board[i][c] == k) {
      return 0;
    }
  }
  for (g = 0; g < 3; g++) {
    if (s->board[g][i] == k) {
      return 0;
    }
  }
  return 1;
}

int main() {
  Sudoku *s = sudoku_new(9);
  sudoku_init(s);
  sudoku_solve(s);
  if (s->solved) {
    printf("Sudoku solution:\n");
    for (int i = 0; i < s->size; i++) {
      for (int j = 0; j < s->size; j++) {
        printf("%d ", s->board[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("No solution found.\n");
  }
  return 0;
}