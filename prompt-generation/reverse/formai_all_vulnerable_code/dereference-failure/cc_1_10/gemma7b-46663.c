//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 20

void simulate_game_of_life(int **cells, int num_cells) {
  // Calculate the number of neighbors for each cell.
  for (int r = 0; r < num_cells; r++) {
    for (int c = 0; c < num_cells; c++) {
      int num_neighbors = 0;
      for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
          if (cells[r + dr][c + dc] == 1) {
            num_neighbors++;
          }
        }
      }
      cells[r][c] = num_neighbors > 3 ? 1 : 0;
    }
  }

  // Update the cells.
  for (int r = 0; r < num_cells; r++) {
    for (int c = 0; c < num_cells; c++) {
      cells[r][c] = cells[r][c] == 1 ? 0 : 1;
    }
  }
}

int main() {
  // Create a 2D array of cells.
  int **cells = (int **)malloc(MAX_CELLS * sizeof(int *));
  for (int r = 0; r < MAX_CELLS; r++) {
    cells[r] = (int *)malloc(MAX_CELLS * sizeof(int));
  }

  // Initialize the cells.
  srand(time(NULL));
  for (int r = 0; r < MAX_CELLS; r++) {
    for (int c = 0; c < MAX_CELLS; c++) {
      cells[r][c] = rand() % 2;
    }
  }

  // Simulate the game of life.
  simulate_game_of_life(cells, MAX_CELLS);

  // Print the cells.
  for (int r = 0; r < MAX_CELLS; r++) {
    for (int c = 0; c < MAX_CELLS; c++) {
      printf("%d ", cells[r][c]);
    }
    printf("\n");
  }

  // Free the memory.
  for (int r = 0; r < MAX_CELLS; r++) {
    free(cells[r]);
  }
  free(cells);

  return 0;
}