//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void drawBoard(int **board) {
  for (int r = 0; r < MAX_SIZE; r++) {
    for (int c = 0; c < MAX_SIZE; c++) {
      printf("%c ", board[r][c]);
    }
    printf("\n");
  }
}

int main() {
  int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
  for (int r = 0; r < MAX_SIZE; r++) {
    board[r] = (int *)malloc(MAX_SIZE * sizeof(int));
  }

  // Initial board setup
  board[2][2] = 1;
  board[2][3] = 1;
  board[3][2] = 1;
  board[3][3] = 1;

  // Game loop
  int generation = 0;
  while (1) {
    drawBoard(board);
    printf("Generation: %d\n", generation);

    // Calculate next generation
    int **nextBoard = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int r = 0; r < MAX_SIZE; r++) {
      nextBoard[r] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    for (int r = 0; r < MAX_SIZE; r++) {
      for (int c = 0; c < MAX_SIZE; c++) {
        int aliveNeighbors = 0;
        if (board[r - 1][c] == 1) aliveNeighbors++;
        if (board[r + 1][c] == 1) aliveNeighbors++;
        if (board[r][c - 1] == 1) aliveNeighbors++;
        if (board[r][c + 1] == 1) aliveNeighbors++;

        nextBoard[r][c] = (aliveNeighbors == 2) || (aliveNeighbors == 3);
      }
    }

    // Free previous board and copy next generation to current board
    for (int r = 0; r < MAX_SIZE; r++) {
      free(board[r]);
    }
    free(board);

    board = nextBoard;
    generation++;

    // Check if game is over
    if (board[0][0] == 1) {
      drawBoard(board);
      printf("Game Over!\n");
      break;
    }
  }

  return 0;
}