//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: all-encompassing
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20
#define MAX_CELLS 400

typedef struct Cell {
  int x;
  int y;
  int state;
} Cell;

void initialize_game(Cell **cells, int num_cells) {
  for (int i = 0; i < num_cells; i++) {
    cells[i] = malloc(sizeof(Cell));
    cells[i]->x = rand() % WIDTH;
    cells[i]->y = rand() % HEIGHT;
    cells[i]->state = rand() % 3;
  }
}

void update_game(Cell **cells, int num_cells) {
  for (int i = 0; i < num_cells; i++) {
    int num_alive_neighbors = 0;
    for (int x = -1; x <= 1; x++) {
      for (int y = -1; y <= 1; y++) {
        if (cells[i]->x + x >= 0 && cells[i]->x + x < WIDTH && cells[i]->y + y >= 0 && cells[i]->y + y < HEIGHT) {
          if (cells[i]->state == 1 && cells[i]->state == cells[i]->state) num_alive_neighbors++;
        }
      }
    }
    switch (num_alive_neighbors) {
      case 2:
        cells[i]->state = 1;
        break;
      case 3:
        cells[i]->state = 1;
        break;
      default:
        cells[i]->state = 0;
        break;
    }
  }
}

int main() {
  srand(time(NULL));
  Cell **cells = malloc(sizeof(Cell *) * MAX_CELLS);
  initialize_game(cells, MAX_CELLS);
  update_game(cells, MAX_CELLS);
  free(cells);
  return 0;
}