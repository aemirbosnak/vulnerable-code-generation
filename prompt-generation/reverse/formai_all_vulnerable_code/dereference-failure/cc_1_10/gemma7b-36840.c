//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 20

void draw_board(int **board) {
  for (int r = 0; r < HEIGHT; r++) {
    for (int c = 0; c < WIDTH; c++) {
      printf("%c ", board[r][c] ? '#' : '.');
    }
    printf("\n");
  }
}

int main() {
  int **board = (int **)malloc(HEIGHT * sizeof(int *));
  for (int r = 0; r < HEIGHT; r++) {
    board[r] = (int *)malloc(WIDTH * sizeof(int));
  }

  // Initialize the board
  for (int r = 0; r < HEIGHT; r++) {
    for (int c = 0; c < WIDTH; c++) {
      board[r][c] = 0;
    }
  }

  // Place some random seeds
  board[10][10] = 1;
  board[12][12] = 1;
  board[14][14] = 1;

  // Game loop
  int generation = 0;
  while (1) {
    draw_board(board);
    printf("Generation: %d\n", generation);

    // Calculate the next generation
    int **next_board = (int **)malloc(HEIGHT * sizeof(int *));
    for (int r = 0; r < HEIGHT; r++) {
      next_board[r] = (int *)malloc(WIDTH * sizeof(int));
    }

    for (int r = 0; r < HEIGHT; r++) {
      for (int c = 0; c < WIDTH; c++) {
        int neighbors = 0;
        for (int dr = -1; dr <= 1; dr++) {
          for (int dc = -1; dc <= 1; dc++) {
            if (board[r + dr][c + dc] && board[r + dr][c + dc] != 0) {
              neighbors++;
            }
          }
        }

        next_board[r][c] = neighbors > 1 && neighbors < 4 ? 1 : 0;
      }
    }

    free(board);
    board = next_board;
    generation++;

    // Check if the game is over
    if (board[0][0] == 1) {
      draw_board(board);
      printf("Game over!\n");
      break;
    }
  }

  return 0;
}