//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

void bingo(int **board, int rows, int cols) {
  // Generate a random number for each element in the board
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      board[r][c] = rand() % 90 + 1;
    }
  }

  // Check if the player has won
  for (int r = 0; r < rows; r++) {
    // Check if the player has won a row
    for (int c = 0; c < cols; c++) {
      // If the player has won a row, print the winning message
      if (board[r][c] == board[r][0] && board[r][c] == board[r][cols - 1]) {
        printf("Player has won a row!\n");
      }
    }
  }

  // Check if the player has won a column
  for (int c = 0; c < cols; c++) {
    // Check if the player has won a column
    for (int r = 0; r < rows; r++) {
      // If the player has won a column, print the winning message
      if (board[r][c] == board[0][c] && board[r][c] == board[rows - 1][c]) {
        printf("Player has won a column!\n");
      }
    }
  }

  // Check if the player has won the diagonal
  if (board[0][0] == board[rows - 1][cols - 1] && board[0][0] == board[rows - 1][0]) {
    printf("Player has won the diagonal!\n");
  }
}

int main() {
  // Create a 5x5 bingo board
  int **board = (int **)malloc(5 * sizeof(int *));
  for (int r = 0; r < 5; r++) {
    board[r] = (int *)malloc(5 * sizeof(int));
  }

  // Play bingo
  bingo(board, 5, 5);

  // Free the memory allocated for the bingo board
  for (int r = 0; r < 5; r++) {
    free(board[r]);
  }
  free(board);

  return 0;
}