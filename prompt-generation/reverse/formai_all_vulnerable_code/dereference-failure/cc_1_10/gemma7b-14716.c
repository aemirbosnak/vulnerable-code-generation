//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 20

typedef struct Cell {
  int state;
  struct Cell* next;
} Cell;

Cell* initialize_game_of_life(int num_cells) {
  Cell* head = NULL;
  for (int i = 0; i < num_cells; i++) {
    Cell* new_cell = malloc(sizeof(Cell));
    new_cell->state = rand() % 2;
    new_cell->next = head;
    head = new_cell;
  }
  return head;
}

void play_game_of_life(Cell* head) {
  Cell* current = head;
  while (current) {
    int num_alive_neighbors = 0;
    Cell* neighbor = current->next;
    while (neighbor) {
      if (neighbor->state == 1) {
        num_alive_neighbors++;
      }
      neighbor = neighbor->next;
    }

    switch (current->state) {
      case 0:
        if (num_alive_neighbors == 3) {
          current->state = 1;
        }
        break;
      case 1:
        if (num_alive_neighbors < 2 || num_alive_neighbors > 3) {
          current->state = 0;
        }
        break;
    }

    current = current->next;
  }
}

int main() {
  int num_cells = MAX_CELLS;
  Cell* head = initialize_game_of_life(num_cells);
  play_game_of_life(head);

  return 0;
}