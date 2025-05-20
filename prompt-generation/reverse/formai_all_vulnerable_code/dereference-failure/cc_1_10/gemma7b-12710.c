//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: rigorous
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
  for (int i = 0; i < s->size; i++) {
    for (int j = 0; j < s->size; j++) {
      s->board[i][j] = 0;
    }
  }
}

void sudoku_solve(Sudoku *s) {
  if (s->solved) {
    return;
  }

  for (int i = 0; i < s->size; i++) {
    for (int j = 0; j < s->size; j++) {
      if (s->board[i][j] == 0) {
        for (int k = 1; k <= s->size; k++) {
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
  // Row validation
  for (int l = 0; l < s->size; l++) {
    if (s->board[i][l] == k) {
      return 0;
    }
  }

  // Column validation
  for (int m = 0; m < s->size; m++) {
    if (s->board[m][j] == k) {
      return 0;
    }
  }

  // Subgrid validation
  int x = i / 3;
  int y = j / 3;
  for (int n = x * 3; n < x * 3 + 3; n++) {
    for (int o = y * 3; o < y * 3 + 3; o++) {
      if (s->board[n][o] == k) {
        return 0;
      }
    }
  }

  return 1;
}

int main() {
  Sudoku *s = sudoku_new(9);
  sudoku_init(s);

  sudoku_solve(s);

  if (s->solved) {
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