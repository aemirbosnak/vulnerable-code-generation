//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Cell {
  int state;
  struct Cell* up;
  struct Cell* right;
  struct Cell* down;
  struct Cell* left;
} Cell;

void initialize(Cell** cells) {
  for (int i = 0; i < MAX_SIZE; i++) {
    cells[i] = NULL;
  }
}

void fill(Cell* cell) {
  cell->state = 1;
  if (cell->up) {
    cell->up->state = 1;
  }
  if (cell->right) {
    cell->right->state = 1;
  }
  if (cell->down) {
    cell->down->state = 1;
  }
  if (cell->left) {
    cell->left->state = 1;
  }
}

void simulate(Cell** cells) {
  for (int i = 0; i < MAX_SIZE; i++) {
    if (cells[i] != NULL && cells[i]->state == 0) {
      fill(cells[i]);
    }
  }
}

int main() {
  Cell** cells = (Cell**)malloc(MAX_SIZE * sizeof(Cell));
  initialize(cells);

  cells[20]->state = 1;
  cells[20]->up->state = 1;
  cells[20]->right->state = 1;

  simulate(cells);

  for (int i = 0; i < MAX_SIZE; i++) {
    if (cells[i] != NULL) {
      printf("%d ", cells[i]->state);
    }
  }

  printf("\n");

  free(cells);

  return 0;
}