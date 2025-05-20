//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY_SPOT '-'

void initializeBoard(char **board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = EMPTY_SPOT;
    }
  }
}

int isBoardFull(char **board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == EMPTY_SPOT) {
        return 0;
      }
    }
  }

  return 1;
}

int checkWin(char **board, char player) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
      return 1;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return 1;
  }

  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return 1;
  }

  return 0;
}

int main() {
  char **board = (char **)malloc(BOARD_SIZE * sizeof(char *));
  for (int i = 0; i < BOARD_SIZE; i++) {
    board[i] = (char *)malloc(BOARD_SIZE * sizeof(char));
  }

  initializeBoard(board);

  char player = PLAYER_X;
  int gameWon = 0;

  // Game loop
  while (!gameWon && !isBoardFull(board)) {
    // Get the player's move
    int row, column;
    printf("Enter your move (row, column): ");
    scanf("%d %d", &row, &column);

    // Validate the move
    if (row < 0 || row >= BOARD_SIZE || column < 0 || column >= BOARD_SIZE) {
      printf("Invalid move.\n");
      continue;
    }

    // Place the player's mark on the board
    board[row][column] = player;

    // Check if the player has won
    gameWon = checkWin(board, player);

    // If the player has not won, switch to the next player
    if (!gameWon) {
      player = PLAYER_O;
    }
  }

  // Game over
  if (gameWon) {
    printf("Congratulations! You won!\n");
  } else {
    printf("It's a draw.\n");
  }

  return 0;
}