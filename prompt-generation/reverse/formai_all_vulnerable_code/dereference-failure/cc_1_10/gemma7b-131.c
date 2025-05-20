//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct Cell {
  int x, y;
  int state;
} Cell;

Cell** createGrid(int size) {
  Cell** grid = (Cell**)malloc(size * sizeof(Cell*));
  for (int i = 0; i < size; i++) {
    grid[i] = (Cell*)malloc(size * sizeof(Cell));
    for (int j = 0; j < size; j++) {
      grid[i][j].x = i;
      grid[i][j].y = j;
      grid[i][j].state = 0;
    }
  }
  return grid;
}

void printGrid(Cell** grid) {
  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      printf("%d ", grid[i][j].state);
    }
    printf("\n");
  }
}

int getAliveNeighbours(Cell** grid, int x, int y) {
  int aliveNeighbours = 0;
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      if (x + dx >= 0 && x + dx < MAX_SIZE && y + dy >= 0 && y + dy < MAX_SIZE) {
        if (grid[x + dx][y + dy].state == 1) {
          aliveNeighbours++;
        }
      }
    }
  }
  return aliveNeighbours;
}

void updateGrid(Cell** grid) {
  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      int aliveNeighbours = getAliveNeighbours(grid, grid[i][j].x, grid[i][j].y);
      if (aliveNeighbours < 2) {
        grid[i][j].state = 0;
      } else if (aliveNeighbours == 2) {
        grid[i][j].state = 1;
      }
    }
  }
}

int main() {
  Cell** grid = createGrid(MAX_SIZE);
  grid[5][5].state = 1;
  grid[5][6].state = 1;
  grid[6][5].state = 1;
  grid[6][6].state = 1;

  printGrid(grid);

  updateGrid(grid);

  printGrid(grid);

  return 0;
}