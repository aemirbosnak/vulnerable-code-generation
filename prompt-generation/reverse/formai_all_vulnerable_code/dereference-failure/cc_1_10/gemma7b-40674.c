//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void create_board(int **board) {
  board = (int *)malloc(MAX_SIZE * MAX_SIZE * sizeof(int));
  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      board[i][j] = 0;
    }
  }
}

void display_board(int **board) {
  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

void update_board(int **board) {
  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      int neighbors = 0;
      if (i > 0) neighbors++;
      if (i < MAX_SIZE - 1) neighbors++;
      if (j > 0) neighbors++;
      if (j < MAX_SIZE - 1) neighbors++;

      if (board[i][j] == 1 && neighbors < 2) board[i][j] = 0;
      if (board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
    }
  }
}

int main() {
  int **board;
  create_board(&board);

  // Seed the board with random values
  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      board[i][j] = rand() % 2;
    }
  }

  display_board(board);

  update_board(board);

  display_board(board);

  return 0;
}