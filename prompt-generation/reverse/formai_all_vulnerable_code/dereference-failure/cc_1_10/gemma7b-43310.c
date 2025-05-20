//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void initializeBoard(int **board, int size) {
  board = (int *)malloc(size * size * sizeof(int));
  for (int i = 0; i < size * size; i++) {
    board[i] = 0;
  }
}

void printBoard(int **board, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", board[i * size + j]);
    }
    printf("\n");
  }
}

void calculateNextState(int **board, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      int neighbours = 0;
      if (i > 0) neighbours++;
      if (i < size - 1) neighbours++;
      if (j > 0) neighbours++;
      if (j < size - 1) neighbours++;

      if (board[i * size + j] == 1 && neighbours < 2) board[i * size + j] = 0;
      if (board[i * size + j] == 0 && neighbours == 3) board[i * size + j] = 1;
    }
  }
}

int main() {
  int size = 5;
  int **board;

  initializeBoard(board, size);
  board[1][1] = board[2][2] = board[2][3] = 1;

  printBoard(board, size);

  calculateNextState(board, size);

  printBoard(board, size);

  return 0;
}