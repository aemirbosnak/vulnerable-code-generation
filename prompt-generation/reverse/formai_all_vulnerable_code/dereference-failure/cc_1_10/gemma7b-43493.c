//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10

typedef struct Cell Cell;
struct Cell {
  int x, y;
  Cell *next;
  Cell *prev;
  int state;
  int alive;
};

Cell *createCell(int x, int y) {
  Cell *cell = (Cell *)malloc(sizeof(Cell));
  cell->x = x;
  cell->y = y;
  cell->next = NULL;
  cell->prev = NULL;
  cell->state = 0;
  cell->alive = 0;
  return cell;
}

void updateCell(Cell *cell) {
  int numAliveNeighbors = 0;
  Cell *neighbor = cell->prev;
  while (neighbor) {
    if (neighbor->alive) {
      numAliveNeighbors++;
    }
    neighbor = neighbor->next;
  }
  neighbor = cell->next;
  while (neighbor) {
    if (neighbor->alive) {
      numAliveNeighbors++;
    }
    neighbor = neighbor->next;
  }
  if (cell->alive && numAliveNeighbors < 2) {
    cell->alive = 0;
  } else if (!cell->alive && numAliveNeighbors == 3) {
    cell->alive = 1;
  }
}

int main() {
  srand(time(NULL));
  Cell *grid = createCell(GRID_SIZE, GRID_SIZE);
  for (int x = 0; x < GRID_SIZE; x++) {
    for (int y = 0; y < GRID_SIZE; y++) {
      grid->alive = rand() % 2;
      grid->next = createCell(x + 1, y);
      grid = grid->next;
    }
  }

  for (int t = 0; t < 10; t++) {
    for (Cell *cell = grid; cell; cell = cell->next) {
      updateCell(cell);
    }
    printf("Generation %d:\n", t);
    for (int x = 0; x < GRID_SIZE; x++) {
      for (int y = 0; y < GRID_SIZE; y++) {
        if (grid->alive) {
          printf("* ");
        } else {
          printf("  ");
        }
        grid = grid->next;
      }
      printf("\n");
    }
  }

  return 0;
}