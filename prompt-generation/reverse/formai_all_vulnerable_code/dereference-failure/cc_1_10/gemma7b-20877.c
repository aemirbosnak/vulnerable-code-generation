//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 1000

typedef struct Cell {
  int alive;
  struct Cell* north;
  struct Cell* south;
  struct Cell* east;
  struct Cell* west;
} Cell;

void create_game_of_life(Cell** cells, int size) {
  for (int i = 0; i < size; i++) {
    cells[i] = malloc(sizeof(Cell));
    cells[i]->alive = 0;
    cells[i]->north = NULL;
    cells[i]->south = NULL;
    cells[i]->east = NULL;
    cells[i]->west = NULL;
  }
}

void simulate_game_of_life(Cell** cells, int size) {
  for (int i = 0; i < size; i++) {
    int neighbors = 0;
    if (cells[i]->north) neighbors++;
    if (cells[i]->south) neighbors++;
    if (cells[i]->east) neighbors++;
    if (cells[i]->west) neighbors++;

    if (cells[i]->alive && neighbors < 2) cells[i]->alive = 0;
    if (!cells[i]->alive && neighbors == 3) cells[i]->alive = 1;
  }
}

int main() {
  srand(time(NULL));

  int size = MAX_CELLS;
  Cell** cells = NULL;
  create_game_of_life(&cells, size);

  for (int t = 0; t < 10; t++) {
    simulate_game_of_life(cells, size);
  }

  return 0;
}