//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void draw_board(int **board) {
  for (int r = 0; r < MAX_SIZE; r++) {
    for (int c = 0; c < MAX_SIZE; c++) {
      printf("%c ", board[r][c] ? '*' : ' ');
    }
    printf("\n");
  }
}

int main() {
  int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
  for (int r = 0; r < MAX_SIZE; r++) {
    board[r] = (int *)malloc(MAX_SIZE * sizeof(int));
  }

  // Initial board setup
  board[5][5] = board[5][6] = board[6][5] = board[6][6] = 1;

  // Game loop
  int generation = 0;
  while (1) {
    draw_board(board);
    printf("Generation: %d\n", generation);

    // Calculate next generation
    for (int r = 0; r < MAX_SIZE; r++) {
      for (int c = 0; c < MAX_SIZE; c++) {
        int neighbors = 0;
        for (int dr = -1; dr <= 1; dr++) {
          for (int dc = -1; dc <= 1; dc++) {
            if (board[r + dr][c + dc] && board[r + dr][c + dc] != 0) {
              neighbors++;
            }
          }
        }

        if (board[r][c] == 1 && neighbors < 2) {
          board[r][c] = 0;
        } else if (board[r][c] == 0 && neighbors == 3) {
          board[r][c] = 1;
        }
      }
    }

    generation++;

    // Check if game is over
    if (board[0][0] == 0 || board[MAX_SIZE - 1][MAX_SIZE - 1] == 0) {
      break;
    }
  }

  draw_board(board);
  printf("Game Over!\n");

  // Free memory
  for (int r = 0; r < MAX_SIZE; r++) {
    free(board[r]);
  }
  free(board);

  return 0;
}