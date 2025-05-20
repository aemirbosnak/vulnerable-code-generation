//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUDO_SIZE 9

typedef struct Sudoku {
  int **board;
  int **mask;
  int solved;
} Sudoku;

Sudoku *sudoku_new() {
  Sudoku *s = malloc(sizeof(Sudoku));
  s->board = malloc(SUDO_SIZE * sizeof(int *));
  s->mask = malloc(SUDO_SIZE * sizeof(int *));
  s->solved = 0;
  for (int i = 0; i < SUDO_SIZE; i++) {
    s->board[i] = malloc(SUDO_SIZE * sizeof(int));
    s->mask[i] = malloc(SUDO_SIZE * sizeof(int));
    for (int j = 0; j < SUDO_SIZE; j++) {
      s->board[i][j] = 0;
      s->mask[i][j] = 0;
    }
  }
  return s;
}

void sudoku_solve(Sudoku *s) {
  if (s->solved) {
    return;
  }
  for (int i = 0; i < SUDO_SIZE; i++) {
    for (int j = 0; j < SUDO_SIZE; j++) {
      if (s->board[i][j] == 0 && s->mask[i][j] == 0) {
        for (int k = 1; k <= SUDO_SIZE; k++) {
          if (sudoku_valid(s, i, j, k)) {
            s->board[i][j] = k;
            s->mask[i][j] = k;
            sudoku_solve(s);
            s->board[i][j] = 0;
            s->mask[i][j] = 0;
          }
        }
      }
    }
  }
  s->solved = 1;
}

int sudoku_valid(Sudoku *s, int i, int j, int k) {
  // Row valid
  for (int l = 0; l < SUDO_SIZE; l++) {
    if (s->board[i][l] == k) {
      return 0;
    }
  }

  // Column valid
  for (int m = 0; m < SUDO_SIZE; m++) {
    if (s->board[m][j] == k) {
      return 0;
    }
  }

  // Subgrid valid
  int x = i / 3;
  int y = j / 3;
  for (int n = x * 3; n < x * 3 + 3; n++) {
    for (int m = y * 3; m < y * 3 + 3; m++) {
      if (s->board[n][m] == k) {
        return 0;
      }
    }
  }

  return 1;
}

int main() {
  Sudoku *s = sudoku_new();
  sudoku_solve(s);
  for (int i = 0; i < SUDO_SIZE; i++) {
    for (int j = 0; j < SUDO_SIZE; j++) {
      printf("%d ", s->board[i][j]);
    }
    printf("\n");
  }
  free(s);
  return 0;
}