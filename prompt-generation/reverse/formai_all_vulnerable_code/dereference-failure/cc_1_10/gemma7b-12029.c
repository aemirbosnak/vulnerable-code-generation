//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void initializeBoard(int **board, int size) {
  board = (int *)malloc(size * size * sizeof(int));
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      board[r][c] = 0;
    }
  }
}

void printBoard(int **board, int size) {
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      printf("%d ", board[r][c]);
    }
    printf("\n");
  }
}

int calculateNeighbors(int **board, int r, int c) {
  int neighbors = 0;
  if (r - 1 >= 0) neighbors++;
  if (r + 1 < MAX_SIZE) neighbors++;
  if (c - 1 >= 0) neighbors++;
  if (c + 1 < MAX_SIZE) neighbors++;
  return neighbors;
}

void updateBoard(int **board, int size) {
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      int neighbors = calculateNeighbors(board, r, c);
      if (neighbors == 3) board[r][c] = 1;
      else board[r][c] = 0;
    }
  }
}

int main() {
  int size = MAX_SIZE;
  int **board;
  initializeBoard(board, size);
  board[0][0] = 1;
  board[1][1] = 1;
  board[2][2] = 1;
  printBoard(board, size);
  updateBoard(board, size);
  printBoard(board, size);
  return 0;
}