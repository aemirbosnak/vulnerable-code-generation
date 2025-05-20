//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIM_SIZE 256

// Percolation simulation parameters
int num_steps = 1000;
int seed = 1234;
int min_perc_size = 10;

// Grid structure
int **grid;

void initialize_grid() {
  grid = malloc(MAX_SIM_SIZE * sizeof(int *));
  for (int i = 0; i < MAX_SIM_SIZE; i++) {
    grid[i] = malloc(MAX_SIM_SIZE * sizeof(int));
  }
  for (int i = 0; i < MAX_SIM_SIZE; i++) {
    for (int j = 0; j < MAX_SIM_SIZE; j++) {
      grid[i][j] = 0;
    }
  }
}

void randomize_grid() {
  srand(seed);
  for (int i = 0; i < MAX_SIM_SIZE; i++) {
    for (int j = 0; j < MAX_SIM_SIZE; j++) {
      grid[i][j] = rand() % 2;
    }
  }
}

void simulate_percolation() {
  for (int step = 0; step < num_steps; step++) {
    for (int i = 0; i < MAX_SIM_SIZE; i++) {
      for (int j = 0; j < MAX_SIM_SIZE; j++) {
        if (grid[i][j] == 1 && (grid[i-1][j] == 1 || grid[i+1][j] == 1 || grid[i][j-1] == 1 || grid[i][j+1] == 1)) {
          grid[i][j] = 2;
        }
      }
    }
  }
}

void print_grid() {
  for (int i = 0; i < MAX_SIM_SIZE; i++) {
    for (int j = 0; j < MAX_SIM_SIZE; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

int main() {
  initialize_grid();
  randomize_grid();
  simulate_percolation();
  print_grid();

  return 0;
}