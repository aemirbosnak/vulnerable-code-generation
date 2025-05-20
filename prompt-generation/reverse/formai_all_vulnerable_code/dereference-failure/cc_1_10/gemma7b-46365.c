//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: irregular
#include <stdlib.h>
#include <stdio.h>

#define BOARD_SIZE 5

void draw_board(int **board) {
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      printf("%c ", board[r][c] == 1 ? '*' : '.');
    }
    printf("\n");
  }
}

int main() {
  int **board = (int **)malloc(BOARD_SIZE * sizeof(int *));
  for (int r = 0; r < BOARD_SIZE; r++) {
    board[r] = (int *)malloc(BOARD_SIZE * sizeof(int));
  }

  // Initialize the board
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      board[r][c] = 0;
    }
  }

  // Seed the board
  board[2][2] = board[3][2] = board[3][3] = 1;

  // Game loop
  int generation = 0;
  while (1) {
    draw_board(board);
    printf("Generation: %d\n", generation);

    // Calculate the next generation
    int **next_board = (int **)malloc(BOARD_SIZE * sizeof(int *));
    for (int r = 0; r < BOARD_SIZE; r++) {
      next_board[r] = (int *)malloc(BOARD_SIZE * sizeof(int));
    }

    for (int r = 0; r < BOARD_SIZE; r++) {
      for (int c = 0; c < BOARD_SIZE; c++) {
        int neighbors = 0;
        for (int dr = -1; dr <= 1; dr++) {
          for (int dc = -1; dc <= 1; dc++) {
            if (board[r + dr][c + dc] == 1) {
              neighbors++;
            }
          }
        }

        next_board[r][c] = neighbors == 2 || neighbors == 3 ? 1 : 0;
      }
    }

    // Free the old board and allocate the new one
    for (int r = 0; r < BOARD_SIZE; r++) {
      free(board[r]);
    }
    free(board);

    board = next_board;
    next_board = NULL;

    // Check if the game is over
    if (board[0][0] == 1) {
      printf("Game over!\n");
      break;
    }

    generation++;
  }

  return 0;
}