//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

// Define the number of players
#define NUM_PLAYERS 2

// Define the grid size
#define GRID_SIZE 5

// Define the cell state
#define ALIVE 1
#define DEAD 0

// Define the game rules
void game_rules(int **grid, int num_players) {
  for (int r = 0; r < GRID_SIZE; r++) {
    for (int c = 0; c < GRID_SIZE; c++) {
      int num_alive = 0;
      // Check the four neighboring cells
      if (grid[r-1][c] == ALIVE) num_alive++;
      if (grid[r+1][c] == ALIVE) num_alive++;
      if (grid[r][c-1] == ALIVE) num_alive++;
      if (grid[r][c+1] == ALIVE) num_alive++;

      // If the cell is alive and has fewer than two alive neighbors, it dies
      if (grid[r][c] == ALIVE && num_alive < 2) grid[r][c] = DEAD;

      // If the cell is dead and has exactly two alive neighbors, it becomes alive
      if (grid[r][c] == DEAD && num_alive == 2) grid[r][c] = ALIVE;
    }
  }
}

int main() {
  // Create the grid
  int **grid = (int **)malloc(GRID_SIZE * sizeof(int *));
  for (int r = 0; r < GRID_SIZE; r++) {
    grid[r] = (int *)malloc(GRID_SIZE * sizeof(int));
  }

  // Initialize the grid
  for (int r = 0; r < GRID_SIZE; r++) {
    for (int c = 0; c < GRID_SIZE; c++) {
      grid[r][c] = DEAD;
    }
  }

  // Set up the players
  grid[1][1] = ALIVE;
  grid[2][2] = ALIVE;

  // Play the game
  game_rules(grid, NUM_PLAYERS);

  // Print the final grid
  for (int r = 0; r < GRID_SIZE; r++) {
    for (int c = 0; c < GRID_SIZE; c++) {
      printf("%d ", grid[r][c]);
    }
    printf("\n");
  }

  // Free the memory
  for (int r = 0; r < GRID_SIZE; r++) {
    free(grid[r]);
  }
  free(grid);

  return 0;
}