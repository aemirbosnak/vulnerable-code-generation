//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void draw_board(int **board, int size) {
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      printf("%c ", board[r][c]);
    }
    printf("\n");
  }
}

int main() {
  int size = 5;
  int **board = malloc(size * sizeof(int *)), **neigh = malloc(size * sizeof(int *)), **next_board = malloc(size * sizeof(int *));

  for (int i = 0; i < size; i++) {
    board[i] = malloc(size * sizeof(int));
    neigh[i] = malloc(size * sizeof(int));
    next_board[i] = malloc(size * sizeof(int));
  }

  time_t t = time(NULL);
  srand(t);

  // Initialize the board randomly
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      board[r][c] = rand() % 2;
    }
  }

  // Calculate neighbors for each cell
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      neigh[r][c] = 0;
      if (r > 0) neigh[r][c] += board[r - 1][c];
      if (r < size - 1) neigh[r][c] += board[r + 1][c];
      if (c > 0) neigh[r][c] += board[r][c - 1];
      if (c < size - 1) neigh[r][c] += board[r][c + 1];
    }
  }

  // Update the next board based on the rules of life
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      next_board[r][c] = 0;
      if (neigh[r][c] < 2) next_board[r][c] = 0;
      if (neigh[r][c] == 2) next_board[r][c] = 1;
      if (neigh[r][c] > 3) next_board[r][c] = 0;
    }
  }

  // Draw the board
  draw_board(board, size);

  // Transition to the next generation
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      board[r][c] = next_board[r][c];
    }
  }

  draw_board(board, size);

  free(board);
  free(neigh);
  free(next_board);

  return 0;
}