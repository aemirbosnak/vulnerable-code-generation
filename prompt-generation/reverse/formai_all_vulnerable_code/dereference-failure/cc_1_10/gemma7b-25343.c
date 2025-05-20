//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIM_SIZE 20

int main() {
  int **percolation_array = NULL;
  int num_sims = 0;
  int sim_size = MAX_SIM_SIZE;
  int seed = time(NULL);

  percolation_array = (int **)malloc(sim_size * sizeof(int *));
  for (int i = 0; i < sim_size; i++) {
    percolation_array[i] = (int *)malloc(sim_size * sizeof(int));
  }

  // Initialize the array
  for (int i = 0; i < sim_size; i++) {
    for (int j = 0; j < sim_size; j++) {
      percolation_array[i][j] = 0;
    }
  }

  // Simulate a number of experiments
  num_sims = 1000;
  for (int n = 0; n < num_sims; n++) {
    // Randomly choose a site to activate
    int x = rand() % sim_size;
    int y = rand() % sim_size;
    percolation_array[x][y] = 1;

    // Check if the site is connected to a cluster of active sites
    if (percolation_array[x][y] == 1) {
      // If it is, then activate the site
      percolation_array[x][y] = 2;
    }
  }

  // Print the results
  for (int i = 0; i < sim_size; i++) {
    for (int j = 0; j < sim_size; j++) {
      printf("%d ", percolation_array[i][j]);
    }
    printf("\n");
  }

  // Free the memory
  for (int i = 0; i < sim_size; i++) {
    free(percolation_array[i]);
  }
  free(percolation_array);

  return 0;
}