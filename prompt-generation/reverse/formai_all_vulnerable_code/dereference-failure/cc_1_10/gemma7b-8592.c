//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct GameBoard {
  int board[BOARD_SIZE][BOARD_SIZE];
  int currentPlayer;
} GameBoard;

void initializeGameBoard(GameBoard *board) {
  board->currentPlayer = 1;
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      board->board[r][c] = 0;
    }
  }
}

int checkIfWon(GameBoard *board) {
  // Check rows
  for (int r = 0; r < BOARD_SIZE; r++) {
    if (board->board[r][0] == board->board[r][1] && board->board[r][0] == board->board[r][2] && board->board[r][0] != 0) {
      return board->board[r][0];
    }
  }

  // Check columns
  for (int c = 0; c < BOARD_SIZE; c++) {
    if (board->board[0][c] == board->board[1][c] && board->board[0][c] == board->board[2][c] && board->board[0][c] != 0) {
      return board->board[0][c];
    }
  }

  // Check diagonals
  if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
    return board->board[0][0];
  }

  // If all cells are occupied and no one won, it's a draw
  return 0;
}

void makeMove(GameBoard *board, int row, int column) {
  if (board->board[row][column] != 0) {
    return;
  }

  board->board[row][column] = board->currentPlayer;
  board->currentPlayer = (board->currentPlayer == 1) ? 2 : 1;
}

int main() {
  GameBoard gameBoard;
  initializeGameBoard(&gameBoard);

  // Play until someone wins or it's a draw
  while (!checkIfWon(&gameBoard) && gameBoard.currentPlayer != 0) {
    // Get the player's move
    int moveRow, moveColumn;
    printf("Enter your move (row, column): ");
    scanf("%d %d", &moveRow, &moveColumn);

    // Make the move
    makeMove(&gameBoard, moveRow, moveColumn);
  }

  // Print the winner or draw
  if (checkIfWon(&gameBoard) != 0) {
    printf("Winner: Player %d\n", checkIfWon(&gameBoard));
  } else {
    printf("Draw\n");
  }

  return 0;
}