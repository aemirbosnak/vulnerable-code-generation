//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20

void initializeGrid(int **grid, int size) {
  grid = malloc(size * sizeof(int *));
  for (int i = 0; i < size; i++) {
    grid[i] = malloc(size * sizeof(int));
    for (int j = 0; j < size; j++) {
      grid[i][j] = 0;
    }
  }
}

void displayGrid(int **grid, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

int countNeighbors(int **grid, int x, int y) {
  int neighbors = 0;
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      if (x + dx >= 0 && x + dx < GRID_SIZE && y + dy >= 0 && y + dy < GRID_SIZE && grid[x + dx][y + dy] == 1) {
        neighbors++;
      }
    }
  }
  return neighbors;
}

void updateGrid(int **grid, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      int neighbors = countNeighbors(grid, i, j);
      if (neighbors < 2) {
        grid[i][j] = 0;
      } else if (neighbors == 2) {
        grid[i][j] = 1;
      } else if (neighbors > 3) {
        grid[i][j] = 0;
      }
    }
  }
}

int main() {
  int **grid;
  initializeGrid(grid, GRID_SIZE);

  // Seed the random number generator
  srand(time(NULL));

  // Randomly assign some cells to be alive
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      if (rand() % 2 == 0) {
        grid[i][j] = 1;
      }
    }
  }

  displayGrid(grid, GRID_SIZE);

  updateGrid(grid, GRID_SIZE);

  displayGrid(grid, GRID_SIZE);

  free(grid);

  return 0;
}