//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 100

typedef struct Cell {
  int x, y;
  int state;
} Cell;

void initialize_cells(Cell **cells, int n) {
  for (int i = 0; i < n; i++) {
    cells[i] = malloc(sizeof(Cell));
    cells[i]->x = i % MAX_CELLS;
    cells[i]->y = i / MAX_CELLS;
    cells[i]->state = rand() % 2;
  }
}

void simulate_game_of_life(Cell **cells, int n) {
  for (int t = 0; t < 10; t++) {
    for (int i = 0; i < n; i++) {
      int neighbors = 0;
      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          if (dx == 0 && dy == 0) continue;
          int x = cells[i]->x + dx;
          int y = cells[i]->y + dy;
          if (x >= 0 && x < MAX_CELLS && y >= 0 && y < MAX_CELLS) {
            neighbors++;
          }
        }
      }
      int state_change = 0;
      if (cells[i]->state == 0 && neighbors == 3) {
        state_change = 1;
      } else if (cells[i]->state == 1 && (neighbors < 2 || neighbors > 3)) {
        state_change = -1;
      }
      cells[i]->state += state_change;
    }
  }
}

int main() {
  srand(time(NULL));
  Cell **cells = NULL;
  initialize_cells(&cells, 100);
  simulate_game_of_life(cells, 100);
  for (int i = 0; i < 100; i++) {
    printf("%d ", cells[i]->state);
  }
  printf("\n");
  return 0;
}