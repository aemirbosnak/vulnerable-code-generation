//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: mind-bending
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

typedef struct Cell {
  int x;
  int y;
  struct Cell* next;
} Cell;

Cell* createCell(int x, int y) {
  Cell* cell = malloc(sizeof(Cell));
  cell->x = x;
  cell->y = y;
  cell->next = NULL;
  return cell;
}

void addCell(Cell* cell, Cell* newCell) {
  cell->next = newCell;
}

void printBoard(Cell* cell) {
  for (int y = 0; y < BOARD_SIZE; y++) {
    for (int x = 0; x < BOARD_SIZE; x++) {
      if (cell->x == x && cell->y == y) {
        printf("X ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));

  Cell* head = createCell(0, 0);
  Cell* tail = head;

  for (int i = 0; i < 10; i++) {
    tail = createCell(rand() % BOARD_SIZE, rand() % BOARD_SIZE);
    addCell(head, tail);
  }

  printBoard(head);

  return 0;
}