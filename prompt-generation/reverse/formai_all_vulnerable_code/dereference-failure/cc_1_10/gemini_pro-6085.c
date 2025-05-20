//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid dimensions
#define WIDTH 20
#define HEIGHT 20

// Probability of a cell being open
#define P 0.5

// Union-find data structure
struct UF {
  int *id;
  int *sz;
  int count;
};

// Create a new union-find data structure
struct UF *UF_init(int n) {
  struct UF *uf = malloc(sizeof(struct UF));
  uf->id = malloc(n * sizeof(int));
  uf->sz = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    uf->id[i] = i;
    uf->sz[i] = 1;
  }
  uf->count = n;
  return uf;
}

// Find the root of a node
int UF_find(struct UF *uf, int p) {
  while (p != uf->id[p]) {
    uf->id[p] = uf->id[uf->id[p]];
    p = uf->id[p];
  }
  return p;
}

// Union two nodes
void UF_union(struct UF *uf, int p, int q) {
  int rootP = UF_find(uf, p);
  int rootQ = UF_find(uf, q);
  if (rootP == rootQ) return;
  if (uf->sz[rootP] < uf->sz[rootQ]) {
    uf->id[rootP] = rootQ;
    uf->sz[rootQ] += uf->sz[rootP];
  } else {
    uf->id[rootQ] = rootP;
    uf->sz[rootP] += uf->sz[rootQ];
  }
  uf->count--;
}

// Generate a random grid of open and closed cells
int **generate_grid() {
  int **grid = malloc(HEIGHT * sizeof(int *));
  for (int i = 0; i < HEIGHT; i++) {
    grid[i] = malloc(WIDTH * sizeof(int));
    for (int j = 0; j < WIDTH; j++) {
      grid[i][j] = (rand() / (RAND_MAX + 1.0)) < P ? 1 : 0;
    }
  }
  return grid;
}

// Print the grid
void print_grid(int **grid) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// Perform percolation simulation
int percolate(int **grid) {
  // Create a union-find data structure to track connected components
  struct UF *uf = UF_init(WIDTH * HEIGHT);

  // Iterate over the grid
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      // If the cell is open
      if (grid[i][j]) {
        // Union with the cells above, below, left, and right (if they are open)
        if (i > 0 && grid[i - 1][j]) UF_union(uf, i * WIDTH + j, (i - 1) * WIDTH + j);
        if (i < HEIGHT - 1 && grid[i + 1][j]) UF_union(uf, i * WIDTH + j, (i + 1) * WIDTH + j);
        if (j > 0 && grid[i][j - 1]) UF_union(uf, i * WIDTH + j, i * WIDTH + j - 1);
        if (j < WIDTH - 1 && grid[i][j + 1]) UF_union(uf, i * WIDTH + j, i * WIDTH + j + 1);
      }
    }
  }

  // Check if there is a path from the top to the bottom
  int rootTop = UF_find(uf, 0);
  int rootBottom = UF_find(uf, (HEIGHT - 1) * WIDTH + WIDTH - 1);
  return rootTop == rootBottom;
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random grid
  int **grid = generate_grid();

  // Print the grid
  printf("Grid:\n");
  print_grid(grid);

  // Perform percolation simulation
  int percolates = percolate(grid);

  // Print the result
  printf("Percolates: %d\n", percolates);

  // Free the grid
  for (int i = 0; i < HEIGHT; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}