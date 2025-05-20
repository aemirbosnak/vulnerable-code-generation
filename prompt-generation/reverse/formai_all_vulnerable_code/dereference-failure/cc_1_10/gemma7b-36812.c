//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void drawBoard(int **board, int size) {
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      printf("%c ", board[r][c] ? '#' : '.');
    }
    printf("\n");
  }
}

int main() {
  int size = MAX;
  int **board = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < size; i++) {
    board[i] = (int *)malloc(size * sizeof(int));
  }

  // Randomly initialize the board
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      board[r][c] = rand() % 2;
    }
  }

  drawBoard(board, size);

  // Simulate 20 generations
  for (int g = 0; g < 20; g++) {
    // Calculate the next generation
    int **nextBoard = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
      nextBoard[i] = (int *)malloc(size * sizeof(int));
    }

    for (int r = 0; r < size; r++) {
      for (int c = 0; c < size; c++) {
        int neighbors = 0;
        for (int dr = -1; dr <= 1; dr++) {
          for (int dc = -1; dc <= 1; dc++) {
            if (board[r + dr][c + dc] && board[r + dr][c + dc] != 0) {
              neighbors++;
            }
          }
        }

        nextBoard[r][c] = (neighbors >= 2) ? 1 : 0;
      }
    }

    drawBoard(nextBoard, size);

    // Free the memory
    for (int i = 0; i < size; i++) {
      free(board[i]);
    }
    free(board);

    board = nextBoard;
  }

  drawBoard(board, size);

  free(board);

  return 0;
}