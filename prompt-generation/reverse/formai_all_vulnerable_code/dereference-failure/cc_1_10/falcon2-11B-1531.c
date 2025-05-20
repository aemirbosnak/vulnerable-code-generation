//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct {
  int x;
  int y;
} Coordinate;

void print_board(int* board, int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      printf("%d ", board[x + y * width]);
    }
    printf("\n");
  }
}

int is_alive(int x, int y, int* board, int width, int height) {
  return board[x + y * width];
}

void update_cell(int x, int y, int* board, int width, int height) {
  int neighbors = 0;
  int alive = is_alive(x, y, board, width, height);

  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      if (dx == 0 && dy == 0) continue;
      int nx = x + dx;
      int ny = y + dy;

      if (nx >= 0 && nx < width && ny >= 0 && ny < height && is_alive(nx, ny, board, width, height)) {
        neighbors++;
      }
    }
  }

  if (alive == 1 && neighbors < 2 && neighbors > 3) {
    board[x + y * width] = 0;
  } else if (alive == 0 && neighbors == 3) {
    board[x + y * width] = 1;
  }
}

int main() {
  int* board = (int*)malloc(WIDTH * HEIGHT * sizeof(int));
  for (int x = 0; x < WIDTH; x++) {
    for (int y = 0; y < HEIGHT; y++) {
      board[x + y * WIDTH] = rand() % 2;
    }
  }

  printf("Initial state:\n");
  print_board(board, WIDTH, HEIGHT);
  printf("\n");

  for (int i = 0; i < 100; i++) {
    for (int y = 0; y < HEIGHT; y++) {
      for (int x = 0; x < WIDTH; x++) {
        update_cell(x, y, board, WIDTH, HEIGHT);
      }
    }

    printf("Generation %d:\n", i);
    print_board(board, WIDTH, HEIGHT);
    printf("\n");
  }

  return 0;
}