//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Linus Torvalds
/* Sudoku puzzle solver in the Linus Torvalds style */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
// Define the size of the Sudoku puzzle
#define N 9
 
// Define the data structure for the Sudoku puzzle
struct Sudoku {
  int grid[N][N];
  bool solved;
};
 
// Function to create a new Sudoku puzzle
struct Sudoku *create_sudoku() {
  struct Sudoku *sudoku = malloc(sizeof(struct Sudoku));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      sudoku->grid[i][j] = 0;
    }
  }
  sudoku->solved = false;
  return sudoku;
}
 
// Function to print the Sudoku puzzle
void print_sudoku(struct Sudoku *sudoku) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", sudoku->grid[i][j]);
    }
    printf("\n");
  }
}
 
// Function to check if a number is valid in a given cell
bool is_valid(struct Sudoku *sudoku, int row, int col, int num) {
  // Check if the number is already present in the row
  for (int i = 0; i < N; i++) {
    if (sudoku->grid[row][i] == num) {
      return false;
    }
  }
 
  // Check if the number is already present in the column
  for (int i = 0; i < N; i++) {
    if (sudoku->grid[i][col] == num) {
      return false;
    }
  }
 
  // Check if the number is already present in the 3x3 box
  int box_row = row / 3;
  int box_col = col / 3;
  for (int i = 3 * box_row; i < 3 * box_row + 3; i++) {
    for (int j = 3 * box_col; j < 3 * box_col + 3; j++) {
      if (sudoku->grid[i][j] == num) {
        return false;
      }
    }
  }
 
  // If none of the above checks fail, the number is valid
  return true;
}
 
// Function to solve the Sudoku puzzle
bool solve_sudoku(struct Sudoku *sudoku) {
  // Iterate over all the cells in the puzzle
  for (int row = 0; row < N; row++) {
    for (int col = 0; col < N; col++) {
      // If the cell is empty, try all possible numbers
      if (sudoku->grid[row][col] == 0) {
        for (int num = 1; num <= N; num++) {
          // If the number is valid, try it
          if (is_valid(sudoku, row, col, num)) {
            sudoku->grid[row][col] = num;
 
            // Recursively solve the puzzle with the new number
            if (solve_sudoku(sudoku)) {
              return true;
            } else {
              // If the puzzle cannot be solved with the new number, reset the cell to empty
              sudoku->grid[row][col] = 0;
            }
          }
        }
 
        // If none of the numbers worked, the puzzle cannot be solved
        return false;
      }
    }
  }
 
  // If all the cells are filled, the puzzle is solved
  sudoku->solved = true;
  return true;
}
 
// Main function
int main() {
  // Create a new Sudoku puzzle
  struct Sudoku *sudoku = create_sudoku();
 
  // Print the unsolved puzzle
  printf("Unsolved puzzle:\n");
  print_sudoku(sudoku);
 
  // Solve the puzzle
  if (solve_sudoku(sudoku)) {
    // Print the solved puzzle
    printf("Solved puzzle:\n");
    print_sudoku(sudoku);
  } else {
    // The puzzle cannot be solved
    printf("The puzzle cannot be solved.\n");
  }
 
  // Free the memory allocated for the puzzle
  free(sudoku);
 
  return 0;
}