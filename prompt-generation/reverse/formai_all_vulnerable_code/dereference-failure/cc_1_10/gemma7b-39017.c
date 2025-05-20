//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 20

typedef struct Cell {
  int state;
  struct Cell* next;
} Cell;

void initialize_game(Cell** head) {
  *head = NULL;
  for (int i = 0; i < MAX_CELLS; i++) {
    *head = malloc(sizeof(Cell));
    (*head)->state = rand() % 2;
    (*head)->next = NULL;
    head = &((*head)->next);
  }
}

void simulate_game(Cell* head) {
  Cell* current = head;
  while (current) {
    int neighbors = 0;
    Cell* neighbor = current->next;
    while (neighbor) {
      if (neighbor->state == 1) {
        neighbors++;
      }
      neighbor = neighbor->next;
    }

    switch (current->state) {
      case 0:
        if (neighbors == 3) {
          current->state = 1;
        }
        break;
      case 1:
        if (neighbors < 2 || neighbors > 3) {
          current->state = 0;
        }
        break;
    }

    current = current->next;
  }
}

int main() {
  Cell* head = NULL;
  initialize_game(&head);
  simulate_game(head);

  return 0;
}