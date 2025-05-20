//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 100

typedef struct Cell {
  int x, y;
  int state;
  struct Cell* next;
} Cell;

Cell* createCell(int x, int y) {
  Cell* cell = (Cell*)malloc(sizeof(Cell));
  cell->x = x;
  cell->y = y;
  cell->state = 0;
  cell->next = NULL;
  return cell;
}

void updateCells(Cell* cell) {
  int neighbors = 0;
  Cell* current = cell;
  Cell* iterator = current->next;

  // Count the number of neighbors
  while (iterator) {
    if (iterator->x == current->x - 1 && iterator->y == current->y) neighbors++;
    if (iterator->x == current->x + 1 && iterator->y == current->y) neighbors++;
    if (iterator->x == current->x && iterator->y == current->y - 1) neighbors++;
    if (iterator->x == current->x && iterator->y == current->y + 1) neighbors++;

    iterator = iterator->next;
  }

  // Apply the Game of Life rules
  if (neighbors < 2) cell->state = 0;
  else if (neighbors == 2) cell->state = 1;
  else if (neighbors == 3) cell->state = 1;
  else cell->state = 0;
}

int main() {
  // Create a grid of cells
  Cell* cells = createCell(0, 0);
  for (int x = 0; x < MAX_CELLS; x++) {
    for (int y = 0; y < MAX_CELLS; y++) {
      cells = createCell(x, y);
    }
  }

  // Simulate the Game of Life
  for (int t = 0; t < 10; t++) {
    updateCells(cells);
  }

  // Print the final state of the grid
  for (int x = 0; x < MAX_CELLS; x++) {
    for (int y = 0; y < MAX_CELLS; y++) {
      if (cells->state == 1) printf("O ");
      else printf(". ");
    }
    printf("\n");
  }

  return 0;
}