//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: automated
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

int count_alive_neighbors(int **board, int i, int j, int size) {
  int alive_neighbors = 0;
  for (int r = -1; r <= 1; r++) {
    for (int c = -1; c <= 1; c++) {
      if (i + r >= 0 && i + r < size && j + c >= 0 && j + c < size && board[i + r * size + j + c] == 1) {
        alive_neighbors++;
      }
    }
  }
  return alive_neighbors;
}

void update_board(int **board, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      int alive_neighbors = count_alive_neighbors(board, i, j, size);
      if (alive_neighbors < 2) {
        board[i * size + j] = 0;
      } else if (alive_neighbors == 2) {
        board[i * size + j] = 1;
      }
    }
  }
}

int main() {
  int size = MAX_SIZE;
  int **board;
  initialize_board(board, size);
  board[0][0] = board[1][1] = board[2][2] = 1;

  print_board(board, size);
  update_board(board, size);
  print_board(board, size);

  return 0;
}