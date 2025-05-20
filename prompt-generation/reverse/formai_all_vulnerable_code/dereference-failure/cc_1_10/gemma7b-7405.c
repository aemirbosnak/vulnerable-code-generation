//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

void drawBoard(int **board, int size) {
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      printf("%c ", board[r][c] == 1 ? 'O' : ' ');
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

  // Place the seed
  board[2][2] = 1;

  // Run the game
  int generation = 0;
  while (board[size - 1][size - 1] != 1) {
    drawBoard(board, size);
    printf("Generation: %d\n", generation++);

    // Calculate the next generation
    for (int r = 0; r < size; r++) {
      for (int c = 0; c < size; c++) {
        int neighbours = 0;
        if (r - 1 >= 0) neighbours++;
        if (r + 1 < size) neighbours++;
        if (c - 1 >= 0) neighbours++;
        if (c + 1 < size) neighbours++;

        if (board[r][c] == 1 && neighbours < 2) board[r][c] = 0;
        else if (board[r][c] == 0 && neighbours == 3) board[r][c] = 1;
      }
    }
  }

  drawBoard(board, size);
  printf("Generation: %d\n", generation);

  free(board);
  return 0;
}