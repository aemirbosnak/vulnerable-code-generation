//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid dimensions
#define WIDTH 20
#define HEIGHT 20

// Probability of a site being open
#define P 0.5

// Union-find data structure
typedef struct {
  int *parent;
  int *rank;
  int count;
} UF;

// Initialize the union-find data structure
void UF_init(UF *uf, int n) {
  uf->parent = malloc(n * sizeof(int));
  uf->rank = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    uf->parent[i] = i;
    uf->rank[i] = 0;
  }
  uf->count = n;
}

// Find the root of the tree containing p
int UF_find(UF *uf, int p) {
  if (uf->parent[p] != p) {
    uf->parent[p] = UF_find(uf, uf->parent[p]);
  }
  return uf->parent[p];
}

// Union the trees containing p and q
void UF_union(UF *uf, int p, int q) {
  int root_p = UF_find(uf, p);
  int root_q = UF_find(uf, q);
  if (root_p != root_q) {
    if (uf->rank[root_p] < uf->rank[root_q]) {
      uf->parent[root_p] = root_q;
    } else if (uf->rank[root_p] > uf->rank[root_q]) {
      uf->parent[root_q] = root_p;
    } else {
      uf->parent[root_q] = root_p;
      uf->rank[root_p]++;
    }
    uf->count--;
  }
}

// Open a site at (x, y)
void open_site(int grid[WIDTH][HEIGHT], int x, int y, UF *uf) {
  if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
    return;
  }

  if (grid[x][y] == 0) {
    grid[x][y] = 1;

    // Union the site with its open neighbors
    if (x > 0 && grid[x - 1][y] == 1) {
      UF_union(uf, x * WIDTH + y, (x - 1) * WIDTH + y);
    }
    if (x < WIDTH - 1 && grid[x + 1][y] == 1) {
      UF_union(uf, x * WIDTH + y, (x + 1) * WIDTH + y);
    }
    if (y > 0 && grid[x][y - 1] == 1) {
      UF_union(uf, x * WIDTH + y, x * WIDTH + (y - 1));
    }
    if (y < HEIGHT - 1 && grid[x][y + 1] == 1) {
      UF_union(uf, x * WIDTH + y, x * WIDTH + (y + 1));
    }
  }
}

// Check if the system percolates
int percolates(int grid[WIDTH][HEIGHT], UF *uf) {
  // Check if any site in the top row is connected to the bottom row
  for (int i = 0; i < WIDTH; i++) {
    if (UF_find(uf, i) == UF_find(uf, WIDTH * HEIGHT - 1)) {
      return 1;
    }
  }

  return 0;
}

// Print the grid
void print_grid(int grid[WIDTH][HEIGHT]) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%d ", grid[j][i]);
    }
    printf("\n");
  }
}

int main() {
  // Initialize the grid
  int grid[WIDTH][HEIGHT];
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      grid[i][j] = 0;
    }
  }

  // Initialize the union-find data structure
  UF uf;
  UF_init(&uf, WIDTH * HEIGHT);

  // Open sites randomly
  srand(time(NULL));
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      if (rand() < P * RAND_MAX) {
        open_site(grid, i, j, &uf);
      }
    }
  }

  // Check if the system percolates
  int percolates_flag = percolates(grid, &uf);

  // Print the grid
  printf("Grid:\n");
  print_grid(grid);

  // Print the percolation status
  if (percolates_flag) {
    printf("The system percolates.\n");
  } else {
    printf("The system does not percolate.\n");
  }

  return 0;
}