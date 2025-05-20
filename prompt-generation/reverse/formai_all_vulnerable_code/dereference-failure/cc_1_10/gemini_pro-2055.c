//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid dimensions
#define GRID_WIDTH 10
#define GRID_HEIGHT 10

// Probability of a site being open
#define P 0.5

// Function to generate a random grid
int** generate_grid() {
  // Allocate memory for the grid
  int** grid = malloc(GRID_WIDTH * sizeof(int*));
  for (int i = 0; i < GRID_WIDTH; i++) {
    grid[i] = malloc(GRID_HEIGHT * sizeof(int));
  }

  // Initialize the grid
  for (int i = 0; i < GRID_WIDTH; i++) {
    for (int j = 0; j < GRID_HEIGHT; j++) {
      grid[i][j] = (rand() < (RAND_MAX * P)) ? 1 : 0;
    }
  }

  return grid;
}

// Function to print the grid
void print_grid(int** grid) {
  for (int i = 0; i < GRID_WIDTH; i++) {
    for (int j = 0; j < GRID_HEIGHT; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a site is open
int is_open(int** grid, int x, int y) {
  return grid[x][y] == 1;
}

// Function to check if a site is part of the cluster
int is_in_cluster(int** grid, int** cluster, int x, int y) {
  return cluster[x][y] == 1;
}

// Function to add a site to the cluster
void add_to_cluster(int** grid, int** cluster, int x, int y) {
  cluster[x][y] = 1;
}

// Function to find the largest cluster
int find_largest_cluster(int** grid) {
  // Allocate memory for the cluster
  int** cluster = malloc(GRID_WIDTH * sizeof(int*));
  for (int i = 0; i < GRID_WIDTH; i++) {
    cluster[i] = malloc(GRID_HEIGHT * sizeof(int));
  }

  // Initialize the cluster
  for (int i = 0; i < GRID_WIDTH; i++) {
    for (int j = 0; j < GRID_HEIGHT; j++) {
      cluster[i][j] = 0;
    }
  }

  // Find the largest cluster
  int max_cluster_size = 0;
  for (int i = 0; i < GRID_WIDTH; i++) {
    for (int j = 0; j < GRID_HEIGHT; j++) {
      if (is_open(grid, i, j) && !is_in_cluster(grid, cluster, i, j)) {
        // Found a new cluster

        // Initialize the cluster size
        int cluster_size = 0;

        // Queue for breadth-first search
        int queue[GRID_WIDTH * GRID_HEIGHT];
        int head = 0;
        int tail = 0;

        // Add the initial site to the queue
        queue[tail++] = i * GRID_WIDTH + j;

        // While the queue is not empty
        while (head < tail) {
          // Get the next site from the queue
          int site = queue[head++];

          // Add the site to the cluster
          add_to_cluster(grid, cluster, site / GRID_WIDTH, site % GRID_HEIGHT);

          // Increment the cluster size
          cluster_size++;

          // Add the neighbors of the site to the queue
          int x = site / GRID_WIDTH;
          int y = site % GRID_HEIGHT;
          if (x > 0 && is_open(grid, x - 1, y) && !is_in_cluster(grid, cluster, x - 1, y)) {
            queue[tail++] = (x - 1) * GRID_WIDTH + y;
          }
          if (x < GRID_WIDTH - 1 && is_open(grid, x + 1, y) && !is_in_cluster(grid, cluster, x + 1, y)) {
            queue[tail++] = (x + 1) * GRID_WIDTH + y;
          }
          if (y > 0 && is_open(grid, x, y - 1) && !is_in_cluster(grid, cluster, x, y - 1)) {
            queue[tail++] = x * GRID_WIDTH + (y - 1);
          }
          if (y < GRID_HEIGHT - 1 && is_open(grid, x, y + 1) && !is_in_cluster(grid, cluster, x, y + 1)) {
            queue[tail++] = x * GRID_WIDTH + (y + 1);
          }
        }

        // Update the max cluster size
        max_cluster_size = fmax(max_cluster_size, cluster_size);
      }
    }
  }

  // Free the memory for the cluster
  for (int i = 0; i < GRID_WIDTH; i++) {
    free(cluster[i]);
  }
  free(cluster);

  return max_cluster_size;
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random grid
  int** grid = generate_grid();

  // Print the grid
  printf("Grid:\n");
  print_grid(grid);

  // Find the largest cluster
  int max_cluster_size = find_largest_cluster(grid);

  // Print the largest cluster size
  printf("Max cluster size: %d\n", max_cluster_size);

  // Free the memory for the grid
  for (int i = 0; i < GRID_WIDTH; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}