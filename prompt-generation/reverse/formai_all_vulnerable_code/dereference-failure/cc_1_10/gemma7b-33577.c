//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 9

typedef struct Sudoku {
  int **board;
  int size;
} Sudoku;

Sudoku *sudoku_create(int size) {
  Sudoku *s = malloc(sizeof(Sudoku));
  s->size = size;
  s->board = malloc(size * size * sizeof(int));
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      s->board[i][j] = 0;
    }
  }
  return s;
}

void sudoku_solve(Sudoku *s) {
  for (int i = 0; i < s->size; i++) {
    for (int j = 0; j < s->size; j++) {
      if (s->board[i][j] == 0) {
        for (int k = 0; k < s->size; k++) {
          if (k != i && s->board[k][j] != 0) {
            int num = s->board[k][j];
            s->board[i][j] = num;
            if (sudoku_valid(s)) {
              sudoku_solve(s);
              s->board[i][j] = 0;
            }
          }
        }
      }
    }
  }
}

int sudoku_valid(Sudoku *s) {
  for (int i = 0; i < s->size; i++) {
    int row_sum[MAX] = {0};
    for (int j = 0; j < s->size; j++) {
      row_sum[s->board[i][j]]++;
    }
    for (int k = 0; k < MAX; k++) {
      if (row_sum[k] > 1) {
        return 0;
      }
    }
  }

  for (int i = 0; i < s->size; i++) {
    int col_sum[MAX] = {0};
    for (int j = 0; j < s->size; j++) {
      col_sum[s->board[j][i]]++;
    }
    for (int k = 0; k < MAX; k++) {
      if (col_sum[k] > 1) {
        return 0;
      }
    }
  }

  return 1;
}

int main() {
  Sudoku *s = sudoku_create(9);
  sudoku_solve(s);

  for (int i = 0; i < s->size; i++) {
    for (int j = 0; j < s->size; j++) {
      printf("%d ", s->board[i][j]);
    }
    printf("\n");
  }

  free(s->board);
  free(s);

  return 0;
}