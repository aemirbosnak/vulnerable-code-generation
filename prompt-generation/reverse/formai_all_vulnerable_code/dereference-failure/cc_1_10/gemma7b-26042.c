//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Board {
  int **board;
  int turn;
  int winner;
} Board;

Board *initBoard() {
  Board *board = malloc(sizeof(Board));
  board->board = malloc(sizeof(int *) * BOARD_SIZE);
  for (int i = 0; i < BOARD_SIZE; i++) {
    board->board[i] = malloc(sizeof(int) * BOARD_SIZE);
  }
  board->turn = 0;
  board->winner = 0;
  return board;
}

void makeMove(Board *board, int x, int y) {
  if (board->board[x][y] == 0 && board->winner == 0) {
    board->board[x][y] = board->turn;
    board->turn++;
  }
}

int checkWin(Board *board) {
  // Check rows
  for (int r = 0; r < BOARD_SIZE; r++) {
    if (board->board[0][r] == board->board[1][r] && board->board[0][r] == board->board[2][r] && board->board[0][r] != 0) {
      return board->board[0][r];
    }
  }

  // Check columns
  for (int c = 0; c < BOARD_SIZE; c++) {
    if (board->board[c][0] == board->board[c][1] && board->board[c][0] == board->board[c][2] && board->board[c][0] != 0) {
      return board->board[c][0];
    }
  }

  // Check diagonals
  if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
    return board->board[0][0];
  }

  // If all cells are occupied and no winner, it's a draw
  return 0;
}

int main() {
  Board *board = initBoard();
  makeMove(board, 1, 1);
  makeMove(board, 2, 0);
  makeMove(board, 0, 2);
  makeMove(board, 1, 0);
  makeMove(board, 2, 2);
  makeMove(board, 0, 0);
  int winner = checkWin(board);
  if (winner != 0) {
    printf("The winner is player %d!", winner);
  } else {
    printf("It's a draw!");
  }

  return 0;
}