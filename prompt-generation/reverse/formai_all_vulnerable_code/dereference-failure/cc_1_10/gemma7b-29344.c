//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>

#define MAX_CELLS 20

typedef struct Cell {
  int alive;
  struct Cell* next;
} Cell;

void initialize(Cell** head) {
  *head = malloc(sizeof(Cell));
  (*head)->alive = 0;
  (*head)->next = NULL;
}

void addCell(Cell** head, int alive) {
  Cell* newCell = malloc(sizeof(Cell));
  newCell->alive = alive;
  newCell->next = NULL;

  if (*head) {
    (*head)->next = newCell;
  } else {
    *head = newCell;
  }
}

void update(Cell* head) {
  Cell* current = head;
  while (current) {
    int neighbors = 0;
    Cell* neighbor = current->next;
    while (neighbor) {
      if (neighbor->alive) {
        neighbors++;
      }
      neighbor = neighbor->next;
    }

    if (current->alive && neighbors < 2) {
      current->alive = 0;
    } else if (!current->alive && neighbors == 2) {
      current->alive = 1;
    }
    current = current->next;
  }
}

int main() {
  Cell* head = NULL;
  initialize(&head);

  // Add some cells
  addCell(&head, 1);
  addCell(&head, 1);
  addCell(&head, 0);
  addCell(&head, 1);

  // Update the cells
  update(head);

  // Print the cells
  Cell* current = head;
  while (current) {
    printf("%d ", current->alive);
    current = current->next;
  }

  return 0;
}