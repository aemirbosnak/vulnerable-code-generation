//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct Cell {
  int state;
  struct Cell *next;
} Cell;

void initialize(Cell **head) {
  *head = NULL;
}

void insert(Cell **head, int state) {
  Cell *new_cell = malloc(sizeof(Cell));
  new_cell->state = state;
  new_cell->next = NULL;

  if (*head == NULL) {
    *head = new_cell;
  } else {
    (*head)->next = new_cell;
  }
}

void simulate(Cell *head) {
  Cell *current = head;
  while (current) {
    int neighbors = 0;
    Cell *neighbor = current->next;
    while (neighbor) {
      if (neighbor->state == 1) {
        neighbors++;
      }
      neighbor = neighbor->next;
    }

    int state = current->state;
    if (state == 0 && neighbors == 3) {
      insert(head, 1);
    } else if (state == 1 && (neighbors < 2 || neighbors > 3)) {
      insert(head, 0);
    }
    current = current->next;
  }
}

int main() {
  Cell *head = NULL;
  initialize(&head);

  insert(head, 1);
  insert(head, 0);
  insert(head, 1);
  insert(head, 0);
  insert(head, 1);

  simulate(head);

  Cell *current = head;
  while (current) {
    printf("%d ", current->state);
    current = current->next;
  }

  printf("\n");

  return 0;
}