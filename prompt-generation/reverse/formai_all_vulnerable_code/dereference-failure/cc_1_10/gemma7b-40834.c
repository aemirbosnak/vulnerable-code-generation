//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5

typedef struct Cell {
  int x;
  int y;
  struct Cell* up;
  struct Cell* right;
  struct Cell* down;
  struct Cell* left;
} Cell;

Cell* createCell(int x, int y) {
  Cell* cell = malloc(sizeof(Cell));
  cell->x = x;
  cell->y = y;
  cell->up = NULL;
  cell->right = NULL;
  cell->down = NULL;
  cell->left = NULL;

  return cell;
}

void connectCells(Cell* cell1, Cell* cell2) {
  cell1->up = cell2;
  cell2->down = cell1;
  cell1->right = cell2;
  cell2->left = cell1;
}

void printBoard(Cell* cell) {
  for (int y = 0; y < BOARD_SIZE; y++) {
    for (int x = 0; x < BOARD_SIZE; x++) {
      if (cell->x == x && cell->y == y) {
        printf("O ");
      } else {
        printf(". ");
      }
    }

    printf("\n");
  }
}

int main() {
  srand(time(NULL));

  Cell* board = createCell(0, 0);
  connectCells(board, createCell(1, 0));
  connectCells(board, createCell(2, 0));
  connectCells(board, createCell(2, 1));
  connectCells(board, createCell(1, 1));

  printBoard(board);

  return 0;
}