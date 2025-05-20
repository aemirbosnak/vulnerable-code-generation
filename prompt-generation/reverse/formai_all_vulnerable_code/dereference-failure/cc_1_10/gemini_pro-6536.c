//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9

// Structure to represent a Sudoku puzzle
struct Sudoku {
  int grid[N][N];
  int solved;
};

// Function to create a new Sudoku puzzle
struct Sudoku *newSudoku() {
  struct Sudoku *sudoku = (struct Sudoku *)malloc(sizeof(struct Sudoku));
  if (sudoku == NULL) {
    return NULL;
  }
  memset(sudoku->grid, 0, sizeof(sudoku->grid));
  sudoku->solved = 0;
  return sudoku;
}

// Function to free a Sudoku puzzle
void freeSudoku(struct Sudoku *sudoku) {
  if (sudoku != NULL) {
    free(sudoku);
  }
}

// Function to print a Sudoku puzzle
void printSudoku(struct Sudoku *sudoku) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", sudoku->grid[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a number is safe to place in a cell
int isSafe(struct Sudoku *sudoku, int row, int col, int num) {
  // Check row
  for (int i = 0; i < N; i++) {
    if (sudoku->grid[row][i] == num) {
      return 0;
    }
  }

  // Check column
  for (int i = 0; i < N; i++) {
    if (sudoku->grid[i][col] == num) {
      return 0;
    }
  }

  // Check box
  int boxRow = row / 3;
  int boxCol = col / 3;
  for (int i = 3 * boxRow; i < 3 * boxRow + 3; i++) {
    for (int j = 3 * boxCol; j < 3 * boxCol + 3; j++) {
      if (sudoku->grid[i][j] == num) {
        return 0;
      }
    }
  }

  return 1;
}

// Function to solve a Sudoku puzzle
int solveSudoku(struct Sudoku *sudoku) {
  // Start from the first cell
  int row = 0;
  int col = 0;

  // Find an empty cell
  while (sudoku->grid[row][col] != 0) {
    col++;
    if (col == N) {
      row++;
      col = 0;
    }
    if (row == N) {
      return 1;
    }
  }

  // Try all possible numbers for the empty cell
  for (int num = 1; num <= N; num++) {
    // Check if the number is safe to place
    if (isSafe(sudoku, row, col, num)) {
      // Place the number in the cell
      sudoku->grid[row][col] = num;

      // Solve the rest of the puzzle
      if (solveSudoku(sudoku)) {
        return 1;
      } else {
        // If the rest of the puzzle cannot be solved, reset the cell to empty
        sudoku->grid[row][col] = 0;
      }
    }
  }

  // If no number can be placed in the empty cell, the puzzle cannot be solved
  return 0;
}

int main() {
  // Create a new Sudoku puzzle
  struct Sudoku *sudoku = newSudoku();

  // Populate the puzzle with some values
  sudoku->grid[0][0] = 5;
  sudoku->grid[0][1] = 3;
  sudoku->grid[0][4] = 7;
  sudoku->grid[1][0] = 6;
  sudoku->grid[1][3] = 1;
  sudoku->grid[1][4] = 9;
  sudoku->grid[1][5] = 5;
  sudoku->grid[2][1] = 9;
  sudoku->grid[2][2] = 8;
  sudoku->grid[2][7] = 6;
  sudoku->grid[3][0] = 8;
  sudoku->grid[3][4] = 6;
  sudoku->grid[3][8] = 3;
  sudoku->grid[4][0] = 4;
  sudoku->grid[4][3] = 8;
  sudoku->grid[4][5] = 3;
  sudoku->grid[4][8] = 1;
  sudoku->grid[5][0] = 7;
  sudoku->grid[5][4] = 2;
  sudoku->grid[5][8] = 6;
  sudoku->grid[6][2] = 6;
  sudoku->grid[6][6] = 2;
  sudoku->grid[6][7] = 8;
  sudoku->grid[7][3] = 4;
  sudoku->grid[7][4] = 1;
  sudoku->grid[7][5] = 9;
  sudoku->grid[7][8] = 5;
  sudoku->grid[8][4] = 8;
  sudoku->grid[8][7] = 7;
  sudoku->grid[8][8] = 9;

  // Print the unsolved puzzle
  printf("Unsolved puzzle:\n");
  printSudoku(sudoku);

  // Solve the puzzle
  if (solveSudoku(sudoku)) {
    // Print the solved puzzle
    printf("Solved puzzle:\n");
    printSudoku(sudoku);
  } else {
    printf("The puzzle could not be solved.\n");
  }

  // Free the puzzle
  freeSudoku(sudoku);

  return 0;
}