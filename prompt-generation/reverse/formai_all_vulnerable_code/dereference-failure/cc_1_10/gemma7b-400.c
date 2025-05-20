//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void drawBoard(int **board) {
  for (int r = 0; r < MAX; r++) {
    for (int c = 0; c < MAX; c++) {
      printf("%c ", board[r][c] ? 'O' : '.');
    }
    printf("\n");
  }
}

int main() {
  int **board = (int **)malloc(MAX * sizeof(int *));
  for (int r = 0; r < MAX; r++) {
    board[r] = (int *)malloc(MAX * sizeof(int));
  }

  // Initial board setup
  board[5][5] = 1;
  board[5][6] = 1;
  board[6][5] = 1;
  board[6][6] = 1;

  // Game loop
  int generation = 0;
  while (1) {
    drawBoard(board);
    printf("Generation: %d\n", generation);

    // Calculate next generation
    int **nextBoard = (int **)malloc(MAX * sizeof(int *));
    for (int r = 0; r < MAX; r++) {
      nextBoard[r] = (int *)malloc(MAX * sizeof(int));
    }

    for (int r = 0; r < MAX; r++) {
      for (int c = 0; c < MAX; c++) {
        int aliveNeighbors = 0;
        for (int dr = -1; dr <= 1; dr++) {
          for (int dc = -1; dc <= 1; dc++) {
            if (board[r + dr][c + dc] && board[r + dr][c + dc] != 0) {
              aliveNeighbors++;
            }
          }
        }

        nextBoard[r][c] = aliveNeighbors >= 2 ? 1 : 0;
      }
    }

    // Free previous board and move to next generation
    for (int r = 0; r < MAX; r++) {
      free(board[r]);
    }
    free(board);

    board = nextBoard;
    generation++;

    // Check if game ends
    if (board[0][0] == 0) {
      break;
    }
  }

  drawBoard(board);
  printf("Final board:\n");

  return 0;
}