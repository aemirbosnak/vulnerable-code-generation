//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: standalone
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct Cell {
  int x;
  int y;
  int state;
} Cell;

void initialize_board(Cell **board) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      board[y][x].x = x;
      board[y][x].y = y;
      board[y][x].state = 0;
    }
  }
}

void print_board(Cell **board) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      printf("%d ", board[y][x].state);
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));

  Cell **board = (Cell **)malloc(HEIGHT * sizeof(Cell *) + WIDTH * sizeof(Cell));
  initialize_board(board);

  // Simulate game of life
  for (int generation = 0; generation < 10; generation++) {
    print_board(board);

    // Calculate next generation
    for (int y = 0; y < HEIGHT; y++) {
      for (int x = 0; x < WIDTH; x++) {
        int neighbors = 0;
        for (int dy = -1; dy <= 1; dy++) {
          for (int dx = -1; dx <= 1; dx++) {
            if (board[y + dy][x + dx].state) {
              neighbors++;
            }
          }
        }

        if (board[y][x].state == 1 && neighbors < 2) {
          board[y][x].state = 0;
        } else if (board[y][x].state == 0 && neighbors == 3) {
          board[y][x].state = 1;
        }
      }
    }

    // Print next generation
    print_board(board);
  }

  free(board);

  return 0;
}