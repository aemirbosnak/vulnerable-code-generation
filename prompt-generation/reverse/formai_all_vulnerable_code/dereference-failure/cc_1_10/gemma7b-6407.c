//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

typedef struct Cell {
  int x, y;
  int state;
} Cell;

void initBoard(Cell **board, int size) {
  *board = (Cell *)malloc(size * sizeof(Cell));
  for (int i = 0; i < size; i++) {
    (*board)[i].x = -1;
    (*board)[i].y = -1;
    (*board)[i].state = 0;
  }
}

void printBoard(Cell *board, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", board[i].state);
  }
  printf("\n");
}

void calculateNextState(Cell *board, int size) {
  for (int i = 0; i < size; i++) {
    int neighbors = 0;
    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        if (board[i].x + dx >= 0 && board[i].x + dx < size && board[i].y + dy >= 0 && board[i].y + dy < size) {
          if (board[i].state == 1) {
            neighbors++;
          }
        }
      }
    }
    if (board[i].state == 0 && neighbors == 3) {
      board[i].state = 1;
    } else if (board[i].state == 1 && (neighbors < 2 || neighbors > 3)) {
      board[i].state = 0;
    }
  }
}

int main() {
  int size = MAX;
  Cell *board;
  initBoard(&board, size);

  // Randomly initialize some cells
  for (int i = 0; i < size; i++) {
    board[i].state = rand() % 2;
  }

  printBoard(board, size);

  calculateNextState(board, size);

  printBoard(board, size);

  return 0;
}