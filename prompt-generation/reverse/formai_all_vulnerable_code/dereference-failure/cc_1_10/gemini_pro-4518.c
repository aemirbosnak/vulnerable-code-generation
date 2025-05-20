//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A site is either open or blocked.
typedef enum {OPEN, BLOCKED} Site;

// A grid is a 2D array of sites.
typedef Site** Grid;

// Initialize a grid of size n x n to all blocked sites.
Grid init_grid(int n) {
  Grid grid = malloc(sizeof(Site*) * n);
  for (int i = 0; i < n; i++) {
    grid[i] = malloc(sizeof(Site) * n);
    for (int j = 0; j < n; j++) {
      grid[i][j] = BLOCKED;
    }
  }
  return grid;
}

// Free the memory allocated for a grid.
void free_grid(Grid grid, int n) {
  for (int i = 0; i < n; i++) {
    free(grid[i]);
  }
  free(grid);
}

// Open a site at row i and column j.
void open_site(Grid grid, int i, int j) {
  grid[i][j] = OPEN;
}

// Is a site at row i and column j open?
int is_open(Grid grid, int i, int j) {
  return grid[i][j] == OPEN;
}

// Percolate the grid.
void percolate(Grid grid, int n) {
  // Open the top row of the grid.
  for (int i = 0; i < n; i++) {
    open_site(grid, 0, i);
  }

  // For each row, try to percolate down through the grid.
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // If the site is open, try to percolate down.
      if (is_open(grid, i, j)) {
        // If the site below is open, percolate down.
        if (is_open(grid, i + 1, j)) {
          open_site(grid, i + 1, j);
        }
        // If the site to the right is open, percolate down.
        if (is_open(grid, i, j + 1)) {
          open_site(grid, i, j + 1);
        }
      }
    }
  }
}

// Print the grid to the console.
void print_grid(Grid grid, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%c", grid[i][j] == OPEN ? 'O' : 'X');
    }
    printf("\n");
  }
}

// Main function.
int main() {
  // Seed the random number generator.
  srand(time(NULL));

  // Get the size of the grid from the user.
  int n;
  printf("Enter the size of the grid: ");
  scanf("%d", &n);

  // Initialize the grid.
  Grid grid = init_grid(n);

  // Open a random number of sites.
  int num_sites = rand() % (n * n);
  for (int i = 0; i < num_sites; i++) {
    int row = rand() % n;
    int col = rand() % n;
    open_site(grid, row, col);
  }

  // Percolate the grid.
  percolate(grid, n);

  // Print the grid to the console.
  print_grid(grid, n);

  // Free the memory allocated for the grid.
  free_grid(grid, n);

  return 0;
}