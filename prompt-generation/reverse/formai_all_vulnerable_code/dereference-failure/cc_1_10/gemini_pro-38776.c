//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Define the size of the Sudoku board.
#define N 9

// Define the set of all possible values for a Sudoku cell.
#define POSSIBLE_VALUES {1, 2, 3, 4, 5, 6, 7, 8, 9}

// Define the data structure for a Sudoku board.
typedef struct {
  int cells[N][N];
} SudokuBoard;

// Create a new Sudoku board.
SudokuBoard* create_board() {
  SudokuBoard* board = malloc(sizeof(SudokuBoard));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      board->cells[i][j] = 0;
    }
  }
  return board;
}

// Free the memory allocated for a Sudoku board.
void free_board(SudokuBoard* board) {
  free(board);
}

// Print a Sudoku board to the console.
void print_board(SudokuBoard* board) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", board->cells[i][j]);
    }
    printf("\n");
  }
}

// Check if a Sudoku board is valid.
int is_valid_board(SudokuBoard* board) {
  // Check if each row contains all of the possible values.
  for (int i = 0; i < N; i++) {
    int values[N] = {0};
    for (int j = 0; j < N; j++) {
      values[board->cells[i][j] - 1]++;
    }
    for (int k = 0; k < N; k++) {
      if (values[k] != 1) {
        return 0;
      }
    }
  }

  // Check if each column contains all of the possible values.
  for (int j = 0; j < N; j++) {
    int values[N] = {0};
    for (int i = 0; i < N; i++) {
      values[board->cells[i][j] - 1]++;
    }
    for (int k = 0; k < N; k++) {
      if (values[k] != 1) {
        return 0;
      }
    }
  }

  // Check if each 3x3 subgrid contains all of the possible values.
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int values[N] = {0};
      for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
          values[board->cells[i * 3 + k][j * 3 + l] - 1]++;
        }
      }
      for (int k = 0; k < N; k++) {
        if (values[k] != 1) {
          return 0;
        }
      }
    }
  }

  return 1;
}

// Solve a Sudoku board using backtracking.
int solve_board(SudokuBoard* board) {
  // Find the first empty cell.
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (board->cells[i][j] == 0) {
        goto found;
      }
    }
  }
  found:

  // If there are no empty cells, then the board is solved.
  if (i == N && j == N) {
    return 1;
  }

  // Try all possible values for the empty cell.
  for (int k = 0; k < N; k++) {
    // Check if the value is valid for the cell.
    int valid = 1;
    for (int l = 0; l < N; l++) {
      if (board->cells[i][l] == k + 1 || board->cells[l][j] == k + 1) {
        valid = 0;
        break;
      }
    }
    for (int l = 0; l < 3; l++) {
      for (int m = 0; m < 3; m++) {
        if (board->cells[i / 3 * 3 + l][j / 3 * 3 + m] == k + 1) {
          valid = 0;
          break;
        }
      }
    }
    if (!valid) {
      continue;
    }

    // Set the cell to the value.
    board->cells[i][j] = k + 1;

    // Recursively solve the board.
    if (solve_board(board)) {
      return 1;
    }

    // If the board is not solved, then reset the cell to 0.
    board->cells[i][j] = 0;
  }

  // If no values are valid for the cell, then the board is unsolvable.
  return 0;
}

int main() {
  // Create a new Sudoku board.
  SudokuBoard* board = create_board();

  // Set the initial values of the board.
  board->cells[0][0] = 5;
  board->cells[0][1] = 3;
  board->cells[0][4] = 7;
  board->cells[1][0] = 6;
  board->cells[1][3] = 1;
  board->cells[1][4] = 9;
  board->cells[1][5] = 5;
  board->cells[2][1] = 9;
  board->cells[2][2] = 8;
  board->cells[2][7] = 6;
  board->cells[3][0] = 8;
  board->cells[3][4] = 6;
  board->cells[3][8] = 3;
  board->cells[4][0] = 4;
  board->cells[4][3] = 8;
  board->cells[4][5] = 3;
  board->cells[4][8] = 1;
  board->cells[5][0] = 7;
  board->cells[5][4] = 2;
  board->cells[5][8] = 6;
  board->cells[6][1] = 6;
  board->cells[6][6] = 2;
  board->cells[6][7] = 8;
  board->cells[7][3] = 4;
  board->cells[7][4] = 1;
  board->cells[7][5] = 9;
  board->cells[7][8] = 5;
  board->cells[8][4] = 8;
  board->cells[8][7] = 7;
  board->cells[8][8] = 9;

  // Print the original board.
  printf("Original board:\n");
  print_board(board);

  // Solve the board.
  int solved = solve_board(board);

  // Print the solved board.
  if (solved) {
    printf("Solved board:\n");
    print_board(board);
  } else {
    printf("Unsolvable board.\n");
  }

  // Free the memory allocated for the board.
  free_board(board);

  return 0;
}