//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define LIVE 1
#define DEAD 0

typedef struct Cell {
  int x;
  int y;
  int state;
} Cell;

void initializeBoard(Cell **board) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      board[i][j].x = i;
      board[i][j].y = j;
      board[i][j].state = DEAD;
    }
  }
}

void printBoard(Cell **board) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (board[i][j].state == LIVE) {
        printf("%c ", '*');
      } else {
        printf("%c ", '.');
      }
    }
    printf("\n");
  }
}

void updateBoard(Cell **board) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      int neighbors = 0;
      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          if (board[i + dx][j + dy].state == LIVE) {
            neighbors++;
          }
        }
      }
      if (board[i][j].state == LIVE && neighbors < 2) {
        board[i][j].state = DEAD;
      } else if (board[i][j].state == DEAD && neighbors == 3) {
        board[i][j].state = LIVE;
      }
    }
  }
}

int main() {
  srand(time(NULL));

  Cell **board = (Cell **)malloc(HEIGHT * sizeof(Cell *) + WIDTH * sizeof(Cell));
  initializeBoard(board);

  for (int t = 0; t < 10; t++) {
    printBoard(board);
    updateBoard(board);
  }

  printBoard(board);

  free(board);

  return 0;
}