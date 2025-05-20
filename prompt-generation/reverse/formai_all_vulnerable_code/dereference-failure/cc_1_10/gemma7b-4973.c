//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
  int **cells;
  int currentPlayer;
  int winner;
} Board;

Board *createBoard() {
  Board *board = malloc(sizeof(Board));
  board->cells = malloc(BOARD_SIZE * sizeof(int *));
  for (int i = 0; i < BOARD_SIZE; i++) {
    board->cells[i] = malloc(BOARD_SIZE * sizeof(int));
  }
  board->currentPlayer = 1;
  board->winner = 0;
  return board;
}

void makeMove(Board *board, int row, int col) {
  if (board->cells[row][col] != 0) {
    return;
  }
  board->cells[row][col] = board->currentPlayer;
  board->currentPlayer = (board->currentPlayer == 1) ? 2 : 1;
}

int checkWin(Board *board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board->cells[0][i] == board->cells[1][i] && board->cells[0][i] == board->cells[2][i] && board->cells[0][i] != 0) {
      return board->cells[0][i] * 2 - 1;
    }
  }
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board->cells[j][0] == board->cells[j][1] && board->cells[j][0] == board->cells[j][2] && board->cells[j][0] != 0) {
      return board->cells[j][0] * 2 - 1;
    }
  }
  if (board->cells[0][0] == board->cells[1][1] && board->cells[0][0] == board->cells[2][2] && board->cells[0][0] != 0) {
    return board->cells[0][0] * 2 - 1;
  }
  return 0;
}

int main() {
  Board *board = createBoard();
  makeMove(board, 1, 1);
  makeMove(board, 2, 0);
  makeMove(board, 0, 1);
  makeMove(board, 1, 0);
  makeMove(board, 2, 1);
  makeMove(board, 0, 2);
  int winner = checkWin(board);
  if (winner) {
    printf("Winner: Player %d\n", winner);
  } else {
    printf("Draw\n");
  }
  return 0;
}