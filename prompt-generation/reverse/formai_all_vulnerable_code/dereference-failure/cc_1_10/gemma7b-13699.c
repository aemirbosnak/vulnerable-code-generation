//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: calm
#include <stdio.h>
#include <stdlib.h>

void drawBoard(int **board, int size) {
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      printf("%c ", board[r][c]);
    }
    printf("\n");
  }
}

int main() {
  int size = 5;
  int **board = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < size; i++) {
    board[i] = (int *)malloc(size * sizeof(int));
  }

  // Initialize the board
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      board[r][c] = 0;
    }
  }

  // Place some seeds
  board[2][2] = 1;
  board[3][3] = 1;

  drawBoard(board, size);

  // Simulate life
  for (int t = 0; t < 10; t++) {
    drawBoard(board, size);
    for (int r = 0; r < size; r++) {
      for (int c = 0; c < size; c++) {
        int alive = 0;
        if (board[r - 1][c] == 1) alive++;
        if (board[r + 1][c] == 1) alive++;
        if (board[r][c - 1] == 1) alive++;
        if (board[r][c + 1] == 1) alive++;
        if (board[r][c] == 1 && alive < 2) board[r][c] = 0;
        else if (board[r][c] == 0 && alive == 3) board[r][c] = 1;
      }
    }
  }

  drawBoard(board, size);

  free(board);

  return 0;
}