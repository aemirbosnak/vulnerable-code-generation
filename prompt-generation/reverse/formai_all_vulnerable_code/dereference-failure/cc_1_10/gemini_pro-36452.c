//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid size
#define N 10

// Probability of a site being open
#define P 0.5

// Function to generate a random grid
int** generate_grid() {
  int** grid = (int**)malloc(N * sizeof(int*));
  for (int i = 0; i < N; i++) {
    grid[i] = (int*)malloc(N * sizeof(int));
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

// Function to check if a site is open
int is_open(int** grid, int i, int j) {
  return grid[i][j] == 1;
}

// Function to check if a site is on the boundary
int is_on_boundary(int i, int j) {
  return i == 0 || i == N - 1 || j == 0 || j == N - 1;
}

// Function to perform a depth-first search
void dfs(int** grid, int i, int j) {
  // Mark the site as visited
  grid[i][j] = 2;

  // Check if the site is on the boundary
  if (is_on_boundary(i, j)) {
    // If it is, then the system percolates
    printf("The system percolates!\n");
    exit(0);
  }

  // Check if the site is open
  if (is_open(grid, i, j)) {
    // If it is, then continue the search in all four directions
    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
  }
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random grid
  int** grid = generate_grid();

  // Print the grid
  printf("Initial grid:\n");
  print_grid(grid);

  // Perform a depth-first search starting from the top-left corner
  dfs(grid, 0, 0);

  // If the system does not percolate, then print a message
  printf("The system does not percolate.\n");

  return 0;
}