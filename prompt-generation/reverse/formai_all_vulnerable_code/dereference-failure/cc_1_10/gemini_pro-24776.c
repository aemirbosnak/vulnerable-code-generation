//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid size
#define N 10

// Probability of a cell being open
#define P 0.5

// Function to generate a random grid
int** generate_grid() {
  int** grid = malloc(N * sizeof(int*));
  for (int i = 0; i < N; i++) {
    grid[i] = malloc(N * sizeof(int));
    for (int j = 0; j < N; j++) {
      grid[i][j] = (rand() < RAND_MAX * P) ? 1 : 0;
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

// Function to check if a cell is open
int is_open(int** grid, int i, int j) {
  return grid[i][j] == 1;
}

// Function to check if a cell is on the top row
int is_top_row(int i) {
  return i == 0;
}

// Function to check if a cell is on the bottom row
int is_bottom_row(int i) {
  return i == N - 1;
}

// Function to check if a cell is on the left edge
int is_left_edge(int j) {
  return j == 0;
}

// Function to check if a cell is on the right edge
int is_right_edge(int j) {
  return j == N - 1;
}

// Function to check if a cell is on the edge
int is_edge(int i, int j) {
  return is_top_row(i) || is_bottom_row(i) || is_left_edge(j) || is_right_edge(j);
}

// Function to check if a cell is percolated
int is_percolated(int** grid, int i, int j) {
  // Check if the cell is on the top row
  if (is_top_row(i)) {
    return is_open(grid, i, j);
  }

  // Check if the cell is on the bottom row
  if (is_bottom_row(i)) {
    return is_open(grid, i, j);
  }

  // Check if the cell is on the left edge
  if (is_left_edge(j)) {
    return is_open(grid, i, j) && is_percolated(grid, i, j + 1);
  }

  // Check if the cell is on the right edge
  if (is_right_edge(j)) {
    return is_open(grid, i, j) && is_percolated(grid, i, j - 1);
  }

  // Check if the cell is on the edge
  if (is_edge(i, j)) {
    return is_open(grid, i, j) && is_percolated(grid, i, j + 1) && is_percolated(grid, i, j - 1);
  }

  // Check if the cell is not on the edge
  return is_open(grid, i, j) && is_percolated(grid, i - 1, j) && is_percolated(grid, i + 1, j);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random grid
  int** grid = generate_grid();

  // Print the grid
  printf("Initial grid:\n");
  print_grid(grid);

  // Check if the grid percolates
  int percolates = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (is_percolated(grid, i, j)) {
        percolates = 1;
        break;
      }
    }
  }

  // Print the result
  if (percolates) {
    printf("The grid percolates!\n");
  } else {
    printf("The grid does not percolate.\n");
  }

  // Free the grid
  for (int i = 0; i < N; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}