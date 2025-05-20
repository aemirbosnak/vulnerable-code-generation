//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 20

typedef struct Cell {
  int state;
  struct Cell* north;
  struct Cell* south;
  struct Cell* east;
  struct Cell* west;
} Cell;

Cell** createBoard() {
  Cell** board = malloc(sizeof(Cell*) * BOARD_SIZE);
  for (int i = 0; i < BOARD_SIZE; i++) {
    board[i] = malloc(sizeof(Cell));
    board[i]->state = 0;
    board[i]->north = NULL;
    board[i]->south = NULL;
    board[i]->east = NULL;
    board[i]->west = NULL;
  }
  return board;
}

void simulateGameOfLife(Cell** board) {
  for (int x = 0; x < BOARD_SIZE; x++) {
    for (int y = 0; y < BOARD_SIZE; y++) {
      int neighbors = 0;
      if (board[x]->north) neighbors++;
      if (board[x]->south) neighbors++;
      if (board[x]->east) neighbors++;
      if (board[x]->west) neighbors++;

      switch (board[x]->state) {
        case 0:
          if (neighbors == 3) board[x]->state = 1;
          break;
        case 1:
          if (neighbors < 2) board[x]->state = 0;
          else if (neighbors > 3) board[x]->state = 0;
          break;
      }
    }
  }
}

int main() {
  Cell** board = createBoard();
  board[10]->state = 1;
  board[11]->state = 1;
  board[12]->state = 1;
  board[13]->state = 1;

  simulateGameOfLife(board);

  for (int x = 0; x < BOARD_SIZE; x++) {
    for (int y = 0; y < BOARD_SIZE; y++) {
      printf("%d ", board[x]->state);
    }
    printf("\n");
  }

  return 0;
}