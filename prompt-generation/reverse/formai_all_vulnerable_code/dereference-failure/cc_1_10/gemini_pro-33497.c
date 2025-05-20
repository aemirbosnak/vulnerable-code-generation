//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid dimensions
#define GRID_WIDTH 100
#define GRID_HEIGHT 100

// Probability of a site being open
#define P 0.5

// Union-find data structure
typedef struct {
  int *parent;
  int *rank;
  int count;
} UF;

// Create a new union-find data structure
UF *UF_create(int n) {
  UF *uf = malloc(sizeof(UF));
  uf->parent = malloc(n * sizeof(int));
  uf->rank = malloc(n * sizeof(int));
  uf->count = n;
  for (int i = 0; i < n; i++) {
    uf->parent[i] = i;
    uf->rank[i] = 0;
  }
  return uf;
}

// Find the root of a node
int UF_find(UF *uf, int p) {
  if (uf->parent[p] == p) {
    return p;
  }
  return uf->parent[p] = UF_find(uf, uf->parent[p]);
}

// Union two nodes
void UF_union(UF *uf, int p, int q) {
  int rootP = UF_find(uf, p);
  int rootQ = UF_find(uf, q);
  if (rootP == rootQ) {
    return;
  }
  if (uf->rank[rootP] < uf->rank[rootQ]) {
    uf->parent[rootP] = rootQ;
  } else if (uf->rank[rootP] > uf->rank[rootQ]) {
    uf->parent[rootQ] = rootP;
  } else {
    uf->parent[rootQ] = rootP;
    uf->rank[rootP]++;
  }
  uf->count--;
}

// Check if the grid percolates
int percolates(int **grid) {
  // Create a union-find data structure
  UF *uf = UF_create(GRID_WIDTH * GRID_HEIGHT);

  // Iterate over the grid
  for (int i = 0; i < GRID_HEIGHT; i++) {
    for (int j = 0; j < GRID_WIDTH; j++) {
      // If the site is open
      if (grid[i][j] == 1) {
        // Union it with its neighbors
        if (i > 0 && grid[i - 1][j] == 1) {
          UF_union(uf, i * GRID_WIDTH + j, (i - 1) * GRID_WIDTH + j);
        }
        if (j > 0 && grid[i][j - 1] == 1) {
          UF_union(uf, i * GRID_WIDTH + j, i * GRID_WIDTH + j - 1);
        }
        if (i < GRID_HEIGHT - 1 && grid[i + 1][j] == 1) {
          UF_union(uf, i * GRID_WIDTH + j, (i + 1) * GRID_WIDTH + j);
        }
        if (j < GRID_WIDTH - 1 && grid[i][j + 1] == 1) {
          UF_union(uf, i * GRID_WIDTH + j, i * GRID_WIDTH + j + 1);
        }
      }
    }
  }

  // Check if the top and bottom rows are connected
  for (int i = 0; i < GRID_WIDTH; i++) {
    if (UF_find(uf, i) == UF_find(uf, GRID_WIDTH * GRID_HEIGHT - 1 - i)) {
      return 1;
    }
  }

  // Otherwise, the grid does not percolate
  return 0;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create a grid
  int **grid = malloc(GRID_HEIGHT * sizeof(int *));
  for (int i = 0; i < GRID_HEIGHT; i++) {
    grid[i] = malloc(GRID_WIDTH * sizeof(int));
    for (int j = 0; j < GRID_WIDTH; j++) {
      grid[i][j] = (rand() < RAND_MAX * P) ? 1 : 0;
    }
  }

  // Print the grid
  for (int i = 0; i < GRID_HEIGHT; i++) {
    for (int j = 0; j < GRID_WIDTH; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  // Check if the grid percolates
  int result = percolates(grid);

  // Print the result
  printf("Percolates: %s\n", result ? "yes" : "no");

  // Free the grid
  for (int i = 0; i < GRID_HEIGHT; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}