//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct Cell {
  int x;
  int y;
  struct Cell* up;
  struct Cell* right;
  struct Cell* down;
  struct Cell* left;
} Cell;

Cell* createCell(int x, int y) {
  Cell* cell = (Cell*)malloc(sizeof(Cell));
  cell->x = x;
  cell->y = y;
  cell->up = NULL;
  cell->right = NULL;
  cell->down = NULL;
  cell->left = NULL;
  return cell;
}

void printBoard(Cell* cell) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
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
  Cell* board = createCell(0, 0);
  board->up = createCell(0, 1);
  board->right = createCell(1, 0);
  board->down = createCell(0, 2);
  board->left = createCell(-1, 0);

  printBoard(board);

  return 0;
}