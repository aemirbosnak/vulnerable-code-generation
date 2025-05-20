//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 5

typedef struct Cell {
  int alive;
  struct Cell** neighbors;
} Cell;

void initializeBoard(Cell** board) {
  for (int r = 0; r < BOARD_SIZE; r++) {
    board[r] = (Cell*)malloc(BOARD_SIZE * sizeof(Cell));
    for (int c = 0; c < BOARD_SIZE; c++) {
      board[r][c].alive = 0;
      board[r][c].neighbors = NULL;
    }
  }
}

void printBoard(Cell** board) {
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      printf("%d ", board[r][c].alive);
    }
    printf("\n");
  }
}

void calculateNeighbors(Cell* cell) {
  int numNeighbors = 0;
  if (cell->neighbors) {
    for (int i = 0; i < 8; i++) {
      if (cell->neighbors[i]->alive) {
        numNeighbors++;
      }
    }
  }
  cell->alive = numNeighbors == 3;
}

void simulateGameOfLife(Cell** board) {
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      calculateNeighbors(&board[r][c]);
    }
  }
  printBoard(board);
}

int main() {
  Cell** board = NULL;
  initializeBoard(&board);

  board[1][1].alive = 1;
  board[1][2].alive = 1;
  board[2][1].alive = 1;
  board[2][2].alive = 1;

  simulateGameOfLife(board);

  free(board);
  return 0;
}