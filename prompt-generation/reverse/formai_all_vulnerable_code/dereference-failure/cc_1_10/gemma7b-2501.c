//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIM_SIZE 20
#define MAX_WATER_LEVEL 5

typedef struct Cell {
  int water_level;
  struct Cell* up, *right, *down, *left;
} Cell;

Cell* createCell(int x, int y) {
  Cell* cell = (Cell*)malloc(sizeof(Cell));
  cell->water_level = 0;
  cell->up = NULL;
  cell->right = NULL;
  cell->down = NULL;
  cell->left = NULL;
  return cell;
}

void simulatePercolation(Cell* cell) {
  if (cell->water_level == MAX_WATER_LEVEL) {
    return;
  }
  int random_num = rand() % 2;
  if (random_num == 0) {
    cell->water_level++;
  } else {
    if (cell->up) {
      simulatePercolation(cell->up);
    }
    if (cell->right) {
      simulatePercolation(cell->right);
    }
    if (cell->down) {
      simulatePercolation(cell->down);
    }
    if (cell->left) {
      simulatePercolation(cell->left);
    }
  }
}

int main() {
  srand(time(NULL));
  Cell* cell = createCell(MAX_SIM_SIZE, MAX_SIM_SIZE);
  simulatePercolation(cell);
  return 0;
}