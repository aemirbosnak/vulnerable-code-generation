//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

void initialize_board(int **board, int size) {
  board = (int *)malloc(size * size * sizeof(int));
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      board[r][c] = 0;
    }
  }
}

void print_board(int **board, int size) {
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      printf("%d ", board[r][c]);
    }
    printf("\n");
  }
}

int count_neighbors(int **board, int r, int c) {
  int neighbors = 0;
  if (r - 1) neighbors++;
  if (r + 1) neighbors++;
  if (c - 1) neighbors++;
  if (c + 1) neighbors++;

  return neighbors;
}

void update_board(int **board, int size) {
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      int neighbors = count_neighbors(board, r, c);
      if (neighbors < 2) board[r][c] = 0;
      else if (neighbors == 2) board[r][c] = 1;
      else board[r][c] = 2;
    }
  }
}

int main() {
  int size = MAX_SIZE;
  int **board;

  initialize_board(board, size);

  // Seed the random number generator
  srand(time(NULL));

  // Randomly initialize some cells
  for (int i = 0; i < 10; i++) {
    board[rand() % size][rand() % size] = 1;
  }

  print_board(board, size);

  update_board(board, size);

  print_board(board, size);

  return 0;
}