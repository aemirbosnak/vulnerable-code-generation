//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100  // grid size
#define P 0.5 // probability of a site being open

// Function to generate a random grid of open and closed sites
int **generateGrid() {
  int **grid = malloc(N * sizeof(int *));
  for (int i = 0; i < N; i++) {
    grid[i] = malloc(N * sizeof(int));
    for (int j = 0; j < N; j++) {
      grid[i][j] = (rand() < P * RAND_MAX) ? 1 : 0;
    }
  }
  return grid;
}

// Function to print the grid
void printGrid(int **grid) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a site is open
int isOpen(int **grid, int i, int j) {
  if (i >= 0 && i < N && j >= 0 && j < N && grid[i][j]) {
    return 1;
  }
  return 0;
}

// Function to perform a depth-first search to find all open sites connected to a given site
void dfs(int **grid, int i, int j) {
  if (!isOpen(grid, i, j)) {
    return;
  }

  grid[i][j] = 2;  // mark the site as visited

  // Recursively call dfs on all adjacent open sites
  dfs(grid, i - 1, j);  // up
  dfs(grid, i + 1, j);  // down
  dfs(grid, i, j - 1);  // left
  dfs(grid, i, j + 1);  // right
}

// Function to count the number of clusters of open sites
int countClusters(int **grid) {
  int count = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (isOpen(grid, i, j) && grid[i][j] != 2) {
        dfs(grid, i, j);
        count++;
      }
    }
  }
  return count;
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random grid
  int **grid = generateGrid();

  // Print the grid
  printf("Original grid:\n");
  printGrid(grid);

  // Perform a depth-first search to find all open sites connected to the top row
  for (int i = 0; i < N; i++) {
    if (isOpen(grid, 0, i)) {
      dfs(grid, 0, i);
    }
  }

  // Print the grid after the depth-first search
  printf("\nGrid after depth-first search:\n");
  printGrid(grid);

  // Count the number of clusters of open sites
  int numClusters = countClusters(grid);

  // Print the number of clusters
  printf("\nNumber of clusters: %d\n", numClusters);

  // Free the grid
  for (int i = 0; i < N; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}