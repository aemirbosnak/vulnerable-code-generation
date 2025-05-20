//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Total size of the grid
#define GRID_SIZE 10

// Percentage of cells to be blocked
#define BLOCKED_CELLS 30

// Function to create a random grid
int** create_grid(void) {
  // Allocate memory for the grid
  int** grid = malloc(GRID_SIZE * sizeof(int*));
  for (int i = 0; i < GRID_SIZE; i++) {
    grid[i] = malloc(GRID_SIZE * sizeof(int));
  }

  // Initialize the grid to 0 (unblocked)
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      grid[i][j] = 0;
    }
  }

  // Set some cells to be blocked
  srand(time(NULL));
  for (int i = 0; i < GRID_SIZE * GRID_SIZE * BLOCKED_CELLS / 100; i++) {
    int x = rand() % GRID_SIZE;
    int y = rand() % GRID_SIZE;
    grid[x][y] = 1;
  }

  return grid;
}

// Function to print the grid
void print_grid(int** grid) {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a cell is open
int is_open(int** grid, int x, int y) {
  return grid[x][y] == 0;
}

// Function to check if a cell is blocked
int is_blocked(int** grid, int x, int y) {
  return grid[x][y] == 1;
}

// Function to check if a cell is on the top edge of the grid
int is_on_top_edge(int x) {
  return x == 0;
}

// Function to check if a cell is on the bottom edge of the grid
int is_on_bottom_edge(int x) {
  return x == GRID_SIZE - 1;
}

// Function to check if a cell is on the left edge of the grid
int is_on_left_edge(int y) {
  return y == 0;
}

// Function to check if a cell is on the right edge of the grid
int is_on_right_edge(int y) {
  return y == GRID_SIZE - 1;
}

// Function to check if a cell is on an edge of the grid
int is_on_edge(int x, int y) {
  return is_on_top_edge(x) || is_on_bottom_edge(x) || is_on_left_edge(y) || is_on_right_edge(y);
}

// Function to check if a cell is in a corner of the grid
int is_in_corner(int x, int y) {
  return is_on_top_edge(x) && is_on_left_edge(y) || is_on_top_edge(x) && is_on_right_edge(y) || is_on_bottom_edge(x) && is_on_left_edge(y) || is_on_bottom_edge(x) && is_on_right_edge(y);
}

// Function to check if a cell is adjacent to an open cell
int is_adjacent_to_open_cell(int** grid, int x, int y) {
  for (int i = x - 1; i <= x + 1; i++) {
    for (int j = y - 1; j <= y + 1; j++) {
      if (is_open(grid, i, j)) {
        return 1;
      }
    }
  }

  return 0;
}

// Function to check if a cell is part of a percolating path
int is_part_of_percolating_path(int** grid, int x, int y) {
  // If the cell is on the top edge, it is part of a percolating path if it is open and adjacent to an open cell
  if (is_on_top_edge(x)) {
    return is_open(grid, x, y) && is_adjacent_to_open_cell(grid, x, y);
  }

  // If the cell is on the bottom edge, it is part of a percolating path if it is open and adjacent to an open cell that is part of a percolating path
  if (is_on_bottom_edge(x)) {
    return is_open(grid, x, y) && is_adjacent_to_open_cell(grid, x, y) && is_part_of_percolating_path(grid, x - 1, y);
  }

  // If the cell is on the left edge, it is part of a percolating path if it is open and adjacent to an open cell that is part of a percolating path
  if (is_on_left_edge(y)) {
    return is_open(grid, x, y) && is_adjacent_to_open_cell(grid, x, y) && is_part_of_percolating_path(grid, x, y + 1);
  }

  // If the cell is on the right edge, it is part of a percolating path if it is open and adjacent to an open cell that is part of a percolating path
  if (is_on_right_edge(y)) {
    return is_open(grid, x, y) && is_adjacent_to_open_cell(grid, x, y) && is_part_of_percolating_path(grid, x, y - 1);
  }

  // If the cell is not on an edge, it is part of a percolating path if it is open and adjacent to an open cell that is part of a percolating path in any direction
  return is_open(grid, x, y) && is_adjacent_to_open_cell(grid, x, y) && (is_part_of_percolating_path(grid, x - 1, y) || is_part_of_percolating_path(grid, x + 1, y) || is_part_of_percolating_path(grid, x, y + 1) || is_part_of_percolating_path(grid, x, y - 1));
}

// Function to check if the grid percolates
int does_grid_percolate(int** grid) {
  // Check if any cell on the bottom edge is part of a percolating path
  for (int i = 0; i < GRID_SIZE; i++) {
    if (is_part_of_percolating_path(grid, GRID_SIZE - 1, i)) {
      return 1;
    }
  }

  return 0;
}

int main(void) {
  // Create a random grid
  int** grid = create_grid();

  // Print the grid
  printf("Initial grid:\n");
  print_grid(grid);

  // Check if the grid percolates
  int percolates = does_grid_percolate(grid);

  // Print the result
  if (percolates) {
    printf("The grid percolates!\n");
  } else {
    printf("The grid does not percolate.\n");
  }

  // Free the grid
  for (int i = 0; i < GRID_SIZE; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}