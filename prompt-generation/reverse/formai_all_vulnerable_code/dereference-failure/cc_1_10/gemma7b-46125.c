//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 20

typedef struct Cell {
  int x;
  int y;
  int state;
  struct Cell* next;
} Cell;

void initializeGame(Cell** head) {
  *head = NULL;
  for (int i = 0; i < MAX_CELLS; i++) {
    Cell* cell = malloc(sizeof(Cell));
    cell->x = i;
    cell->y = 0;
    cell->state = rand() % 2;
    cell->next = *head;
    *head = cell;
  }
}

void playGame(Cell* head) {
  for (Cell* cell = head; cell; cell = cell->next) {
    int numAliveNeighbors = 0;
    for (Cell* neighbor = head; neighbor; neighbor = neighbor->next) {
      if (neighbor->x == cell->x && neighbor->y == cell->y - 1) {
        numAliveNeighbors++;
      }
    }
    switch (cell->state) {
      case 0:
        if (numAliveNeighbors == 3) {
          cell->state = 1;
        }
        break;
      case 1:
        if (numAliveNeighbors < 2 || numAliveNeighbors > 3) {
          cell->state = 0;
        }
        break;
    }
  }
}

int main() {
  Cell* head = NULL;
  initializeGame(&head);
  playGame(head);
  return 0;
}