//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 1024

typedef struct Cell {
  int state;
  struct Cell* north;
  struct Cell* south;
  struct Cell* east;
  struct Cell* west;
} Cell;

void init_cell(Cell* cell) {
  cell->state = 0;
  cell->north = NULL;
  cell->south = NULL;
  cell->east = NULL;
  cell->west = NULL;
}

void percolate(Cell* cell) {
  if (cell->state == 1) {
    return;
  }

  int rand_num = rand() % 4;
  switch (rand_num) {
    case 0:
      if (cell->north) {
        percolate(cell->north);
      }
      break;
    case 1:
      if (cell->south) {
        percolate(cell->south);
      }
      break;
    case 2:
      if (cell->east) {
        percolate(cell->east);
      }
      break;
    case 3:
      if (cell->west) {
        percolate(cell->west);
      }
      break;
  }

  if (cell->state == 0) {
    cell->state = 1;
  }
}

int main() {
  srand(time(NULL));

  Cell* cells = (Cell*)malloc(sizeof(Cell) * MAX_CELLS);
  for (int i = 0; i < MAX_CELLS; i++) {
    init_cell(cells + i);
  }

  percolate(cells);

  for (int i = 0; i < MAX_CELLS; i++) {
    if (cells[i].state == 1) {
      printf("Cell %d is wet\n", i);
    }
  }

  free(cells);

  return 0;
}