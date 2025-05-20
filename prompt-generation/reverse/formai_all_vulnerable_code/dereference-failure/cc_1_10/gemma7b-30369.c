//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct Cell {
  int x, y;
  int state;
} Cell;

void initialize_board(Cell **board) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      board[x][y].x = x;
      board[x][y].y = y;
      board[x][y].state = 0;
    }
  }
}

void print_board(Cell **board) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      printf("%d ", board[x][y].state);
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));

  Cell **board = (Cell **)malloc(WIDTH * HEIGHT * sizeof(Cell));
  initialize_board(board);

  // Randomly set some cells to alive
  for (int i = 0; i < 10; i++) {
    board[rand() % WIDTH][rand() % HEIGHT].state = 1;
  }

  print_board(board);

  // Simulate game of life
  for (int t = 0; t < 10; t++) {
    for (int y = 0; y < HEIGHT; y++) {
      for (int x = 0; x < WIDTH; x++) {
        int alive_neighbors = 0;
        if (board[x][y].state == 1) {
          alive_neighbors++;
        }
        if (board[x][y].state == 0 && alive_neighbors == 3) {
          board[x][y].state = 1;
        } else if (board[x][y].state == 1 && (alive_neighbors < 2 || alive_neighbors > 3)) {
          board[x][y].state = 0;
        }
      }
    }
    print_board(board);
  }

  free(board);

  return 0;
}