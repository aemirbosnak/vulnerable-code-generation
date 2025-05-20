//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Alan Turing
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BOARD_SIZE 3

typedef struct Board {
  char **board;
  int turn;
  int winner;
} Board;

Board *createBoard() {
  Board *board = malloc(sizeof(Board));
  board->board = malloc(sizeof(char *) * BOARD_SIZE);
  for (int i = 0; i < BOARD_SIZE; i++) {
    board->board[i] = malloc(sizeof(char) * BOARD_SIZE);
  }
  board->turn = 0;
  board->winner = 0;
  return board;
}

void playTurn(Board *board, int row, int col) {
  if (board->board[row][col] == '-' && board->winner == 0) {
    board->board[row][col] = 'O';
    board->turn++;
  }
}

int checkWin(Board *board) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != '-') {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != '-') {
      return 1;
    }
  }

  // Check diagonals
  if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != '-') {
    return 1;
  }

  // No winner
  return 0;
}

int main() {
  Board *board = createBoard();

  // Play the game
  playTurn(board, 1, 1);
  playTurn(board, 0, 0);
  playTurn(board, 2, 2);
  playTurn(board, 1, 0);
  playTurn(board, 0, 2);

  // Check if there is a winner
  if (checkWin(board) == 1) {
    printf("Winner!");
  } else {
    printf("No winner!");
  }

  return 0;
}