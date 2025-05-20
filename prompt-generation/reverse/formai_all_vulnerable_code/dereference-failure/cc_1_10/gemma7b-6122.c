//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: dynamic
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

void initBoard(Cell **board) {
  int i, j;
  board = (Cell **)malloc(WIDTH * HEIGHT * sizeof(Cell));
  for (i = 0; i < WIDTH; i++) {
    for (j = 0; j < HEIGHT; j++) {
      board[i][j].x = i;
      board[i][j].y = j;
      board[i][j].state = 0;
    }
  }
}

void drawBoard(Cell **board) {
  int i, j;
  for (i = 0; i < WIDTH; i++) {
    for (j = 0; j < HEIGHT; j++) {
      switch (board[i][j].state) {
        case 0:
          printf(".");
          break;
        case 1:
          printf("o");
          break;
      }
    }
    printf("\n");
  }
}

void updateBoard(Cell **board) {
  int i, j, x, y, neighbor_count;
  for (i = 0; i < WIDTH; i++) {
    for (j = 0; j < HEIGHT; j++) {
      neighbor_count = 0;
      for (x = -1; x <= 1; x++) {
        for (y = -1; y <= 1; y++) {
          if (x == 0 && y == 0) {
            continue;
          }
          if (board[i + x][j + y].state == 1) {
            neighbor_count++;
          }
        }
      }
      if (board[i][j].state == 1 && neighbor_count < 2) {
        board[i][j].state = 0;
      } else if (board[i][j].state == 0 && neighbor_count == 3) {
        board[i][j].state = 1;
      }
    }
  }
}

int main() {
  srand(time(NULL));
  Cell **board;
  initBoard(&board);
  drawBoard(board);
  updateBoard(board);
  drawBoard(board);

  return 0;
}