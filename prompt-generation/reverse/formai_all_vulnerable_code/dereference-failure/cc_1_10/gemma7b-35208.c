//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 20

typedef struct Cell {
  int state;
  struct Cell* next;
} Cell;

void initializeGame(Cell** head) {
  *head = NULL;
  for (int i = 0; i < MAX_CELLS; i++) {
    *head = malloc(sizeof(Cell));
    (*head)->state = 0;
    (*head)->next = NULL;
    head = &((*head)->next);
  }
}

void playGame(Cell* head) {
  for (Cell* current = head; current; current = current->next) {
    int aliveNeighbors = 0;
    for (Cell* neighbor = head; neighbor; neighbor = neighbor->next) {
      if (neighbor != current && neighbor->state == 1) {
        aliveNeighbors++;
      }
    }
    switch (aliveNeighbors) {
      case 2:
        current->state = 1;
        break;
      case 3:
        current->state = 1;
        break;
      default:
        current->state = 0;
        break;
    }
  }
}

int main() {
  Cell* head = NULL;
  initializeGame(&head);

  // Set up the initial state of the cells
  head->state = 1;
  head->next->state = 1;
  head->next->next->state = 1;
  head->next->next->next->state = 1;

  playGame(head);

  // Print the final state of the cells
  for (Cell* current = head; current; current = current->next) {
    printf("%d ", current->state);
  }
  printf("\n");

  return 0;
}