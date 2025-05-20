//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: scalable
#include <stdlib.h>
#include <stdio.h>

#define BOARD_SIZE 20

typedef struct Cell {
  int state;
  struct Cell* neighbors;
} Cell;

Cell* createCell(int state) {
  Cell* cell = malloc(sizeof(Cell));
  cell->state = state;
  cell->neighbors = NULL;
  return cell;
}

void addNeighbor(Cell* cell, Cell* neighbor) {
  cell->neighbors = neighbor;
}

void simulateGameOfLife(Cell* cell) {
  int numAliveNeighbors = 0;
  for (Cell* neighbor = cell->neighbors; neighbor; neighbor = neighbor->neighbors) {
    if (neighbor->state == 1) {
      numAliveNeighbors++;
    }
  }

  if (cell->state == 1 && numAliveNeighbors < 2) {
    cell->state = 0;
  } else if (cell->state == 0 && numAliveNeighbors == 3) {
    cell->state = 1;
  }
}

int main() {
  Cell* board = createCell(0);
  for (int i = 0; i < BOARD_SIZE; i++) {
    addNeighbor(board, createCell(0));
  }

  board->state = 1;
  board->neighbors->state = 1;
  board->neighbors->neighbors->state = 1;

  simulateGameOfLife(board);

  if (board->state == 1) {
    printf("Cell is alive.\n");
  } else {
    printf("Cell is dead.\n");
  }

  return 0;
}