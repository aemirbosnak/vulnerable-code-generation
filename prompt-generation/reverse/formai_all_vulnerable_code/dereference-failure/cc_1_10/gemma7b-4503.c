//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: sophisticated
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CELLS 100

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
  for (Cell* cell = head; cell; cell = cell->next) {
    int neighbors = 0;
    for (Cell* neighbor = head; neighbor && neighbor != cell; neighbor = neighbor->next) {
      if (neighbor->state == 1 && cell->state == 0) {
        neighbors++;
      }
    }
    switch (cell->state) {
      case 0:
        if (neighbors >= 3) {
          cell->state = 1;
        }
        break;
      case 1:
        if (neighbors < 2) {
          cell->state = 0;
        }
        break;
    }
  }
}

int main() {
  Cell* head = NULL;
  initialize_game(&head);
  simulate_game(head);
  return 0;
}