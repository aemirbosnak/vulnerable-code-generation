//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 20

void simulatePercolation(int **map) {
  for (int r = 0; r < MAP_SIZE; r++) {
    for (int c = 0; c < MAP_SIZE; c++) {
      int neighbors = 0;
      if (map[r - 1][c] == 1) neighbors++;
      if (map[r + 1][c] == 1) neighbors++;
      if (map[r][c - 1] == 1) neighbors++;
      if (map[r][c + 1] == 1) neighbors++;

      if (neighbors > 0) map[r][c] = 1;
    }
  }
}

int main() {
  int **map = NULL;
  map = (int **)malloc(MAP_SIZE * sizeof(int *));
  for (int r = 0; r < MAP_SIZE; r++) {
    map[r] = (int *)malloc(MAP_SIZE * sizeof(int));
  }

  for (int r = 0; r < MAP_SIZE; r++) {
    for (int c = 0; c < MAP_SIZE; c++) {
      map[r][c] = 0;
    }
  }

  map[10][10] = 1;
  map[10][11] = 1;
  map[11][10] = 1;
  map[11][11] = 1;

  simulatePercolation(map);

  for (int r = 0; r < MAP_SIZE; r++) {
    for (int c = 0; c < MAP_SIZE; c++) {
      printf("%d ", map[r][c]);
    }
    printf("\n");
  }

  free(map);

  return 0;
}