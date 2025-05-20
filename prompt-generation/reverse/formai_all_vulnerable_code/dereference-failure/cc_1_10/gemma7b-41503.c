//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

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

int count_alive(int **board, int r, int c) {
  int alive = 0;
  for (int dr = -1; dr <= 1; dr++) {
    for (int dc = -1; dc <= 1; dc++) {
      if (r + dr >= 0 && r + dr < MAX_SIZE && c + dc >= 0 && c + dc < MAX_SIZE && board[r + dr][c + dc] == 1) {
        alive++;
      }
    }
  }
  return alive;
}

void update_board(int **board, int size) {
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      int alive = count_alive(board, r, c);
      if (alive < 2) {
        board[r][c] = 0;
      } else if (alive == 2) {
        board[r][c] = 1;
      }
    }
  }
}

int main() {
  int size = MAX_SIZE;
  int **board = NULL;
  initialize_board(board, size);

  board[5][5] = 1;
  board[5][6] = 1;
  board[6][5] = 1;
  board[6][6] = 1;

  print_board(board, size);
  update_board(board, size);
  print_board(board, size);

  free(board);
  return 0;
}