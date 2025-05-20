//Code Llama-13B DATASET v1.0 Category: Game of Life ; Style: light-weight
/*
 * Game of Life
 *
 * Usage: ./game_of_life <grid_size> <num_generations>
 *
 * This program simulates the Game of Life, a cellular automaton created by John Conway.
 * The game is played on a grid of cells, where each cell can be either alive or dead.
 * At each generation, the following rules apply:
 * 1. Any live cell with two or three live neighbors survives.
 * 2. Any dead cell with three live neighbors becomes alive.
 * 3. All other live cells die in the next generation.
 * All dead cells stay dead.
 *
 * The program takes two command-line arguments:
 * 1. <grid_size>: the size of the grid, specified as a positive integer
 * 2. <num_generations>: the number of generations to simulate, specified as a positive integer
 *
 * The program outputs the state of the grid at each generation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 100
#define NUM_GENERATIONS 100

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: ./game_of_life <grid_size> <num_generations>\n");
    return 1;
  }

  int grid_size = atoi(argv[1]);
  int num_generations = atoi(argv[2]);

  // Initialize the grid with a random starting state
  int grid[GRID_SIZE][GRID_SIZE];
  srand(time(NULL));
  for (int i = 0; i < grid_size; i++) {
    for (int j = 0; j < grid_size; j++) {
      grid[i][j] = rand() % 2;
    }
  }

  // Simulate the Game of Life for the specified number of generations
  for (int i = 0; i < num_generations; i++) {
    // Update the grid based on the Game of Life rules
    for (int i = 0; i < grid_size; i++) {
      for (int j = 0; j < grid_size; j++) {
        int num_live_neighbors = 0;
        for (int k = -1; k <= 1; k++) {
          for (int l = -1; l <= 1; l++) {
            if (i + k >= 0 && i + k < grid_size && j + l >= 0 && j + l < grid_size) {
              num_live_neighbors += grid[i + k][j + l];
            }
          }
        }
        if (grid[i][j] == 0 && num_live_neighbors == 3) {
          grid[i][j] = 1;
        } else if (grid[i][j] == 1 && (num_live_neighbors < 2 || num_live_neighbors > 3)) {
          grid[i][j] = 0;
        }
      }
    }

    // Print the current state of the grid
    printf("Generation %d:\n", i + 1);
    for (int i = 0; i < grid_size; i++) {
      for (int j = 0; j < grid_size; j++) {
        printf("%c ", grid[i][j] == 1 ? '*' : ' ');
      }
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}