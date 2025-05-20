//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void initialize_board(int **board, int size) {
  board = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < size; i++) {
    board[i] = (int *)malloc(size * sizeof(int));
    for (int j = 0; j < size; j++) {
      board[i][j] = 0;
    }
  }
}

void print_board(int **board, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

int count_alive(int **board, int i, int j, int size) {
  int alive = 0;
  for (int r = -1; r <= 1; r++) {
    for (int c = -1; c <= 1; c++) {
      if (r == 0 && c == 0) continue;
      if (i + r < 0 || i + r >= size) continue;
      if (j + c < 0 || j + c >= size) continue;
      if (board[i + r][j + c] == 1) alive++;
    }
  }
  return alive;
}

void update_board(int **board, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      int alive = count_alive(board, i, j, size);
      if (alive < 2) board[i][j] = 0;
      else if (alive == 2) board[i][j] = 1;
    }
  }
}

int main() {
  int size = MAX_SIZE;
  int **board;
  initialize_board(board, size);

  // Example game setup
  board[0][0] = 1;
  board[0][1] = 1;
  board[1][0] = 1;
  board[1][1] = 1;

  print_board(board, size);

  update_board(board, size);

  print_board(board, size);

  return 0;
}