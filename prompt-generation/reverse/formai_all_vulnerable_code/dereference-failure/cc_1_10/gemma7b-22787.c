//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Board {
  int **board;
  int turn;
  int winner;
} Board;

void initializeBoard(Board *board) {
  board->board = malloc(BOARD_SIZE * sizeof(int *));
  for (int i = 0; i < BOARD_SIZE; i++) {
    board->board[i] = malloc(BOARD_SIZE * sizeof(int));
  }
  board->turn = 0;
  board->winner = -1;
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

void makeMove(Board *board, int x, int y) {
  if (board->board[x][y] != 0) {
    return;
  }
  board->board[x][y] = board->turn;
  board->turn++;
}

int checkWinner(Board *board) {
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

  // No winner
  return -1;
}

int main() {
  Board board;
  initializeBoard(&board);

  // Play the game
  while (!isBoardFull(&board) && board.winner == -1) {
    // Get the player's move
    int x, y;
    printf("Enter your move (x, y): ");
    scanf("%d %d", &x, &y);

    // Make the move
    makeMove(&board, x, y);

    // Check if there is a winner
    board.winner = checkWinner(&board);

    // Print the board
    for (int i = 0; i < BOARD_SIZE; i++) {
      for (int j = 0; j < BOARD_SIZE; j++) {
        printf("%d ", board.board[i][j]);
      }
      printf("\n");
    }
  }

  // Game over
  if (board.winner != -1) {
    printf("Winner: Player %d\n", board.winner);
  } else {
    printf("It's a draw!\n");
  }

  return 0;
}