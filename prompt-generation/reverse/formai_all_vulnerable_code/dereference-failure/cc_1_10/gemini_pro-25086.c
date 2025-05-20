//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Size of the grid
#define P 0.5 // Probability of a site being open

// Function to create a random grid
int** create_grid(int n) {
  int** grid = malloc(n * sizeof(int*));
  for (int i = 0; i < n; i++) {
    grid[i] = malloc(n * sizeof(int));
    for (int j = 0; j < n; j++) {
      grid[i][j] = (rand() < RAND_MAX * P) ? 1 : 0;
    }
  }
  return grid;
}

// Function to print a grid
void print_grid(int** grid, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a site is open
int is_open(int** grid, int i, int j) {
  return grid[i][j] == 1;
}

// Function to check if a site is part of the cluster
int is_in_cluster(int** grid, int n, int i, int j, int cluster_id) {
  return grid[i][j] == cluster_id;
}

// Function to mark a site as part of the cluster
void mark_cluster(int** grid, int n, int i, int j, int cluster_id) {
  grid[i][j] = cluster_id;
}

// Function to find the cluster ID of a site
int find_cluster_id(int** grid, int n, int i, int j) {
  if (is_open(grid, i, j)) {
    if (is_in_cluster(grid, n, i - 1, j, grid[i - 1][j])) {
      return grid[i - 1][j];
    } else if (is_in_cluster(grid, n, i, j - 1, grid[i][j - 1])) {
      return grid[i][j - 1];
    } else {
      return grid[i][j];
    }
  } else {
    return 0;
  }
}

// Function to find the largest cluster in the grid
int find_largest_cluster(int** grid, int n) {
  int max_cluster_id = 0;
  int max_cluster_size = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int cluster_id = find_cluster_id(grid, n, i, j);
      if (cluster_id > 0) {
        int cluster_size = 0;
        for (int k = 0; k < n; k++) {
          for (int l = 0; l < n; l++) {
            if (is_in_cluster(grid, n, k, l, cluster_id)) {
              cluster_size++;
            }
          }
        }
        if (cluster_size > max_cluster_size) {
          max_cluster_id = cluster_id;
          max_cluster_size = cluster_size;
        }
      }
    }
  }

  return max_cluster_id;
}

// Function to main
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create a random grid
  int** grid = create_grid(N);

  // Print the grid
  printf("Grid:\n");
  print_grid(grid, N);

  // Find the largest cluster in the grid
  int max_cluster_id = find_largest_cluster(grid, N);

  // Mark the largest cluster in the grid
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (is_in_cluster(grid, N, i, j, max_cluster_id)) {
        mark_cluster(grid, N, i, j, -1);
      }
    }
  }

  // Print the grid with the largest cluster marked
  printf("\nGrid with largest cluster marked:\n");
  print_grid(grid, N);

  // Free the grid
  for (int i = 0; i < N; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}