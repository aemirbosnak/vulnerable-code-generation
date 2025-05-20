//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: satisfied
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
  for (int i = 0; i < size; i++) {
    board[i] = (int *)malloc(size * sizeof(int));
  }

  // Initialize the board
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      board[r][c] = 0;
    }
  }

  // Place the seed
  board[2][2] = 1;
  board[2][3] = 1;

  // Game of Life
  int generations = 0;
  while (board[size - 1][size - 1] != 1) {
    drawBoard(board, size);
    printf("Generation: %d\n", generations);

    // Calculate the next generation
    int **nextBoard = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
      nextBoard[i] = (int *)malloc(size * sizeof(int));
    }

    for (int r = 0; r < size; r++) {
      for (int c = 0; c < size; c++) {
        int neighbors = 0;
        if (r - 1 >= 0) neighbors++;
        if (r + 1 < size) neighbors++;
        if (c - 1 >= 0) neighbors++;
        if (c + 1 < size) neighbors++;

        nextBoard[r][c] = (board[r][c] && neighbors >= 2) || neighbors == 3;
      }
    }

    // Free the previous board and move to the next generation
    for (int r = 0; r < size; r++) {
      free(board[r]);
    }
    free(board);

    board = nextBoard;
    generations++;
  }

  drawBoard(board, size);
  printf("Generation: %d\n", generations);

  return 0;
}