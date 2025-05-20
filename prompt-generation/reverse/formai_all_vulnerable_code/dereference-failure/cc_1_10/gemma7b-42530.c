//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define SUDO_SIZE 9

typedef struct SudokuCell {
  int value;
  int used;
  struct SudokuCell **children;
} SudokuCell;

SudokuCell **sudoku_create(int size)
{
  SudokuCell **cells = malloc(size * sizeof(SudokuCell));
  for (int i = 0; i < size; i++) {
    cells[i] = malloc(sizeof(SudokuCell));
    cells[i]->value = 0;
    cells[i]->used = 0;
    cells[i]->children = NULL;
  }
  return cells;
}

void sudoku_solve(SudokuCell **cells)
{
  for (int i = 0; i < SUDO_SIZE; i++) {
    if (!cells[i]->used && cells[i]->value == 0) {
      for (int j = 0; j < SUDO_SIZE; j++) {
        if (cells[j]->used && cells[j]->value == cells[i]->value) {
          cells[i]->used = 1;
          sudoku_solve(cells);
          cells[i]->used = 0;
        }
      }
      cells[i]->value = 1;
      sudoku_solve(cells);
      cells[i]->value = 0;
    }
  }
}

int main()
{
  SudokuCell **cells = sudoku_create(SUDO_SIZE);
  sudoku_solve(cells);

  for (int i = 0; i < SUDO_SIZE; i++) {
    printf("%d ", cells[i]->value);
  }
  printf("\n");

  return 0;
}