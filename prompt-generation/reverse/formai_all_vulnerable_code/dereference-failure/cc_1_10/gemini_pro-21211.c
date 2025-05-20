//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the grid size
#define GRID_SIZE 20

// Define the probability of a site being open
#define P 0.5

// Define the number of simulations to run
#define NUM_SIMULATIONS 100

// Define the data structure for a site
typedef struct site {
  int x;
  int y;
  int open;
} site;

// Define the data structure for a grid
typedef struct grid {
  site sites[GRID_SIZE][GRID_SIZE];
} grid;

// Create a new grid
grid *create_grid() {
  grid *g = malloc(sizeof(grid));
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      g->sites[i][j].x = i;
      g->sites[i][j].y = j;
      g->sites[i][j].open = rand() < P * RAND_MAX;
    }
  }
  return g;
}

// Destroy a grid
void destroy_grid(grid *g) {
  free(g);
}

// Print a grid
void print_grid(grid *g) {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      printf("%c", g->sites[i][j].open ? 'O' : 'X');
    }
    printf("\n");
  }
}

// Check if a site is open
int is_open(grid *g, int x, int y) {
  return g->sites[x][y].open;
}

// Check if a site is occupied
int is_occupied(grid *g, int x, int y) {
  return !is_open(g, x, y);
}

// Check if a site is on the top of the grid
int is_top(grid *g, int x, int y) {
  return x == 0;
}

// Check if a site is on the bottom of the grid
int is_bottom(grid *g, int x, int y) {
  return x == GRID_SIZE - 1;
}

// Check if a site is on the left of the grid
int is_left(grid *g, int x, int y) {
  return y == 0;
}

// Check if a site is on the right of the grid
int is_right(grid *g, int x, int y) {
  return y == GRID_SIZE - 1;
}

// Check if a site is on the boundary of the grid
int is_boundary(grid *g, int x, int y) {
  return is_top(g, x, y) || is_bottom(g, x, y) || is_left(g, x, y) || is_right(g, x, y);
}

// Find the number of open sites in a row
int count_open_sites_in_row(grid *g, int x, int y) {
  int count = 0;
  for (int i = 0; i < GRID_SIZE; i++) {
    if (is_open(g, x, i)) {
      count++;
    }
  }
  return count;
}

// Find the number of open sites in a column
int count_open_sites_in_column(grid *g, int x, int y) {
  int count = 0;
  for (int i = 0; i < GRID_SIZE; i++) {
    if (is_open(g, i, y)) {
      count++;
    }
  }
  return count;
}

// Check if a grid percolates
int does_grid_percolate(grid *g) {
  // Check if there is an open site on the top row
  for (int i = 0; i < GRID_SIZE; i++) {
    if (is_open(g, 0, i)) {
      // Check if there is an open site on the bottom row
      for (int j = 0; j < GRID_SIZE; j++) {
        if (is_open(g, GRID_SIZE - 1, j)) {
          // Check if there is a path between the two open sites
          if (count_open_sites_in_row(g, 0, i) + count_open_sites_in_row(g, GRID_SIZE - 1, j) >= GRID_SIZE) {
            return 1;
          }
        }
      }
    }
  }

  // Check if there is an open site on the left column
  for (int i = 0; i < GRID_SIZE; i++) {
    if (is_open(g, i, 0)) {
      // Check if there is an open site on the right column
      for (int j = 0; j < GRID_SIZE; j++) {
        if (is_open(g, i, GRID_SIZE - 1)) {
          // Check if there is a path between the two open sites
          if (count_open_sites_in_column(g, i, 0) + count_open_sites_in_column(g, i, GRID_SIZE - 1) >= GRID_SIZE) {
            return 1;
          }
        }
      }
    }
  }

  // The grid does not percolate
  return 0;
}

// Run a percolation simulation
int run_simulation() {
  // Create a new grid
  grid *g = create_grid();

  // Check if the grid percolates
  int percolates = does_grid_percolate(g);

  // Destroy the grid
  destroy_grid(g);

  // Return the result of the simulation
  return percolates;
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Run the simulation multiple times
  int num_percolates = 0;
  for (int i = 0; i < NUM_SIMULATIONS; i++) {
    num_percolates += run_simulation();
  }

  // Print the results of the simulation
  printf("Number of simulations: %d\n", NUM_SIMULATIONS);
  printf("Number of percolating grids: %d\n", num_percolates);
  printf("Probability of percolation: %f\n", (double)num_percolates / NUM_SIMULATIONS);

  return 0;
}