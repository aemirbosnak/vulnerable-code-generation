//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: shocked
#include <stdlib.h>
#include <time.h>

int main() {
  int n = 10;
  int** grid = NULL;
  grid = malloc(n * sizeof(int*));
  for(int i = 0; i < n; i++) {
    grid[i] = malloc(n * sizeof(int));
  }

  // Initialize the grid
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      grid[i][j] = 0;
    }
  }

  // Percolation simulation
  int num_iter = 0;
  while(!percolation(grid, n, n, num_iter)) {
    num_iter++;
  }

  // Print the final grid
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  free(grid);
  return 0;
}

int percolation(int** grid, int n, int m, int num_iter) {
  // Randomly choose a site
  int x = rand() % n;
  int y = rand() % m;

  // If the site is not occupied and the row is not full, occupy the site
  if(grid[x][y] == 0 && grid[x][y] != -1) {
    grid[x][y] = 1;

    // Check if the site is the top site
    if(x == 0) {
      return 0;
    }

    // Check if the site is the leftmost site
    if(y == 0) {
      return 0;
    }

    // Check if the site is the rightmost site
    if(y == m - 1) {
      return 0;
    }

    // Occupy the neighboring sites
    grid[x - 1][y] = 1;
    grid[x + 1][y] = 1;
    grid[x][y - 1] = 1;
    grid[x][y + 1] = 1;
  }

  // Increment the number of iterations
  num_iter++;

  // Return 0 if the grid is full or -1 otherwise
  return num_iter;
}