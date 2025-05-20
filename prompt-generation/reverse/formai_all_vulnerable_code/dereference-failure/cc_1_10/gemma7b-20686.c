//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIM_SIZE 512

int main() {
  int sim_size = MAX_SIM_SIZE;
  int **grid = (int **)malloc(sim_size * sizeof(int *));
  for (int i = 0; i < sim_size; i++) {
    grid[i] = (int *)malloc(sim_size * sizeof(int));
  }

  int num_particles = 1000;
  int **particles = (int **)malloc(num_particles * sizeof(int *));
  for (int i = 0; i < num_particles; i++) {
    particles[i] = (int *)malloc(2 * sizeof(int));
  }

  // Initialize the grid
  for (int i = 0; i < sim_size; i++) {
    for (int j = 0; j < sim_size; j++) {
      grid[i][j] = 0;
    }
  }

  // Place the particles randomly
  for (int i = 0; i < num_particles; i++) {
    particles[i][0] = rand() % sim_size;
    particles[i][1] = rand() % sim_size;
  }

  // Simulate the percolation
  int iterations = 0;
  while (!percolation_finished(grid, particles, sim_size, num_particles)) {
    iterations++;
  }

  // Print the results
  printf("Number of iterations: %d\n", iterations);
  printf("Percolation finished.\n");

  // Free the memory
  for (int i = 0; i < sim_size; i++) {
    for (int j = 0; j < sim_size; j++) {
      free(grid[i][j]);
    }
    free(grid[i]);
  }
  free(grid);

  for (int i = 0; i < num_particles; i++) {
    free(particles[i][0]);
    free(particles[i]);
  }
  free(particles);

  return 0;
}

int percolation_finished(int **grid, int **particles, int sim_size, int num_particles) {
  for (int i = 0; i < num_particles; i++) {
    if (grid[particles[i][0]][particles[i][1]] == 1) {
      return 0;
    }
  }

  return 1;
}