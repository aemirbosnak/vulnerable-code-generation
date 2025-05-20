//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 100  // Adjust this value to change the size of the grid

// Function to generate a random grid
int **generate_grid() {
  int **grid = malloc(GRID_SIZE * sizeof(int *));
  for (int i = 0; i < GRID_SIZE; i++) {
    grid[i] = malloc(GRID_SIZE * sizeof(int));
    for (int j = 0; j < GRID_SIZE; j++) {
      grid[i][j] = rand() % 2;  // 0 for blocked, 1 for open
    }
  }
  return grid;
}

// Function to print the grid
void print_grid(int **grid) {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a cell is open or blocked
int is_open(int **grid, int x, int y) { return grid[x][y] == 1; }

// Function to check if a cell is within the grid
int is_valid(int x, int y) { return x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE; }

// Function to perform DFS from a given cell
void dfs(int **grid, int x, int y) {
  if (!is_valid(x, y) || !is_open(grid, x, y)) {
    return;
  }

  // Mark the cell as visited
  grid[x][y] = -1;

  // Recursively explore adjacent cells
  dfs(grid, x - 1, y);
  dfs(grid, x + 1, y);
  dfs(grid, x, y - 1);
  dfs(grid, x, y + 1);
}

// Function to check if the grid percolates
int percolates(int **grid) {
  // Check if any cell in the top row is open
  for (int i = 0; i < GRID_SIZE; i++) {
    if (is_open(grid, i, 0)) {
      // Perform DFS from that cell
      dfs(grid, i, 0);

      // Check if any cell in the bottom row is marked as visited
      for (int j = 0; j < GRID_SIZE; j++) {
        if (grid[j][GRID_SIZE - 1] == -1) {
          return 1;  // Grid percolates
        }
      }
    }
  }

  return 0;  // Grid does not percolate
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random grid
  int **grid = generate_grid();

  // Print the grid
  printf("Initial grid:\n");
  print_grid(grid);

  // Check if the grid percolates
  int result = percolates(grid);

  // Print the result
  printf("\nPercolation result: %s\n", result ? "True" : "False");

  // Free the memory allocated for the grid
  for (int i = 0; i < GRID_SIZE; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}