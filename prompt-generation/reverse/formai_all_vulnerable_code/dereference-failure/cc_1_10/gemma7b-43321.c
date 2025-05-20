//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 20

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

void update_game(Cell* cell) {
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

void play_game(Cell** cells) {
  time_t start_time = time(NULL);
  for (int generation = 0; generation < 10; generation++) {
    for (int i = 0; i < MAX_CELLS; i++) {
      update_game(cells[i]);
    }

    printf("Generation %d:\n", generation);
    for (int i = 0; i < MAX_CELLS; i++) {
      if (cells[i]->state == 1) {
        printf("%c ", 'O');
      } else {
        printf("%c ", '.');
      }
    }

    printf("\n");
  }

  time_t end_time = time(NULL);
  printf("Time taken: %.2f seconds\n", (double)(end_time - start_time));
}

int main() {
  Cell** cells = NULL;
  initialize_game(&cells);

  play_game(cells);

  return 0;
}