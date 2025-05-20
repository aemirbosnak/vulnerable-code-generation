//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_GRID 9

typedef struct Sudoku {
  int **grid;
  int size;
} Sudoku;

Sudoku *sudoku_init(int size) {
  Sudoku *s = malloc(sizeof(Sudoku));
  s->size = size;
  s->grid = malloc(size * size * sizeof(int));
  for (int i = 0; i < size * size; i++) {
    s->grid[i] = 0;
  }
  return s;
}

void sudoku_solve(Sudoku *s) {
  for (int i = 0; i < s->size; i++) {
    for (int j = 0; j < s->size; j++) {
      if (s->grid[i][j] == 0) {
        for (int k = 0; k < s->size; k++) {
          if (s->grid[k][j] != 0 && k != i) {
            if (s->grid[i][k] != 0) {
              continue;
            }
          }
        }
        s->grid[i][j] = 1;
        sudoku_solve(s);
        s->grid[i][j] = 0;
      }
    }
  }
}

int main() {
  Sudoku *s = sudoku_init(MAX_GRID);
  sudoku_solve(s);

  for (int i = 0; i < MAX_GRID; i++) {
    for (int j = 0; j < MAX_GRID; j++) {
      printf("%d ", s->grid[i][j]);
    }
    printf("\n");
  }

  free(s->grid);
  free(s);

  return 0;
}