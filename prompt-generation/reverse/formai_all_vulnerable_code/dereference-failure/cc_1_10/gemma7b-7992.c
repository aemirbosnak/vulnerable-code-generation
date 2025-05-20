//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: configurable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
  int **board;
  int player;
  int winner;
} Board;

void initializeBoard(Board *board) {
  board->board = (int **)malloc(sizeof(int *) * BOARD_SIZE);
  for (int i = 0; i < BOARD_SIZE; i++) {
    board->board[i] = (int *)malloc(sizeof(int) * BOARD_SIZE);
  }
  board->player = 1;
  board->winner = 0;
}

int isBoardFull(Board *board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board->board[i][j] == 0) {
        return 0;
      }
    }
  }
  return 1;
}

int checkWin(Board *board) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
      return board->board[0][i];
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0) {
      return board->board[j][0];
    }
  }

  // Check diagonals
  if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
    return board->board[0][0];
  }

  // If all else fails, it's a draw
  return 0;
}

int main() {
  Board board;
  initializeBoard(&board);

  // Game loop
  while (!isBoardFull(&board) && board.winner == 0) {
    // Get the player's move
    int moveX, moveY;
    printf("Enter your move (x, y): ");
    scanf("%d %d", &moveX, &moveY);

    // Place the player's mark
    board.board[moveX][moveY] = board.player;

    // Check if the player won
    board.winner = checkWin(&board);

    // Switch players
    board.player *= -1;
  }

  // Game over
  if (board.winner) {
    printf("Congratulations! You won!");
  } else {
    printf("It's a draw!");
  }

  return 0;
}