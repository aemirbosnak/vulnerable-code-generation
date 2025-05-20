//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 20
#define MAX_HEIGHT 20

typedef struct Cell {
  int x;
  int y;
  int state;
} Cell;

void initializeBoard(Cell **board, int width, int height) {
  board = (Cell **)malloc(sizeof(Cell *) * height);
  for (int i = 0; i < height; i++) {
    board[i] = (Cell *)malloc(sizeof(Cell) * width);
    for (int j = 0; j < width; j++) {
      board[i][j].x = j;
      board[i][j].y = i;
      board[i][j].state = 0;
    }
  }
}

void printBoard(Cell **board, int width, int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      switch (board[i][j].state) {
      case 0:
        printf(".");
        break;
      case 1:
        printf("O");
        break;
      case 2:
        printf("#");
        break;
      }
    }
    printf("\n");
  }
}

void calculateNextState(Cell **board, int width, int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int neighbors = 0;
      if (board[i - 1][j].state == 1) neighbors++;
      if (board[i + 1][j].state == 1) neighbors++;
      if (board[i][j - 1].state == 1) neighbors++;
      if (board[i][j + 1].state == 1) neighbors++;
      switch (board[i][j].state) {
      case 0:
        if (neighbors == 3) board[i][j].state = 1;
        break;
      case 1:
        if (neighbors < 2) board[i][j].state = 0;
        else if (neighbors > 3) board[i][j].state = 0;
        break;
      }
    }
  }
}

int main() {
  Cell **board;
  initializeBoard(&board, MAX_WIDTH, MAX_HEIGHT);

  board[5][5].state = 1;
  board[5][6].state = 1;
  board[6][5].state = 1;
  board[6][6].state = 1;

  printBoard(board, MAX_WIDTH, MAX_HEIGHT);

  calculateNextState(board, MAX_WIDTH, MAX_HEIGHT);

  printBoard(board, MAX_WIDTH, MAX_HEIGHT);

  return 0;
}