//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: artistic
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct Cell {
  int x, y;
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
          printf("O");
          break;
        case 2:
          printf("X");
          break;
      }
    }
    printf("\n");
  }
}

void update_board(Cell **board) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      int neighbors = 0;
      for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
          if (board[x + dx][y + dy].state == 1) {
            neighbors++;
          }
        }
      }
      if (board[x][y].state == 1 && neighbors < 2) {
        board[x][y].state = 0;
      } else if (board[x][y].state == 0 && neighbors == 3) {
        board[x][y].state = 1;
      }
    }
  }
}

int main() {
  srand(time(NULL));
  Cell **board = (Cell **)malloc(WIDTH * HEIGHT * sizeof(Cell));
  for (int y = 0; y < HEIGHT; y++) {
    board[y] = (Cell *)malloc(WIDTH * sizeof(Cell));
    for (int x = 0; x < WIDTH; x++) {
      board[y][x].x = x;
      board[y][x].y = y;
      board[y][x].state = rand() % 2;
    }
  }

  int generation = 0;
  while (1) {
    draw_board(board);
    update_board(board);
    generation++;
    if (generation == 10) {
      break;
    }
  }

  draw_board(board);
  printf("Generation: %d\n", generation);

  free(board);
  return 0;
}