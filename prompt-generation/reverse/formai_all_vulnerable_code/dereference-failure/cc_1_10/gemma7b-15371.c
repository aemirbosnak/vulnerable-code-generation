//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void initializeBoard(int **board, int size);
void printBoard(int **board, int size);
int simulateGame(int **board, int size);

int main() {
  int **board;
  int size = MAX_SIZE;

  board = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < size; i++) {
    board[i] = (int *)malloc(size * sizeof(int));
  }

  initializeBoard(board, size);
  printBoard(board, size);

  simulateGame(board, size);

  printBoard(board, size);

  free(board);

  return 0;
}

void initializeBoard(int **board, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      board[i][j] = 0;
    }
  }
}

void printBoard(int **board, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

int simulateGame(int **board, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      int numNeighbors = 0;
      if (i > 0) numNeighbors++;
      if (i < size - 1) numNeighbors++;
      if (j > 0) numNeighbors++;
      if (j < size - 1) numNeighbors++;

      if (board[i][j] == 1 && numNeighbors < 2) board[i][j] = 0;
      if (board[i][j] == 0 && numNeighbors == 3) board[i][j] = 1;
    }
  }

  return 0;
}