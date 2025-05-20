//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct Cell {
  int x;
  int y;
  int state;
} Cell;

void draw_board(Cell **board) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      switch (board[x][y].state) {
        case 0:
          printf(" ");
          break;
        case 1:
          printf("o");
          break;
        case 2:
          printf("x");
          break;
      }
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));

  Cell **board = (Cell **)malloc(WIDTH * HEIGHT * sizeof(Cell));
  for (int y = 0; y < HEIGHT; y++) {
    board = (Cell *)realloc(board, WIDTH * (y + 1) * sizeof(Cell));
    for (int x = 0; x < WIDTH; x++) {
      board[x][y].x = x;
      board[x][y].y = y;
      board[x][y].state = rand() % 3;
    }
  }

  draw_board(board);

  // Game loop
  int generation = 0;
  while (1) {
    draw_board(board);
    printf("Generation: %d\n", generation++);

    // Calculate next generation
    Cell **next_board = (Cell **)malloc(WIDTH * HEIGHT * sizeof(Cell));
    for (int y = 0; y < HEIGHT; y++) {
      next_board = (Cell *)realloc(next_board, WIDTH * (y + 1) * sizeof(Cell));
      for (int x = 0; x < WIDTH; x++) {
        int num_alive = 0;
        for (int dy = -1; dy <= 1; dy++) {
          for (int dx = -1; dx <= 1; dx++) {
            if (board[x + dx][y + dy].state == 1) {
              num_alive++;
            }
          }
        }

        next_board[x][y].state = (num_alive == 2) || (num_alive == 3) ? 1 : 0;
      }
    }

    free(board);
    board = next_board;
  }

  return 0;
}