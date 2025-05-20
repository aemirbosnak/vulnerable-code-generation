//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 100

typedef struct Cell {
  int alive;
  struct Cell* next;
} Cell;

Cell* createCell(int alive) {
  Cell* cell = (Cell*)malloc(sizeof(Cell));
  cell->alive = alive;
  cell->next = NULL;
  return cell;
}

void printCells(Cell* head) {
  Cell* current = head;
  while (current) {
    printf("%d ", current->alive);
    current = current->next;
  }
  printf("\n");
}

void simulate(Cell* head) {
  Cell* current = head;
  while (current) {
    int aliveNeighbors = 0;
    Cell* neighbor = current->next;
    while (neighbor) {
      if (neighbor->alive) {
        aliveNeighbors++;
      }
      neighbor = neighbor->next;
    }
    if (aliveNeighbors < 2) {
      current->alive = 0;
    } else if (aliveNeighbors > 3) {
      current->alive = 0;
    } else {
      current->alive = 1;
    }
    current = current->next;
  }
}

int main() {
  Cell* head = createCell(1);
  head->next = createCell(0);
  head->next->next = createCell(1);
  head->next->next->next = createCell(0);

  printCells(head);
  simulate(head);
  printCells(head);

  return 0;
}