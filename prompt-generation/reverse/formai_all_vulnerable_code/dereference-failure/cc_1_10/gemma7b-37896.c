//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: genius
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIM_SIZE 20
#define MAX_WATER_LEVEL 10

typedef struct Cell {
  int water_level;
  struct Cell* up;
  struct Cell* right;
  struct Cell* down;
  struct Cell* left;
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
  int random_num = rand() % MAX_WATER_LEVEL;
  if (cell->water_level < random_num) {
    cell->water_level++;
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