//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

void drawBoard(int **board) {
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      printf("%c ", board[r][c] ? '#' : '.');
    }
    printf("\n");
  }
}

void simulateGame(int **board) {
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      int neighbours = 0;
      if (board[r - 1][c] == '#') neighbours++;
      if (board[r + 1][c] == '#') neighbours++;
      if (board[r][c - 1] == '#') neighbours++;
      if (board[r][c + 1] == '#') neighbours++;

      if (board[r][c] == '#' && neighbours < 2) board[r][c] = '.';
      if (board[r][c] == '.' && neighbours == 3) board[r][c] = '#';
    }
  }
}

int main() {
  int **board = (int **)malloc(ROWS * sizeof(int *));
  for (int r = 0; r < ROWS; r++) {
    board[r] = (int *)malloc(COLS * sizeof(int));
  }

  // Initialize the board
  board[1][1] = board[2][2] = board[3][2] = '#';

  drawBoard(board);

  // Simulate the game for 10 generations
  for (int gen = 0; gen < 10; gen++) {
    simulateGame(board);
    drawBoard(board);
  }

  // Free the memory
  for (int r = 0; r < ROWS; r++) {
    free(board[r]);
  }
  free(board);

  return 0;
}