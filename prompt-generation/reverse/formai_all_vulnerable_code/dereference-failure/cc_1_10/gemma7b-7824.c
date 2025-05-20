//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 100

void draw_cells(int **cells, int size) {
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      if (cells[r][c] == 1) {
        printf("O ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
}

int main() {
  int **cells = (int **)malloc(MAX_CELLS * sizeof(int *));
  for (int i = 0; i < MAX_CELLS; i++) {
    cells[i] = (int *)malloc(MAX_CELLS * sizeof(int));
  }

  // Initial cell setup
  cells[10][10] = 1;
  cells[10][11] = 1;
  cells[10][12] = 1;
  cells[11][10] = 1;
  cells[11][11] = 1;
  cells[11][12] = 1;

  // Game of Life simulation
  for (int generation = 0; generation < 10; generation++) {
    draw_cells(cells, MAX_CELLS);

    // Calculate next generation
    for (int r = 0; r < MAX_CELLS; r++) {
      for (int c = 0; c < MAX_CELLS; c++) {
        int neighbors = 0;
        if (cells[r - 1][c] == 1) neighbors++;
        if (cells[r + 1][c] == 1) neighbors++;
        if (cells[r][c - 1] == 1) neighbors++;
        if (cells[r][c + 1] == 1) neighbors++;

        if (cells[r][c] == 1) {
          if (neighbors < 2 || neighbors > 3) cells[r][c] = 0;
        } else {
          if (neighbors == 3) cells[r][c] = 1;
        }
      }
    }
  }

  draw_cells(cells, MAX_CELLS);

  free(cells);

  return 0;
}