//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: protected
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIM_SIZE 20
#define MAX_WATER_LEVEL 5

typedef struct Cell {
  int water_level;
  struct Cell* neighbors[4];
} Cell;

void initialize_cell(Cell* cell) {
  cell->water_level = 0;
  for (int i = 0; i < 4; i++) {
    cell->neighbors[i] = NULL;
  }
}

void simulate_percolation(Cell* cell) {
  if (cell->water_level == MAX_WATER_LEVEL) {
    return;
  }
  int sum = 0;
  for (int i = 0; i < 4; i++) {
    if (cell->neighbors[i] != NULL && cell->neighbors[i]->water_level > sum) {
      sum++;
    }
  }
  if (sum > 0) {
    cell->water_level++;
  }
}

int main() {
  srand(time(NULL));

  Cell* cells[MAX_SIM_SIZE];
  for (int i = 0; i < MAX_SIM_SIZE; i++) {
    cells[i] = malloc(sizeof(Cell));
    initialize_cell(cells[i]);
  }

  for (int i = 0; i < MAX_SIM_SIZE; i++) {
    simulate_percolation(cells[i]);
  }

  for (int i = 0; i < MAX_SIM_SIZE; i++) {
    printf("Cell %d: Water Level %d\n", i, cells[i]->water_level);
  }

  return 0;
}