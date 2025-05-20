//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 100

typedef struct Cell {
  int alive;
  struct Cell* next;
} Cell;

void init_game(Cell** head) {
  *head = NULL;
  for (int i = 0; i < MAX_CELLS; i++) {
    *head = malloc(sizeof(Cell));
    (*head)->alive = 0;
    (*head)->next = NULL;
    head = &((*head)->next);
  }
}

void play_game(Cell* head) {
  int alive_cells = 0;
  for (Cell* cell = head; cell; cell = cell->next) {
    int num_alive_neighbors = 0;
    for (Cell* neighbor = cell->next; neighbor; neighbor = neighbor->next) {
      if (neighbor->alive) {
        num_alive_neighbors++;
      }
    }

    if (cell->alive && (num_alive_neighbors < 2 || num_alive_neighbors > 3)) {
      cell->alive = 0;
    } else if (!cell->alive && num_alive_neighbors == 3) {
      cell->alive = 1;
    }
    alive_cells++;
  }

  printf("Number of alive cells: %d\n", alive_cells);
}

int main() {
  Cell* head = NULL;
  init_game(&head);

  // Randomly set some cells to alive
  for (int i = 0; i < MAX_CELLS; i++) {
    if (rand() % 2 == 0) {
      head->alive = 1;
    }
    head = head->next;
  }

  play_game(head);

  return 0;
}