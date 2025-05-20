//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Size of the grid
#define N 100

// Probability of each cell being open
#define P 0.5

// Number of simulations to run
#define NUM_SIMS 1000

// Function to generate a random grid
int** generate_grid() {
  int** grid = malloc(N * sizeof(int*));
  for (int i = 0; i < N; i++) {
    grid[i] = malloc(N * sizeof(int));
    for (int j = 0; j < N; j++) {
      grid[i][j] = (rand() < P * RAND_MAX);
    }
  }
  return grid;
}

// Function to check if a cell is open
int is_open(int** grid, int i, int j) {
  return grid[i][j] == 1;
}

// Function to check if a cell is part of the percolating cluster
int is_percolating(int** grid, int i, int j) {
  if (!is_open(grid, i, j)) {
    return 0;
  }

  // Check if the cell is part of a percolating cluster in the north, south, east, or west direction
  if (i > 0 && is_percolating(grid, i - 1, j)) {
    return 1;
  }
  if (i < N - 1 && is_percolating(grid, i + 1, j)) {
    return 1;
  }
  if (j > 0 && is_percolating(grid, i, j - 1)) {
    return 1;
  }
  if (j < N - 1 && is_percolating(grid, i, j + 1)) {
    return 1;
  }

  // If the cell is not part of a percolating cluster in any of the four directions, then it is not part of the percolating cluster
  return 0;
}

// Function to run a single simulation
int run_simulation(int** grid) {
  // Check if the grid percolates
  int percolates = 0;
  for (int i = 0; i < N; i++) {
    if (is_percolating(grid, i, 0)) {
      percolates = 1;
      break;
    }
  }

  // Free the grid
  for (int i = 0; i < N; i++) {
    free(grid[i]);
  }
  free(grid);

  return percolates;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Run the simulations
  int num_percolates = 0;
  for (int i = 0; i < NUM_SIMS; i++) {
    int** grid = generate_grid();
    num_percolates += run_simulation(grid);
  }

  // Print the results
  double percolation_probability = (double)num_percolates / NUM_SIMS;
  printf("Percolation probability: %.4f\n", percolation_probability);

  return 0;
}