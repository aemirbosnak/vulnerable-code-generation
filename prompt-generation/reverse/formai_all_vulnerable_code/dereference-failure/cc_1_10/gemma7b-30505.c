//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

typedef struct Cell {
  int state;
  struct Cell* north;
  struct Cell* south;
  struct Cell* east;
  struct Cell* west;
} Cell;

Cell** createGrid(int w, int h) {
  Cell** grid = (Cell**)malloc(h * sizeof(Cell*));
  for (int r = 0; r < h; r++) {
    grid[r] = (Cell*)malloc(w * sizeof(Cell));
    for (int c = 0; c < w; c++) {
      grid[r][c].state = 0;
      grid[r][c].north = NULL;
      grid[r][c].south = NULL;
      grid[r][c].east = NULL;
      grid[r][c].west = NULL;
    }
  }
  return grid;
}

void percolate(Cell** grid) {
  srand(time(NULL));
  for (int r = 0; r < HEIGHT; r++) {
    for (int c = 0; c < WIDTH; c++) {
      if (grid[r][c].state == 0) {
        int chance = rand() % 10;
        if (chance == 0) {
          grid[r][c].state = 1;
        }
      }
    }
  }
}

void displayGrid(Cell** grid) {
  for (int r = 0; r < HEIGHT; r++) {
    for (int c = 0; c < WIDTH; c++) {
      printf("%d ", grid[r][c].state);
    }
    printf("\n");
  }
}

int main() {
  Cell** grid = createGrid(WIDTH, HEIGHT);
  percolate(grid);
  displayGrid(grid);

  return 0;
}