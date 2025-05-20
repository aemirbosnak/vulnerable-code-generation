//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

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

void calculateNeighbors(int **board, int x, int y, int size) {
  int neighbors = 0;
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      if (x + dx >= 0 && x + dx < size && y + dy >= 0 && y + dy < size && board[x + dx * size + y + dy] == 1) {
        neighbors++;
      }
    }
  }
  board[x * size + y] = neighbors;
}

void updateBoard(int **board, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (board[i * size + j] == 3) {
        board[i * size + j] = 0;
      } else if (board[i * size + j] == 2) {
        board[i * size + j] = 1;
      } else if (board[i * size + j] == 0 && board[i * size + j] < 3) {
        board[i * size + j] = 1;
      }
    }
  }
}

int main() {
  int size = MAX_SIZE;
  int **board = NULL;
  initializeBoard(board, size);

  board[0][0] = 1;
  board[0][1] = 1;
  board[1][0] = 1;
  board[1][1] = 1;

  printBoard(board, size);

  calculateNeighbors(board, 0, 0, size);
  updateBoard(board, size);

  printBoard(board, size);

  return 0;
}