//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawBoard(int **board) {
  for (int r = 0; r < 20; r++) {
    for (int c = 0; c < 20; c++) {
      printf("%c ", board[r][c] ? '#' : '.');
    }
    printf("\n");
  }
}

int main() {
  int **board = (int **)malloc(20 * sizeof(int *));
  for (int r = 0; r < 20; r++) {
    board[r] = (int *)malloc(20 * sizeof(int));
  }

  int seed = time(NULL);
  srand(seed);

  // Initialize the board
  for (int r = 0; r < 20; r++) {
    for (int c = 0; c < 20; c++) {
      board[r][c] = rand() % 2;
    }
  }

  drawBoard(board);

  // Simulate game of life
  for (int t = 0; t < 20; t++) {
    for (int r = 0; r < 20; r++) {
      for (int c = 0; c < 20; c++) {
        int neighbors = 0;
        if (board[r - 1][c] == 1) neighbors++;
        if (board[r + 1][c] == 1) neighbors++;
        if (board[r][c - 1] == 1) neighbors++;
        if (board[r][c + 1] == 1) neighbors++;

        if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
        if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
      }
    }
    drawBoard(board);
  }

  // Free memory
  for (int r = 0; r < 20; r++) {
    free(board[r]);
  }
  free(board);

  return 0;
}