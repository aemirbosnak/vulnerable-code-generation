//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: statistical
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY_SPOT -1

void initializeBoard(int **board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = EMPTY_SPOT;
    }
  }
}

int isBoardFull(int **board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == EMPTY_SPOT) {
        return 0;
      }
    }
  }
  return 1;
}

int getMove(int **board) {
  srand(time(NULL));
  int row = rand() % BOARD_SIZE;
  int col = rand() % BOARD_SIZE;
  while (board[row][col] != EMPTY_SPOT) {
    row = rand() % BOARD_SIZE;
    col = rand() % BOARD_SIZE;
  }
  return board[row][col];
}

int main() {
  int **board = (int **)malloc(BOARD_SIZE * sizeof(int *));
  initializeBoard(board);

  int move = getMove(board);
  board[move] = 2;

  if (isBoardFull(board)) {
    printf("It's a draw!");
  } else {
    printf("Player 2 won!");
  }

  free(board);
  return 0;
}