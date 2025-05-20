//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 100

typedef struct Cell {
  int state;
  struct Cell* next;
} Cell;

void initialize(Cell** head) {
  *head = NULL;
}

void insert(Cell** head, int state) {
  Cell* newCell = malloc(sizeof(Cell));
  newCell->state = state;
  newCell->next = NULL;

  if (*head == NULL) {
    *head = newCell;
  } else {
    (*head)->next = newCell;
  }
}

void simulate(Cell* head) {
  Cell* currentCell = head;
  while (currentCell) {
    int aliveNeighbors = 0;
    Cell* neighborCell = currentCell->next;
    while (neighborCell) {
      if (neighborCell->state == 1) {
        aliveNeighbors++;
      }
      neighborCell = neighborCell->next;
    }

    int stateChange = 0;
    if (aliveNeighbors < 2) {
      stateChange = -1;
    } else if (aliveNeighbors > 3) {
      stateChange = -1;
    } else if (aliveNeighbors == 2) {
      stateChange = 1;
    }

    currentCell->state += stateChange;
    currentCell = currentCell->next;
  }
}

int main() {
  Cell* head = NULL;
  initialize(&head);

  insert(head, 1);
  insert(head, 0);
  insert(head, 1);
  insert(head, 0);

  simulate(head);

  Cell* currentCell = head;
  while (currentCell) {
    printf("%d ", currentCell->state);
    currentCell = currentCell->next;
  }

  return 0;
}