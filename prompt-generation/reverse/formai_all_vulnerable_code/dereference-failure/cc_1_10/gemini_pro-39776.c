//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Constants
#define N 9       // Size of the Sudoku grid
#define SQRT_N 3  // Square root of the Sudoku grid size

// Data structures
typedef struct {
  int value;        // The value of the cell
  bool possible[N]; // The possible values for the cell
} Cell;

typedef struct {
  Cell grid[N][N]; // The Sudoku grid
} Sudoku;

// Function prototypes
Sudoku* create_sudoku();
void print_sudoku(Sudoku* sudoku);
bool is_safe(Sudoku* sudoku, int row, int col, int value);
bool solve_sudoku(Sudoku* sudoku);
void solve_sudoku_recursive(Sudoku* sudoku, int row, int col);

// Main function
int main() {
  // Create a new Sudoku puzzle
  Sudoku* sudoku = create_sudoku();

  // Print the initial Sudoku puzzle
  print_sudoku(sudoku);

  // Solve the Sudoku puzzle
  if (solve_sudoku(sudoku)) {
    // Print the solved Sudoku puzzle
    print_sudoku(sudoku);
  } else {
    printf("No solution found.\n");
  }

  // Free the memory allocated for the Sudoku puzzle
  free(sudoku);

  return 0;
}

// Creates a new Sudoku puzzle
Sudoku* create_sudoku() {
  // Allocate memory for the Sudoku puzzle
  Sudoku* sudoku = (Sudoku*)malloc(sizeof(Sudoku));

  // Initialize the Sudoku grid
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      sudoku->grid[i][j].value = 0;
      for (int k = 0; k < N; k++) {
        sudoku->grid[i][j].possible[k] = true;
      }
    }
  }

  // Return the Sudoku puzzle
  return sudoku;
}

// Prints the Sudoku puzzle
void print_sudoku(Sudoku* sudoku) {
  // Print the top border
  printf("+---+---+---+\n");

  // Print the Sudoku grid
  for (int i = 0; i < N; i++) {
    // Print the left border
    printf("| ");

    // Print the row
    for (int j = 0; j < N; j++) {
      // Print the cell value
      if (sudoku->grid[i][j].value == 0) {
        printf(" ");
      } else {
        printf("%d", sudoku->grid[i][j].value);
      }

      // Print the right border
      if (j % SQRT_N == SQRT_N - 1) {
        printf(" | ");
      }
    }

    // Print the bottom border
    printf("\n+---+---+---+\n");
  }
}

// Checks if it is safe to place a value in a cell
bool is_safe(Sudoku* sudoku, int row, int col, int value) {
  // Check the row
  for (int i = 0; i < N; i++) {
    if (sudoku->grid[row][i].value == value) {
      return false;
    }
  }

  // Check the column
  for (int i = 0; i < N; i++) {
    if (sudoku->grid[i][col].value == value) {
      return false;
    }
  }

  // Check the box
  int box_row = row / SQRT_N;
  int box_col = col / SQRT_N;
  for (int i = box_row * SQRT_N; i < box_row * SQRT_N + SQRT_N; i++) {
    for (int j = box_col * SQRT_N; j < box_col * SQRT_N + SQRT_N; j++) {
      if (sudoku->grid[i][j].value == value) {
        return false;
      }
    }
  }

  // The value is safe to place in the cell
  return true;
}

// Solves the Sudoku puzzle
bool solve_sudoku(Sudoku* sudoku) {
  // Solve the Sudoku puzzle recursively
  solve_sudoku_recursive(sudoku, 0, 0);

  // Return true if the Sudoku puzzle is solved
  return sudoku->grid[N - 1][N - 1].value != 0;
}

// Solves the Sudoku puzzle recursively
void solve_sudoku_recursive(Sudoku* sudoku, int row, int col) {
  // Base case: the Sudoku puzzle is solved
  if (row == N && col == 0) {
    return;
  }

  // If the current cell is not empty, skip it
  if (sudoku->grid[row][col].value != 0) {
    // Move to the next cell
    if (col == N - 1) {
      solve_sudoku_recursive(sudoku, row + 1, 0);
    } else {
      solve_sudoku_recursive(sudoku, row, col + 1);
    }
  } else {
    // Try all possible values for the current cell
    for (int value = 1; value <= N; value++) {
      // If the value is safe to place in the cell, place it and move to the next cell
      if (is_safe(sudoku, row, col, value)) {
        sudoku->grid[row][col].value = value;
        if (col == N - 1) {
          solve_sudoku_recursive(sudoku, row + 1, 0);
        } else {
          solve_sudoku_recursive(sudoku, row, col + 1);
        }
        // If the Sudoku puzzle is solved, stop
        if (sudoku->grid[N - 1][N - 1].value != 0) {
          return;
        }
        // If the Sudoku puzzle is not solved, backtrack
        sudoku->grid[row][col].value = 0;
      }
    }
  }
}