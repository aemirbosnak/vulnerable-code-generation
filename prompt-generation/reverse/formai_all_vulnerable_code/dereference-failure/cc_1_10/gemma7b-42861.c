//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 20

typedef struct Cell {
  int state;
  struct Cell* next;
} Cell;

void initialize_game(Cell** head) {
  *head = NULL;
  for (int i = 0; i < MAX_CELLS; i++) {
    *head = malloc(sizeof(Cell));
    ((*head)->state = rand() % 2);
    ((*head)->next = NULL);
    head = &((*head)->next);
  }
}

void play_game(Cell* head) {
  for (int i = 0; head; i++) {
    int alive_neighbors = 0;
    Cell* current = head;
    while (current) {
      if (current == head) {
        break;
      }
      if (current->state == 1) {
        alive_neighbors++;
      }
      current = current->next;
    }

    switch (alive_neighbors) {
      case 2:
        head->state = 1;
        break;
      case 3:
        head->state = 1;
        break;
      default:
        head->state = 0;
        break;
    }
    head = head->next;
  }
}

int main() {
  Cell* head = NULL;
  initialize_game(&head);
  play_game(head);

  return 0;
}