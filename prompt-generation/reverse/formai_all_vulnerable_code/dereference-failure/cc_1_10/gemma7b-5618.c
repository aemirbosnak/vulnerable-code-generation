//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: post-apocalyptic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define EMPTY 0
#define PLAYER_X 1
#define PLAYER_O 2

#define BOARD_SIZE 3

typedef struct Board {
  int **board;
  int currentPlayer;
  int gameWon;
} Board;

Board *initBoard() {
  Board *board = malloc(sizeof(Board));

  board->board = malloc(BOARD_SIZE * sizeof(int *));
  for (int i = 0; i < BOARD_SIZE; i++) {
    board->board[i] = malloc(BOARD_SIZE * sizeof(int));
  }

  board->currentPlayer = PLAYER_X;
  board->gameWon = EMPTY;

  return board;
}

void placeMark(Board *board, int row, int col) {
  if (board->board[row][col] != EMPTY) {
    return;
  }

  board->board[row][col] = board->currentPlayer;
}

int checkWin(Board *board) {
  // Check rows
  for (int r = 0; r < BOARD_SIZE; r++) {
    if (board->board[r][0] == board->board[r][1] && board->board[r][0] == board->board[r][2] && board->board[r][0] != EMPTY) {
      return board->board[r][0];
    }
  }

  // Check columns
  for (int c = 0; c < BOARD_SIZE; c++) {
    if (board->board[0][c] == board->board[1][c] && board->board[0][c] == board->board[2][c] && board->board[0][c] != EMPTY) {
      return board->board[0][c];
    }
  }

  // Check diagonals
  if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != EMPTY) {
    return board->board[0][0];
  }

  // If all cells are occupied and no winner, it's a draw
  return EMPTY;
}

int main() {
  Board *board = initBoard();

  // Play the game
  while (!board->gameWon) {
    // Get the player's move
    int row, col;
    printf("Enter row: ");
    scanf("%d", &row);
    printf("Enter column: ");
    scanf("%d", &col);

    // Place the mark
    placeMark(board, row, col);

    // Check if the player has won
    if (checkWin(board) != EMPTY) {
      board->gameWon = board->currentPlayer;
    }

    // Switch to the next player
    board->currentPlayer = (board->currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
  }

  // Print the winner
  if (board->gameWon == PLAYER_X) {
    printf("Player X won!");
  } else if (board->gameWon == PLAYER_O) {
    printf("Player O won!");
  } else {
    printf("It's a draw!");
  }

  return 0;
}