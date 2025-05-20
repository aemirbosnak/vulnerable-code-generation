//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9

typedef struct Sudoku {
  int **board;
  int size;
  int **sol;
} Sudoku;

Sudoku *sudoku_create(int size) {
  Sudoku *s = malloc(sizeof(Sudoku));
  s->board = malloc(size * size * sizeof(int));
  s->size = size;
  s->sol = malloc(size * size * sizeof(int));

  return s;
}

void sudoku_solve(Sudoku *s) {
  int i, j, k;
  for (i = 0; i < s->size; i++) {
    for (j = 0; j < s->size; j++) {
      if (s->board[i][j] == 0) {
        for (k = 0; k < s->size; k++) {
          if (s->board[k][j] == 0 && k != i) {
            if (s->sol[k][j] == 0) {
              s->sol[k][j] = 1;
              sudoku_solve(s);
              s->sol[k][j] = 0;
            }
          }
        }
      }
    }
  }
}

int main() {
  Sudoku *s = sudoku_create(MAX_SIZE);

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

  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      printf("%d ", s->sol[i][j]);
    }
    printf("\n");
  }

  return 0;
}