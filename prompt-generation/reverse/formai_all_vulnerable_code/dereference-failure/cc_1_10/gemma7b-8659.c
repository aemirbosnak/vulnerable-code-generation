//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: immersive
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 60

#define EMPTY 0
#define FULL 1
#define BLOCK 2

typedef struct PercolationGrid {
  int **grid;
  int size;
} PercolationGrid;

PercolationGrid *createGrid(int size) {
  PercolationGrid *grid = malloc(sizeof(PercolationGrid));
  grid->size = size;
  grid->grid = malloc(size * size * sizeof(int));
  for (int i = 0; i < size * size; i++) {
    grid->grid[i] = EMPTY;
  }
  return grid;
}

void simulatePercolation(PercolationGrid *grid) {
  int x, y;
  srand(time(NULL));
  for (int i = 0; i < grid->size * grid->size; i++) {
    x = rand() % grid->size;
    y = rand() % grid->size;
    if (grid->grid[x * grid->size + y] == EMPTY) {
      grid->grid[x * grid->size + y] = FULL;
    }
  }
}

void printGrid(PercolationGrid *grid) {
  for (int i = 0; i < grid->size; i++) {
    for (int j = 0; j < grid->size; j++) {
      printf("%d ", grid->grid[i * grid->size + j]);
    }
    printf("\n");
  }
}

int main() {
  PercolationGrid *grid = createGrid(WIDTH);
  simulatePercolation(grid);
  printGrid(grid);
  free(grid);
  return 0;
}