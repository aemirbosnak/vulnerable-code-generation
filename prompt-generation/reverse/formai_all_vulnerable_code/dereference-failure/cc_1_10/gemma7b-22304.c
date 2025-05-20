//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void initialize_board(int **board) {
  for (int r = 0; r < MAX_SIZE; r++) {
    for (int c = 0; c < MAX_SIZE; c++) {
      board[r][c] = 0;
    }
  }
}

void draw_board(int **board) {
  for (int r = 0; r < MAX_SIZE; r++) {
    for (int c = 0; c < MAX_SIZE; c++) {
      printf("%d ", board[r][c]);
    }
    printf("\n");
  }
}

int count_neighbors(int **board, int r, int c) {
  int neighbors = 0;
  if (r > 0) neighbors++;
  if (r < MAX_SIZE - 1) neighbors++;
  if (c > 0) neighbors++;
  if (c < MAX_SIZE - 1) neighbors++;
  return neighbors;
}

void update_board(int **board) {
  for (int r = 0; r < MAX_SIZE; r++) {
    for (int c = 0; c < MAX_SIZE; c++) {
      int neighbors = count_neighbors(board, r, c);
      if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
      else if (board[r][c] == 1 && (neighbors < 2 || neighbors > 3)) board[r][c] = 0;
    }
  }
}

int main() {
  int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
  initialize_board(board);

  board[5][5] = 1;
  board[5][6] = 1;
  board[6][5] = 1;
  board[6][6] = 1;

  draw_board(board);

  update_board(board);

  draw_board(board);

  free(board);

  return 0;
}