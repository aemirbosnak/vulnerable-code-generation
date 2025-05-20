//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 100

typedef struct Cell {
  int x;
  int y;
  int state;
} Cell;

void init_cells(Cell **cells) {
  for (int i = 0; i < MAX_CELLS; i++) {
    cells[i] = malloc(sizeof(Cell));
    cells[i]->x = i % MAX_CELLS;
    cells[i]->y = i / MAX_CELLS;
    cells[i]->state = rand() % 2;
  }
}

void print_cells(Cell **cells) {
  for (int i = 0; i < MAX_CELLS; i++) {
    printf("%d ", cells[i]->state);
  }
  printf("\n");
}

int main() {
  srand(time(NULL));

  Cell **cells = (Cell **)malloc(MAX_CELLS * sizeof(Cell));

  init_cells(cells);
  print_cells(cells);

  for (int t = 0; t < 10; t++) {
    // Game of Life logic here
    for (int i = 0; i < MAX_CELLS; i++) {
      int neighbors = 0;
      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          if (cells[i]->x + dx >= 0 && cells[i]->x + dx < MAX_CELLS && cells[i]->y + dy >= 0 && cells[i]->y + dy < MAX_CELLS) {
            neighbors++;
          }
        }
      }

      if (cells[i]->state == 0 && neighbors == 3) {
        cells[i]->state = 1;
      } else if (cells[i]->state == 1 && (neighbors < 2 || neighbors > 3)) {
        cells[i]->state = 0;
      }
    }

    print_cells(cells);
  }

  free(cells);

  return 0;
}