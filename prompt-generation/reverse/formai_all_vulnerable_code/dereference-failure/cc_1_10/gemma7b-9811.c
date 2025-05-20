//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY_SPACE '-'

void initializeBoard(char **board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    board[i] = malloc(BOARD_SIZE * sizeof(char));
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = EMPTY_SPACE;
    }
  }
}

int isBoardFull(char **board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == EMPTY_SPACE) {
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

  // If all else fails, it's a draw
  return 0;
}

int main() {
  char **board;
  initializeBoard(&board);

  // Play until someone wins or the board is full
  while (!isBoardFull(board) && !checkWin(board, PLAYER_X)) {
    // Get the player's move
    int move = rand() % 9;

    // Place the player's mark on the board
    board[move / BOARD_SIZE][move % BOARD_SIZE] = PLAYER_X;
  }

  // Check if the player won or it was a draw
  if (checkWin(board, PLAYER_X) == 1) {
    printf("Player X won!");
  } else if (isBoardFull(board) == 1) {
    printf("It's a draw!");
  } else {
    printf("Error!");
  }

  return 0;
}