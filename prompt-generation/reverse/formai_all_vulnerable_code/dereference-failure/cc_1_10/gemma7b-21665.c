//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: puzzling
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 20

#define FILL_PROB 0.7

int main() {
  int **grid = NULL;
  int i, j, k, seed, percolate = 0, water = 0;

  seed = time(NULL);
  srand(seed);

  grid = malloc(DIM * DIM * sizeof(int));
  for (i = 0; i < DIM; i++) {
    for (j = 0; j < DIM; j++) {
      grid[i][j] = 0;
    }
  }

  for (k = 0; k < DIM * DIM; k++) {
    i = rand() % DIM;
    j = rand() % DIM;
    if (grid[i][j] == 0 && rand() % 100 < FILL_PROB) {
      grid[i][j] = 1;
    }
  }

  for (i = 0; i < DIM; i++) {
    for (j = 0; j < DIM; j++) {
      if (grid[i][j] == 1) {
        percolate++;
      }
    }
  }

  water = percolate / DIM;

  printf("Percolation Simulation:\n");
  printf("-----------------------\n");
  printf("Number of Percolating Cells: %d\n", percolate);
  printf("Water Level: %d cells\n", water);
  printf("-----------------------\n");

  free(grid);

  return 0;
}