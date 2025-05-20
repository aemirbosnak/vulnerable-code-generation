//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 20

void initializeBoard(int **board) {
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      board[r][c] = 0;
    }
  }
}

void printBoard(int **board) {
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      printf("%d ", board[r][c]);
    }
    printf("\n");
  }
}

void calculateNeighbors(int **board, int r, int c) {
  int neighbors = 0;
  // Check the four directions
  if (r - 1 >= 0) neighbors++;
  if (r + 1 < ROWS) neighbors++;
  if (c - 1 >= 0) neighbors++;
  if (c + 1 < COLS) neighbors++;

  board[r][c] = neighbors;
}

int main() {
  int **board = (int **)malloc(ROWS * sizeof(int *));
  for (int r = 0; r < ROWS; r++) {
    board[r] = (int *)malloc(COLS * sizeof(int));
  }

  initializeBoard(board);
  printBoard(board);

  calculateNeighbors(board, 5, 5);
  printBoard(board);

  free(board);

  return 0;
}