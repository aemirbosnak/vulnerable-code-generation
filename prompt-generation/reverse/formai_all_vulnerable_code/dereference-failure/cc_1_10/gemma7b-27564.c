//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLS 5

void play_bingo(int **board, int num_balls) {
  // Simulate drawing balls
  for (int i = 0; i < num_balls; i++) {
    // Generate a random number between 1 and 25
    int number = rand() % 25 + 1;

    // Mark the number on the board
    for (int r = 0; r < NUM_ROWS; r++) {
      for (int c = 0; c < NUM_COLS; c++) {
        if (board[r][c] == number) {
          board[r][c] = -1;
        }
      }
    }
  }

  // Check if anyone has won
  for (int r = 0; r < NUM_ROWS; r++) {
    // Check for a row win
    for (int c = 0; c < NUM_COLS; c++) {
      if (board[r][c] == -1) {
        // Player has won a row
        printf("Player %d has won a row!\n", r + 1);
      }
    }
  }

  // Check for a column win
  for (int c = 0; c < NUM_COLS; c++) {
    // Check for a column win
    for (int r = 0; r < NUM_ROWS; r++) {
      if (board[r][c] == -1) {
        // Player has won a column
        printf("Player %d has won a column!\n", c + 1);
      }
    }
  }

  // Check for a diagonal win
  if (board[0][0] == -1 && board[NUM_ROWS - 1][NUM_COLS - 1] == -1) {
    // Player has won diagonally
    printf("Player %d has won diagonally!\n", 1);
  }
}

int main() {
  // Create the bingo board
  int **board = (int **)malloc(NUM_ROWS * sizeof(int *));
  for (int r = 0; r < NUM_ROWS; r++) {
    board[r] = (int *)malloc(NUM_COLS * sizeof(int));
  }

  // Initialize the board
  for (int r = 0; r < NUM_ROWS; r++) {
    for (int c = 0; c < NUM_COLS; c++) {
      board[r][c] = 0;
    }
  }

  // Play bingo
  play_bingo(board, 20);

  // Free the memory
  for (int r = 0; r < NUM_ROWS; r++) {
    free(board[r]);
  }
  free(board);

  return 0;
}