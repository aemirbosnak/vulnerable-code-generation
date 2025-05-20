//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 9

// Data structure to represent a Sudoku board
typedef struct {
  int board[BOARD_SIZE][BOARD_SIZE];
  bool solved;
} SudokuBoard;

// Function to create a new Sudoku board
SudokuBoard* createBoard() {
  SudokuBoard* board = (SudokuBoard*)malloc(sizeof(SudokuBoard));
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board->board[i][j] = 0;
    }
  }
  board->solved = false;
  return board;
}

// Function to print a Sudoku board
void printBoard(SudokuBoard* board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%d ", board->board[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a number is valid in a given cell
bool isValid(SudokuBoard* board, int row, int col, int num) {
  // Check row
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board->board[row][i] == num) {
      return false;
    }
  }

  // Check column
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board->board[i][col] == num) {
      return false;
    }
  }

  // Check 3x3 box
  int boxRowStart = (row / 3) * 3;
  int boxColStart = (col / 3) * 3;
  for (int i = boxRowStart; i < boxRowStart + 3; i++) {
    for (int j = boxColStart; j < boxColStart + 3; j++) {
      if (board->board[i][j] == num) {
        return false;
      }
    }
  }

  return true;
}

// Function to solve a Sudoku board using backtracking
bool solve(SudokuBoard* board) {
  // Find an empty cell
  int row, col;
  bool found = false;
  for (row = 0; row < BOARD_SIZE && !found; row++) {
    for (col = 0; col < BOARD_SIZE && !found; col++) {
      if (board->board[row][col] == 0) {
        found = true;
      }
    }
  }

  // If no empty cell found, the board is solved
  if (!found) {
    board->solved = true;
    return true;
  }

  // Try all possible numbers for the empty cell
  for (int num = 1; num <= BOARD_SIZE; num++) {
    if (isValid(board, row, col, num)) {
      // Try placing the number in the empty cell
      board->board[row][col] = num;

      // Recursively solve the rest of the board
      if (solve(board)) {
        return true;
      }

      // If the board is not solved, reset the empty cell
      board->board[row][col] = 0;
    }
  }

  return false;
}

int main() {
  // Create a new Sudoku board
  SudokuBoard* board = createBoard();

  // Populate the board with some initial values
  board->board[0][0] = 5;
  board->board[0][1] = 3;
  board->board[0][4] = 7;
  board->board[1][0] = 6;
  board->board[1][3] = 1;
  board->board[1][4] = 9;
  board->board[1][5] = 5;
  board->board[2][1] = 9;
  board->board[2][2] = 8;
  board->board[2][7] = 6;
  board->board[3][0] = 8;
  board->board[3][4] = 6;
  board->board[3][8] = 3;
  board->board[4][0] = 4;
  board->board[4][3] = 8;
  board->board[4][5] = 3;
  board->board[4][8] = 1;
  board->board[5][0] = 7;
  board->board[5][4] = 2;
  board->board[5][8] = 6;
  board->board[6][1] = 6;
  board->board[6][6] = 2;
  board->board[6][7] = 8;
  board->board[7][3] = 4;
  board->board[7][4] = 1;
  board->board[7][5] = 9;
  board->board[7][8] = 5;
  board->board[8][4] = 8;
  board->board[8][7] = 7;
  board->board[8][8] = 9;

  // Print the initial board
  printf("Initial board:\n");
  printBoard(board);

  // Solve the board
  bool solved = solve(board);

  // Print the solved board
  if (solved) {
    printf("\nSolved board:\n");
    printBoard(board);
  } else {
    printf("\nThe board could not be solved.\n");
  }

  return 0;
}