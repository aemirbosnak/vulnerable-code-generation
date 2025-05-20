//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void initialize_board(int **board, int size) {
  board = malloc(size * size * sizeof(int));
  for (int i = 0; i < size * size; i++) {
    board[i] = 0;
  }
}

int get_neighbor_count(int x, int y, int **board, int size) {
  int count = 0;
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      if (x + dx >= 0 && x + dx < size && y + dy >= 0 && y + dy < size && board[x + dx][y + dy] != 0) {
        count++;
      }
    }
  }
  return count;
}

void update_board(int **board, int size) {
  for (int x = 0; x < size; x++) {
    for (int y = 0; y < size; y++) {
      int neighbors = get_neighbor_count(x, y, board, size);
      if (neighbors == 3) {
        board[x][y] = 1;
      } else if (neighbors == 2) {
        board[x][y] = 0;
      }
    }
  }
}

int main() {
  int size = MAX_SIZE;
  int **board = NULL;
  initialize_board(board, size);

  // Seed the board with some random live cells
  board[5][5] = 1;
  board[2][2] = 1;
  board[4][2] = 1;

  // Run the game for a few generations
  for (int generation = 0; generation < 10; generation++) {
    update_board(board, size);
  }

  // Print the final board
  for (int x = 0; x < size; x++) {
    for (int y = 0; y < size; y++) {
      printf("%d ", board[x][y]);
    }
    printf("\n");
  }

  return 0;
}