//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

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

int count_neighbors(int **board, int x, int y, int size) {
  int neighbors = 0;
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      if (x + dx >= 0 && x + dx < size && y + dy >= 0 && y + dy < size && board[x + dx][y + dy] == 1) {
        neighbors++;
      }
    }
  }
  return neighbors;
}

void update_board(int **board, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      int neighbors = count_neighbors(board, i, j, size);
      if (neighbors < 2) {
        board[i][j] = 0;
      } else if (neighbors == 2) {
        board[i][j] = 1;
      }
    }
  }
}

int main() {
  int size = MAX_SIZE;
  int **board;
  initialize_board(board, size);

  // Seed the random number generator
  srand(time(NULL));

  // Randomly set some cells to 1
  for (int i = 0; i < size * size; i++) {
    if (rand() % 2 == 0) {
      board[i] = 1;
    }
  }

  print_board(board, size);

  update_board(board, size);

  print_board(board, size);

  return 0;
}