//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 20

typedef struct Cell {
  int x;
  int y;
  int state;
} Cell;

void initialize_game(Cell *cells) {
  for (int i = 0; i < MAX_CELLS; i++) {
    cells[i].x = -1;
    cells[i].y = -1;
    cells[i].state = 0;
  }
}

void update_cells(Cell *cells) {
  for (int i = 0; i < MAX_CELLS; i++) {
    int neighbors = 0;
    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        if (cells[i].x + dx >= 0 && cells[i].x + dx < MAX_CELLS && cells[i].y + dy >= 0 && cells[i].y + dy < MAX_CELLS) {
          if (cells[i].state == 1 && cells[i].x + dx == cells[i].x && cells[i].y + dy == cells[i].y) {
            neighbors++;
          }
        }
      }
    }
    switch (neighbors) {
      case 2:
        cells[i].state = 0;
        break;
      case 3:
        cells[i].state = 1;
        break;
      default:
        break;
    }
  }
}

int main() {
  srand(time(NULL));
  Cell *cells = (Cell *)malloc(MAX_CELLS * sizeof(Cell));
  initialize_game(cells);

  for (int t = 0; t < 10; t++) {
    update_cells(cells);
  }

  for (int i = 0; i < MAX_CELLS; i++) {
    if (cells[i].state == 1) {
      printf("Cell at (%d, %d) is alive\n", cells[i].x, cells[i].y);
    }
  }

  free(cells);

  return 0;
}