//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid size
#define N 100

// Probability of a site being open
#define P 0.5

// Number of simulations
#define M 1000

// Function to generate a random grid
int **generate_grid() {
  int **grid = malloc(N * sizeof(int *));
  for (int i = 0; i < N; i++) {
    grid[i] = malloc(N * sizeof(int));
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      grid[i][j] = (rand() < P * RAND_MAX);
    }
  }

  return grid;
}

// Function to check if a site is open
int is_open(int **grid, int i, int j) {
  return grid[i][j];
}

// Function to check if a site is percolating
int is_percolating(int **grid) {
  // Check if the top row is open
  for (int i = 0; i < N; i++) {
    if (is_open(grid, i, 0)) {
      // Check if the bottom row is open
      for (int j = 0; j < N; j++) {
        if (is_open(grid, j, N - 1)) {
          return 1;
        }
      }
    }
  }

  return 0;
}

// Function to run a simulation
int run_simulation() {
  int **grid = generate_grid();
  int percolating = is_percolating(grid);
  free(grid);
  return percolating;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Run the simulations
  int num_percolating = 0;
  for (int i = 0; i < M; i++) {
    num_percolating += run_simulation();
  }

  // Print the results
  printf("Number of percolating simulations: %d\n", num_percolating);
  printf("Probability of percolation: %f\n", (double)num_percolating / M);

  return 0;
}