//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Cryptic
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

#define MAX_ITERATIONS 1000

typedef struct Cell {
  int state;
  struct Cell* up, *right, *down, *left;
} Cell;

Cell** createGrid(int w, int h) {
  Cell** grid = (Cell**)malloc(h * sizeof(Cell*) + w * sizeof(Cell));
  for (int r = 0; r < h; r++) {
    grid[r] = (Cell*)malloc(w * sizeof(Cell));
    for (int c = 0; c < w; c++) {
      grid[r][c].state = 0;
      grid[r][c].up = NULL;
      grid[r][c].right = NULL;
      grid[r][c].down = NULL;
      grid[r][c].left = NULL;
    }
  }
  return grid;
}

void percolate(Cell** grid, int x, int y) {
  if (grid[x][y].state == 1) {
    return;
  }
  grid[x][y].state = 1;
  if (x > 0) {
    percolate(grid, x - 1, y);
  }
  if (y > 0) {
    percolate(grid, x, y - 1);
  }
  if (x < WIDTH - 1) {
    percolate(grid, x + 1, y);
  }
  if (y < HEIGHT - 1) {
    percolate(grid, x, y + 1);
  }
}

int main() {
  srand(time(NULL));

  Cell** grid = createGrid(WIDTH, HEIGHT);

  for (int i = 0; i < MAX_ITERATIONS; i++) {
    int x = rand() % WIDTH;
    int y = rand() % HEIGHT;
    percolate(grid, x, y);
  }

  free(grid);

  return 0;
}