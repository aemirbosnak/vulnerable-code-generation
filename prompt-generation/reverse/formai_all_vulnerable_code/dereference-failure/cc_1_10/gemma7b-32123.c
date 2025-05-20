//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

void initialize_board(int **board, int size) {
  board = (int *)malloc(size * size * sizeof(int));
  for (int i = 0; i < size * size; i++) {
    board[i] = 0;
  }
}

void print_board(int **board, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", board[i * size + j]);
    }
    printf("\n");
  }
}

void calculate_neighbors(int **board, int size, int i, int j) {
  int neighbors = 0;
  for (int x = -1; x <= 1; x++) {
    for (int y = -1; y <= 1; y++) {
      if (x == 0 && y == 0) {
        continue;
      }
      if (i + x >= 0 && i + x < size && j + y >= 0 && j + y < size) {
        neighbors++;
      }
    }
  }
  board[i * size + j] = neighbors;
}

int main() {
  int size = 5;
  int **board;

  initialize_board(board, size);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      calculate_neighbors(board, size, i, j);
    }
  }

  print_board(board, size);

  free(board);

  return 0;
}