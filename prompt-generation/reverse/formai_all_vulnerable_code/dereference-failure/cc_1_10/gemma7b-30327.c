//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct Cell {
  int x;
  int y;
  int state;
} Cell;

void initGame(Cell **grid) {
  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      grid[i][j].x = i;
      grid[i][j].y = j;
      grid[i][j].state = 0;
    }
  }
}

void printGrid(Cell **grid) {
  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      printf("%d ", grid[i][j].state);
    }
    printf("\n");
  }
}

int calculateAliveNeighbors(Cell **grid, int x, int y) {
  int aliveNeighbors = 0;
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      if (x + dx >= 0 && x + dx < MAX_SIZE && y + dy >= 0 && y + dy < MAX_SIZE) {
        if (grid[x + dx][y + dy].state == 1) {
          aliveNeighbors++;
        }
      }
    }
  }
  return aliveNeighbors;
}

void updateCells(Cell **grid) {
  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      int aliveNeighbors = calculateAliveNeighbors(grid, grid[i][j].x, grid[i][j].y);
      if (aliveNeighbors < 2) {
        grid[i][j].state = 0;
      } else if (aliveNeighbors == 2) {
        grid[i][j].state = 1;
      }
    }
  }
}

int main() {
  Cell **grid = (Cell **)malloc(MAX_SIZE * MAX_SIZE * sizeof(Cell));
  initGame(grid);

  // Set some initial cells to 1
  grid[5][5].state = 1;
  grid[5][6].state = 1;
  grid[6][5].state = 1;

  printGrid(grid);

  updateCells(grid);

  printGrid(grid);

  free(grid);

  return 0;
}