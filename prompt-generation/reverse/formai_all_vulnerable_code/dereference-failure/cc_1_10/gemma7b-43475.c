//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: lively
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int main() {
  int **grid = NULL;
  int seed = time(NULL);
  int x, y, dx, dy, i, j;

  grid = (int **)malloc(HEIGHT * sizeof(int *));
  for (i = 0; i < HEIGHT; i++) {
    grid[i] = (int *)malloc(WIDTH * sizeof(int));
  }

  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      grid[i][j] = rand() % 2;
    }
  }

  printf("Percolation Simulation\n");
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  printf("Number of Percolation Sites: %d\n",
    percolation(grid, WIDTH, HEIGHT));

  for (i = 0; i < HEIGHT; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}

int percolation(int **grid, int w, int h) {
  int i, j, dx, dy, count = 0;

  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      if (grid[i][j] == 1) {
        count++;
        dx = 1;
        dy = 0;
        while (grid[i + dx][j] == 1) {
          grid[i + dx][j] = 2;
          dx++;
        }
        dy = 1;
        while (grid[i][j + dy] == 1) {
          grid[i][j + dy] = 2;
          dy++;
        }
      }
    }
  }

  return count;
}