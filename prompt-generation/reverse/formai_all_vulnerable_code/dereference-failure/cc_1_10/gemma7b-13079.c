//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: accurate
#include <stdlib.h>
#include <time.h>

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

void placeMove(Board *board, int x, int y) {
  if (board->board[x][y] != 0) return;
  board->board[x][y] = board->turn;
  board->turn++;
}

int checkWin(Board *board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
      return board->board[0][i];
    }
  }

  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0) {
      return board->board[j][0];
    }
  }

  if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
    return board->board[0][0];
  }

  return 0;
}

int main() {
  Board *board = initBoard();
  placeMove(board, 0, 0);
  placeMove(board, 1, 0);
  placeMove(board, 2, 0);
  placeMove(board, 0, 1);
  placeMove(board, 1, 1);
  placeMove(board, 2, 1);
  placeMove(board, 0, 2);
  placeMove(board, 1, 2);
  placeMove(board, 2, 2);

  int winner = checkWin(board);
  if (winner) {
    printf("The winner is: %d\n", winner);
  } else {
    printf("It's a draw.\n");
  }

  return 0;
}