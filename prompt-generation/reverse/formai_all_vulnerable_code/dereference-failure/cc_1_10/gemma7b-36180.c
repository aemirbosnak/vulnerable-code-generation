//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct Cell {
  int x, y;
  int state;
} Cell;

void init_game(Cell **grid) {
  for (int x = 0; x < WIDTH; x++) {
    for (int y = 0; y < HEIGHT; y++) {
      grid[x][y].x = x;
      grid[x][y].y = y;
      grid[x][y].state = 0;
    }
  }
}

void update_game(Cell **grid) {
  for (int x = 0; x < WIDTH; x++) {
    for (int y = 0; y < HEIGHT; y++) {
      int neighbors = 0;
      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          if (x + dx >= 0 && x + dx < WIDTH && y + dy >= 0 && y + dy < HEIGHT) {
            if (grid[x + dx][y + dy].state == 1) {
              neighbors++;
            }
          }
        }
      }
      if (neighbors < 2) {
        grid[x][y].state = 0;
      } else if (neighbors == 2) {
        grid[x][y].state = 1;
      }
    }
  }
}

int main() {
  srand(time(NULL));

  Cell **grid = (Cell **)malloc(WIDTH * HEIGHT * sizeof(Cell));
  init_game(grid);

  for (int i = 0; i < 10; i++) {
    update_game(grid);
  }

  for (int x = 0; x < WIDTH; x++) {
    for (int y = 0; y < HEIGHT; y++) {
      printf("%d ", grid[x][y].state);
    }
    printf("\n");
  }

  free(grid);

  return 0;
}