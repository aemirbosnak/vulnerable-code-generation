//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Claude Shannon
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 100

typedef struct Cell {
  int state;
  struct Cell* neighbors;
} Cell;

void initialize_game(Cell** cells) {
  for (int i = 0; i < MAX_CELLS; i++) {
    cells[i] = malloc(sizeof(Cell));
    cells[i]->state = 0;
    cells[i]->neighbors = NULL;
  }
}

void update_cells(Cell* cell) {
  int num_alive_neighbors = 0;
  for (Cell* neighbor = cell->neighbors; neighbor; neighbor = neighbor->neighbors) {
    if (neighbor->state == 1) {
      num_alive_neighbors++;
    }
  }

  if (cell->state == 1 && num_alive_neighbors < 2) {
    cell->state = 0;
  } else if (cell->state == 0 && num_alive_neighbors == 3) {
    cell->state = 1;
  }
}

int main() {
  srand(time(NULL));

  Cell** cells = NULL;
  initialize_game(&cells);

  for (int t = 0; t < 10; t++) {
    for (int i = 0; i < MAX_CELLS; i++) {
      update_cells(cells[i]);
    }

    for (int i = 0; i < MAX_CELLS; i++) {
      if (cells[i]->state == 1) {
        printf("%d ", cells[i]->state);
      } else {
        printf(" .");
      }
    }

    printf("\n");
  }

  return 0;
}