//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: realistic
#include <stdlib.h>
#include <stdio.h>

#define MAX_CELLS 20

typedef struct Cell {
  int state;
  struct Cell* next;
} Cell;

Cell* createCell(int state) {
  Cell* cell = malloc(sizeof(Cell));
  cell->state = state;
  cell->next = NULL;
  return cell;
}

void simulateGameOfLife(Cell* head) {
  Cell* currentCell = head;
  while (currentCell) {
    int numNeighbors = 0;
    Cell* neighborCell = currentCell->next;
    while (neighborCell) {
      if (neighborCell->state == 1) {
        numNeighbors++;
      }
      neighborCell = neighborCell->next;
    }

    switch (currentCell->state) {
      case 0:
        if (numNeighbors == 3) {
          currentCell->state = 1;
        }
        break;
      case 1:
        if (numNeighbors < 2 || numNeighbors > 3) {
          currentCell->state = 0;
        }
        break;
    }

    currentCell = currentCell->next;
  }
}

int main() {
  Cell* head = createCell(1);
  head->next = createCell(0);
  head->next->next = createCell(1);
  head->next->next->next = createCell(0);

  simulateGameOfLife(head);

  Cell* currentCell = head;
  while (currentCell) {
    printf("%d ", currentCell->state);
    currentCell = currentCell->next;
  }

  return 0;
}