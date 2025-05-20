//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: careful
#include <stdlib.h>
#include <stdio.h>

#define MAX_CELLS 10

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

void print_cells(Cell* head) {
  while (head) {
    printf("%d ", head->state);
    head = head->next;
  }
  printf("\n");
}

void game_of_life(Cell** head) {
  Cell* current = *head;
  Cell* next = NULL;

  while (current) {
    int neighbors = 0;

    next = current->next;
    while (next) {
      if (next->state == 1) {
        neighbors++;
      }
      next = next->next;
    }

    switch (current->state) {
      case 0:
        if (neighbors == 3) {
          insert(head, 1);
        }
        break;
      case 1:
        if (neighbors < 2 || neighbors > 3) {
          insert(head, 0);
        }
        break;
    }

    current = current->next;
  }
}

int main() {
  Cell* head = NULL;
  initialize(&head);

  insert(head, 1);
  insert(head, 0);
  insert(head, 1);
  insert(head, 0);

  game_of_life(&head);

  print_cells(head);

  return 0;
}