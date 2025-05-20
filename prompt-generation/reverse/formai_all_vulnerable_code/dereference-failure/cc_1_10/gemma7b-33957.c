//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void initializeBoard(int **board, int size) {
  board = (int *)malloc(size * size * sizeof(int));
  for (int i = 0; i < size * size; i++) {
    board[i] = 0;
  }
}

void playGame(int **board, int size) {
  for (int iter = 0; iter < 5; iter++) {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        int neighbors = 0;
        if (i > 0) neighbors++;
        if (i < size - 1) neighbors++;
        if (j > 0) neighbors++;
        if (j < size - 1) neighbors++;

        if (board[i * size + j] == 1 && neighbors < 2) {
          board[i * size + j] = 0;
        } else if (board[i * size + j] == 0 && neighbors == 3) {
          board[i * size + j] = 1;
        }
      }
    }

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        printf("%d ", board[i * size + j]);
      }
      printf("\n");
    }
  }
}

int main() {
  int size = 10;
  int **board;
  initializeBoard(board, size);

  board[5 * size + 5] = 1;
  board[6 * size + 6] = 1;
  board[7 * size + 7] = 1;

  playGame(board, size);

  return 0;
}