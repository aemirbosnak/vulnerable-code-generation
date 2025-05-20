//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void drawBoard(int **board) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int **board = (int **)malloc(5 * sizeof(int *));
  for (int i = 0; i < 5; i++) {
    board[i] = (int *)malloc(5 * sizeof(int));
  }

  // Initialize the board
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      board[i][j] = 0;
    }
  }

  // Place some living cells
  board[2][2] = 1;
  board[3][2] = 1;
  board[2][3] = 1;

  drawBoard(board);

  // Simulate game of life
  for (int t = 0; t < 10; t++) {
    drawBoard(board);
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        int neighbors = 0;
        if (board[i - 1][j] == 1) neighbors++;
        if (board[i + 1][j] == 1) neighbors++;
        if (board[i][j - 1] == 1) neighbors++;
        if (board[i][j + 1] == 1) neighbors++;

        if (board[i][j] == 1 && neighbors < 2) board[i][j] = 0;
        if (board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
      }
    }
  }

  drawBoard(board);

  free(board);

  return 0;
}