//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 10

typedef struct Cell {
  int alive;
  struct Cell* next;
} Cell;

void initialize(Cell** head) {
  *head = NULL;
}

void insert(Cell** head, int value) {
  Cell* new_cell = malloc(sizeof(Cell));
  new_cell->alive = value;
  new_cell->next = NULL;

  if (*head == NULL) {
    *head = new_cell;
  } else {
    (*head)->next = new_cell;
  }
}

void print_cells(Cell* head) {
  while (head) {
    printf("%d ", head->alive);
    head = head->next;
  }
  printf("\n");
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
    } else if (current->alive && neighbors > 3) {
      current->alive = 0;
    } else if (!current->alive && neighbors == 3) {
      current->alive = 1;
    }
    current = current->next;
  }
}

int main() {
  Cell* head = NULL;
  initialize(&head);

  insert(head, 1);
  insert(head, 1);
  insert(head, 1);
  insert(head, 0);
  insert(head, 1);
  insert(head, 0);

  print_cells(head);
  update(head);
  print_cells(head);

  return 0;
}