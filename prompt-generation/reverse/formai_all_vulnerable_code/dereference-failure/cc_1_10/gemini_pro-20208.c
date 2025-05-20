//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid dimensions
#define WIDTH 20
#define HEIGHT 20

// Probability of a cell being open
#define P 0.5

// Union-find data structure
typedef struct {
  int *id;
  int count;
} UF;

// Create a new union-find data structure
UF *UF_create(int n) {
  UF *uf = malloc(sizeof(UF));
  uf->id = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    uf->id[i] = i;
  }
  uf->count = n;
  return uf;
}

// Find the root of the tree containing p
int UF_find(UF *uf, int p) {
  while (p != uf->id[p]) {
    uf->id[p] = uf->id[uf->id[p]];
    p = uf->id[p];
  }
  return p;
}

// Merge the trees containing p and q
void UF_union(UF *uf, int p, int q) {
  int rootP = UF_find(uf, p);
  int rootQ = UF_find(uf, q);
  if (rootP != rootQ) {
    uf->id[rootP] = rootQ;
    uf->count--;
  }
}

// Check if the system percolates
int percolates(int grid[WIDTH][HEIGHT], UF *uf) {
  // Find the root of the tree containing the top cell
  int rootTop = UF_find(uf, 0);

  // Find the root of the tree containing the bottom cell
  int rootBottom = UF_find(uf, WIDTH * HEIGHT - 1);

  // If the roots are the same, the system percolates
  return rootTop == rootBottom;
}

// Print the grid
void printGrid(int grid[WIDTH][HEIGHT]) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create a grid
  int grid[WIDTH][HEIGHT];

  // Initialize the grid
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      grid[i][j] = rand() < P ? 1 : 0;
    }
  }

  // Create a union-find data structure
  UF *uf = UF_create(WIDTH * HEIGHT);

  // Connect open cells
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (grid[i][j] == 0) {
        continue;
      }

      // Connect to the cell above
      if (i > 0 && grid[i - 1][j] == 1) {
        UF_union(uf, i * WIDTH + j, (i - 1) * WIDTH + j);
      }

      // Connect to the cell to the left
      if (j > 0 && grid[i][j - 1] == 1) {
        UF_union(uf, i * WIDTH + j, i * WIDTH + j - 1);
      }
    }
  }

  // Print the grid
  printGrid(grid);

  // Check if the system percolates
  if (percolates(grid, uf)) {
    printf("The system percolates.\n");
  } else {
    printf("The system does not percolate.\n");
  }

  // Free the union-find data structure
  free(uf->id);
  free(uf);

  return 0;
}