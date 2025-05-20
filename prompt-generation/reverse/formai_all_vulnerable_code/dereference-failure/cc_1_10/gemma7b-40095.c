//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: visionary
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct Cell {
  int x;
  int y;
  int state;
} Cell;

Cell** createGrid(int w, int h) {
  Cell** grid = (Cell**)malloc(h * sizeof(Cell*));
  for (int i = 0; i < h; i++) {
    grid[i] = (Cell*)malloc(w * sizeof(Cell));
    for (int j = 0; j < w; j++) {
      grid[i][j].x = i;
      grid[i][j].y = j;
      grid[i][j].state = 0;
    }
  }
  return grid;
}

void simulate(Cell** grid) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      int neighbors = 0;
      // Check neighbors
      for (int r = -1; r <= 1; r++) {
        for (int c = -1; c <= 1; c++) {
          if (grid[i + r][j + c].state == 1) {
            neighbors++;
          }
        }
      }

      // Apply rules
      if (neighbors < 2) {
        grid[i][j].state = 0;
      } else if (neighbors == 2) {
        grid[i][j].state = 1;
      } else if (neighbors > 2) {
        grid[i][j].state = 0;
      }
    }
  }
}

int main() {
  srand(time(NULL));

  Cell** grid = createGrid(WIDTH, HEIGHT);

  // Initialize the grid
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      grid[i][j].state = rand() % 2;
    }
  }

  // Simulate
  simulate(grid);

  // Print the grid
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%d ", grid[i][j].state);
    }
    printf("\n");
  }

  return 0;
}