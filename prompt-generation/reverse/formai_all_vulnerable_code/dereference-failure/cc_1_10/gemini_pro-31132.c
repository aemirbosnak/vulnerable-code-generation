//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Dimensions of the grid
#define SIZE 9

// Structure to represent a cell in the grid
typedef struct cell {
  int value;
  int possibilities[SIZE];
} cell;

// Function to create a new grid
cell* create_grid() {
  cell* grid = malloc(sizeof(cell) * SIZE * SIZE);
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      grid[i * SIZE + j].value = 0;
      for (int k = 0; k < SIZE; k++) {
        grid[i * SIZE + j].possibilities[k] = 1;
      }
    }
  }
  return grid;
}

// Function to print the grid
void print_grid(cell* grid) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%d ", grid[i * SIZE + j].value);
    }
    printf("\n");
  }
}

// Function to check if a value is possible in a cell
int is_possible(cell* grid, int row, int col, int value) {
  // Check row
  for (int i = 0; i < SIZE; i++) {
    if (grid[row * SIZE + i].value == value) {
      return 0;
    }
  }

  // Check column
  for (int i = 0; i < SIZE; i++) {
    if (grid[i * SIZE + col].value == value) {
      return 0;
    }
  }

  // Check box
  int box_row = row / 3;
  int box_col = col / 3;
  for (int i = 3 * box_row; i < 3 * box_row + 3; i++) {
    for (int j = 3 * box_col; j < 3 * box_col + 3; j++) {
      if (grid[i * SIZE + j].value == value) {
        return 0;
      }
    }
  }

  return 1;
}

// Function to solve the sudoku using backtracking
int solve_sudoku(cell* grid, int row, int col) {
  // Base case: we have reached the last cell in the grid
  if (row == SIZE - 1 && col == SIZE - 1) {
    return 1;
  }

  // If the current cell is not empty, move to the next cell
  if (grid[row * SIZE + col].value != 0) {
    if (col == SIZE - 1) {
      return solve_sudoku(grid, row + 1, 0);
    } else {
      return solve_sudoku(grid, row, col + 1);
    }
  }

  // Try all possible values for the current cell
  for (int i = 1; i <= SIZE; i++) {
    if (is_possible(grid, row, col, i)) {
      grid[row * SIZE + col].value = i;

      // If the value is valid, try to solve the rest of the grid
      if (col == SIZE - 1) {
        if (solve_sudoku(grid, row + 1, 0)) {
          return 1;
        }
      } else {
        if (solve_sudoku(grid, row, col + 1)) {
          return 1;
        }
      }

      // If the value is not valid, reset the cell to 0 and try the next value
      grid[row * SIZE + col].value = 0;
    }
  }

  // If no value is valid, return false
  return 0;
}

int main() {
  // Create a new grid
  cell* grid = create_grid();

  // Set the initial values of the grid
  grid[0 * SIZE + 0].value = 5;
  grid[0 * SIZE + 1].value = 3;
  grid[0 * SIZE + 4].value = 7;
  grid[1 * SIZE + 0].value = 6;
  grid[1 * SIZE + 3].value = 1;
  grid[1 * SIZE + 4].value = 9;
  grid[1 * SIZE + 5].value = 5;
  grid[2 * SIZE + 1].value = 9;
  grid[2 * SIZE + 2].value = 8;
  grid[2 * SIZE + 7].value = 6;
  grid[3 * SIZE + 0].value = 8;
  grid[3 * SIZE + 4].value = 6;
  grid[3 * SIZE + 8].value = 3;
  grid[4 * SIZE + 0].value = 4;
  grid[4 * SIZE + 3].value = 8;
  grid[4 * SIZE + 5].value = 3;
  grid[4 * SIZE + 8].value = 1;
  grid[5 * SIZE + 0].value = 7;
  grid[5 * SIZE + 4].value = 2;
  grid[5 * SIZE + 8].value = 6;
  grid[6 * SIZE + 1].value = 6;
  grid[6 * SIZE + 6].value = 2;
  grid[6 * SIZE + 7].value = 8;
  grid[7 * SIZE + 3].value = 4;
  grid[7 * SIZE + 4].value = 1;
  grid[7 * SIZE + 5].value = 9;
  grid[7 * SIZE + 8].value = 5;
  grid[8 * SIZE + 4].value = 8;
  grid[8 * SIZE + 7].value = 7;
  grid[8 * SIZE + 8].value = 9;

  // Print the initial grid
  printf("Initial grid:\n");
  print_grid(grid);

  // Solve the sudoku
  if (solve_sudoku(grid, 0, 0)) {
    // Print the solved grid
    printf("\nSolved grid:\n");
    print_grid(grid);
  } else {
    printf("No solution found");
  }

  // Free the grid
  free(grid);

  return 0;
}