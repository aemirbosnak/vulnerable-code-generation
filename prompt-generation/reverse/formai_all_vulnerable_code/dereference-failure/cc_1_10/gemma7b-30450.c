//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 10

void draw_board(int **board) {
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      printf("%c ", board[r][c]);
    }
    printf("\n");
  }
}

int main() {
  int **board = (int **)malloc(ROWS * sizeof(int *));
  for (int r = 0; r < ROWS; r++) {
    board[r] = (int *)malloc(COLS * sizeof(int));
  }

  // Initialize the board
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      board[r][c] = 0;
    }
  }

  // Game loop
  while (1) {
    draw_board(board);

    // Get the user's move
    int move = getchar();

    // Validate the move
    if (move < 0 || move >= COLS) {
      printf("Invalid move.\n");
      continue;
    }

    // Make the move
    board[0][move] = 1;

    // Check if the player has won
    if (board[0][move] == 3) {
      draw_board(board);
      printf("You won!\n");
      break;
    }

    // Check if the player has lost
    if (board[ROWS - 1][move] == 3) {
      draw_board(board);
      printf("You lost.\n");
      break;
    }

    // Move the aliens
    for (int r = 0; r < ROWS; r++) {
      for (int c = 0; c < COLS; c++) {
        if (board[r][c] == 2) {
          board[r][c] = 0;
          board[r - 1][c] = 2;
        }
      }
    }
  }

  // Free the memory
  for (int r = 0; r < ROWS; r++) {
    free(board[r]);
  }
  free(board);

  return 0;
}