//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 10

typedef struct Cell {
  int state;
  struct Cell* next;
} Cell;

void initialize_game(Cell** head) {
  *head = NULL;
  for (int i = 0; i < MAX_CELLS; i++) {
    Cell* new_cell = malloc(sizeof(Cell));
    new_cell->state = 0;
    new_cell->next = *head;
    *head = new_cell;
  }
}

void simulate_game(Cell* head) {
  for (Cell* current = head; current; current = current->next) {
    int neighbors_alive = 0;
    for (Cell* neighbor = head; neighbor; neighbor = neighbor->next) {
      if (neighbor == current) continue;
      if (neighbor->state == 1) neighbors_alive++;
    }
    switch (neighbors_alive) {
      case 2: current->state = 1; break;
      case 3: current->state = 1; break;
      default: current->state = 0; break;
    }
  }
}

int main() {
  Cell* head = NULL;
  initialize_game(&head);

  // Set some cells to alive
  head->next->state = 1;
  head->next->next->state = 1;

  simulate_game(head);

  // Print the new cell states
  for (Cell* current = head; current; current = current->next) {
    printf("%d ", current->state);
  }

  return 0;
}