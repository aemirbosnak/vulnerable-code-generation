//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 9

#define EMPTY 0
#define FULL 1

typedef struct Sudoku {
  int grid[GRID_SIZE][GRID_SIZE];
  int solved;
} Sudoku;

Sudoku* sudoku_new() {
  Sudoku* s = malloc(sizeof(Sudoku));
  s->solved = 0;
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      s->grid[i][j] = EMPTY;
    }
  }
  return s;
}

void sudoku_solve(Sudoku* s) {
  if (s->solved) {
    return;
  }

  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      if (s->grid[i][j] == EMPTY) {
        for (int k = 0; k < GRID_SIZE; k++) {
          if (s->grid[i][k] == FULL && k != j) {
            if (s->grid[k][j] == EMPTY) {
              s->grid[i][j] = FULL;
              sudoku_solve(s);
              s->grid[i][j] = EMPTY;
            }
          }
        }
      }
    }
  }

  s->solved = 1;
}

int main() {
  Sudoku* s = sudoku_new();

  // Fill the sudoku grid with your own numbers
  s->grid[0][0] = FULL;
  s->grid[0][1] = FULL;
  s->grid[0][2] = FULL;
  s->grid[1][0] = FULL;
  s->grid[1][2] = FULL;
  s->grid[2][0] = FULL;
  s->grid[2][1] = FULL;

  sudoku_solve(s);

  // Print the solved sudoku grid
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      printf("%d ", s->grid[i][j]);
    }
    printf("\n");
  }

  return 0;
}