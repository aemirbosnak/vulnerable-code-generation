//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

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

int count_neighbors(int **board, int i, int j) {
  int neighbors = 0;
  if (i > 0) neighbors++;
  if (i < MAX_SIZE - 1) neighbors++;
  if (j > 0) neighbors++;
  if (j < MAX_SIZE - 1) neighbors++;
  return neighbors;
}

void update_board(int **board, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      int neighbors = count_neighbors(board, i, j);
      if (neighbors == 3) board[i * size + j] = 1;
      else if (neighbors == 2) board[i * size + j] = 0;
    }
  }
}

int main() {
  int **board;
  initialize_board(board, MAX_SIZE);
  board[0][0] = 1;
  board[0][1] = 1;
  board[1][0] = 1;
  board[1][1] = 1;

  print_board(board, MAX_SIZE);

  update_board(board, MAX_SIZE);

  print_board(board, MAX_SIZE);

  return 0;
}