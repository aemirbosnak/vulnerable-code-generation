//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Dimensions of the grid
#define N 30

// Probability of a site being open
#define P 0.5

// Function to generate a random grid
int** generate_grid(void) {
  int** grid = (int**)malloc(N * sizeof(int*));
  for (int i = 0; i < N; i++) {
    grid[i] = (int*)malloc(N * sizeof(int));
    for (int j = 0; j < N; j++) {
      grid[i][j] = (rand() < P * RAND_MAX);
    }
  }
  return grid;
}

// Function to print a grid
void print_grid(int** grid) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a site is open
int is_open(int** grid, int i, int j) {
  return grid[i][j] == 1;
}

// Function to check if a site is on the boundary
int is_on_boundary(int i, int j) {
  return i == 0 || i == N - 1 || j == 0 || j == N - 1;
}

// Function to perform the percolation experiment
int percolate(int** grid) {
  // Create a queue of sites to visit
  int queue[N * N][2];
  int head = 0;
  int tail = 0;

  // Add the top-left site to the queue
  queue[tail][0] = 0;
  queue[tail][1] = 0;
  tail++;

  // While the queue is not empty
  while (head != tail) {
    // Remove the first site from the queue
    int i = queue[head][0];
    int j = queue[head][1];
    head++;

    // If the site is on the bottom boundary, then the system percolates
    if (i == N - 1) {
      return 1;
    }

    // If the site is not open, then continue to the next site
    if (!is_open(grid, i, j)) {
      continue;
    }

    // Add the adjacent sites to the queue
    if (i > 0 && is_open(grid, i - 1, j)) {
      queue[tail][0] = i - 1;
      queue[tail][1] = j;
      tail++;
    }
    if (i < N - 1 && is_open(grid, i + 1, j)) {
      queue[tail][0] = i + 1;
      queue[tail][1] = j;
      tail++;
    }
    if (j > 0 && is_open(grid, i, j - 1)) {
      queue[tail][0] = i;
      queue[tail][1] = j - 1;
      tail++;
    }
    if (j < N - 1 && is_open(grid, i, j + 1)) {
      queue[tail][0] = i;
      queue[tail][1] = j + 1;
      tail++;
    }
  }

  // If the queue is empty and the system has not percolated, then the system does not percolate
  return 0;
}

// Main function
int main(void) {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a grid
  int** grid = generate_grid();

  // Print the grid
  print_grid(grid);

  // Perform the percolation experiment
  int percolates = percolate(grid);

  // Print the result
  if (percolates) {
    printf("The system percolates!\n");
  } else {
    printf("The system does not percolate.\n");
  }

  // Free the grid
  for (int i = 0; i < N; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}