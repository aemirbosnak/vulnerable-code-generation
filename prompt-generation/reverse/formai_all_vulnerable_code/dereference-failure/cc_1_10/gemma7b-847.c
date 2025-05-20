//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Cyberpunk
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define NUM_GENERATIONS 100

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

void simulatePercolation(Cell** grid, int numGenerations) {
  srand(time(NULL));
  for (int g = 0; g < numGenerations; g++) {
    for (int r = 0; r < HEIGHT; r++) {
      for (int c = 0; c < WIDTH; c++) {
        if (grid[r][c].state == 1) {
          int randNum = rand() % 4;
          switch (randNum) {
            case 0:
              if (grid[r - 1][c].state == 0) {
                grid[r - 1][c].state = 1;
              }
              break;
            case 1:
              if (grid[r + 1][c].state == 0) {
                grid[r + 1][c].state = 1;
              }
              break;
            case 2:
              if (grid[r][c - 1].state == 0) {
                grid[r][c - 1].state = 1;
              }
              break;
            case 3:
              if (grid[r][c + 1].state == 0) {
                grid[r][c + 1].state = 1;
              }
              break;
          }
        }
      }
    }
  }
}

int main() {
  Cell** grid = createGrid(WIDTH, HEIGHT);
  simulatePercolation(grid, NUM_GENERATIONS);

  // Print the final grid
  for (int r = 0; r < HEIGHT; r++) {
    for (int c = 0; c < WIDTH; c++) {
      printf("%d ", grid[r][c].state);
    }
    printf("\n");
  }

  return 0;
}