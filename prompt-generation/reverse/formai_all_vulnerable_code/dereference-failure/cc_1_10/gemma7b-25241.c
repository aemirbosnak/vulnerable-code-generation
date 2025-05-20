//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

void drawBoard(int **board, int size) {
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      printf("%c ", board[r][c] ? '#' : '.');
    }
    printf("\n");
  }
}

int main() {
  int size = 5;
  int **board = (int **)malloc(size * sizeof(int *));
  for (int r = 0; r < size; r++) {
    board[r] = (int *)malloc(size * sizeof(int));
  }

  // Initialize the board
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      board[r][c] = 0;
    }
  }

  // Create a random pattern
  board[2][2] = 1;
  board[2][3] = 1;
  board[3][2] = 1;
  board[3][3] = 1;

  // Simulate Game of Life
  for (int t = 0; t < 10; t++) {
    drawBoard(board, size);

    // Calculate the next generation
    for (int r = 0; r < size; r++) {
      for (int c = 0; c < size; c++) {
        int neighbors = 0;
        if (r > 0) neighbors++;
        if (r < size - 1) neighbors++;
        if (c > 0) neighbors++;
        if (c < size - 1) neighbors++;

        if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
        if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
      }
    }
  }

  drawBoard(board, size);

  free(board);

  return 0;
}