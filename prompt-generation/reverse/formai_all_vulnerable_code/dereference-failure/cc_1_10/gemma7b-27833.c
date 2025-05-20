//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

void game_of_life(int **board, int size) {
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      int neighbors = 0;
      // Check the four neighbors
      if (r > 0) neighbors++;
      if (r < size - 1) neighbors++;
      if (c > 0) neighbors++;
      if (c < size - 1) neighbors++;

      // Apply the Game of Life rules
      if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
      else if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
    }
  }
}

int main() {
  // Create a 2D array to store the game board
  int **board = NULL;
  int size = 5;
  board = (int **)malloc(size * sizeof(int *));
  for (int r = 0; r < size; r++) {
    board[r] = (int *)malloc(size * sizeof(int));
  }

  // Initialize the game board with some random cells
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      board[r][c] = rand() % 2;
    }
  }

  // Play the game for 10 generations
  for (int gen = 0; gen < 10; gen++) {
    game_of_life(board, size);
  }

  // Print the final game board
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      printf("%d ", board[r][c]);
    }
    printf("\n");
  }

  // Free the memory allocated for the game board
  for (int r = 0; r < size; r++) {
    free(board[r]);
  }
  free(board);

  return 0;
}