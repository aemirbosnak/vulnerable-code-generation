//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 20

typedef struct Cell {
  int x, y;
  int state;
  struct Cell* next;
} Cell;

void initializeGame(Cell** head) {
  *head = NULL;
  for (int x = 0; x < MAX_CELLS; x++) {
    for (int y = 0; y < MAX_CELLS; y++) {
      Cell* newCell = malloc(sizeof(Cell));
      newCell->x = x;
      newCell->y = y;
      newCell->state = 0;
      newCell->next = *head;
      *head = newCell;
    }
  }
}

void simulateGame(Cell* head) {
  // Calculate the number of neighbors for each cell
  for (Cell* cell = head; cell; cell = cell->next) {
    int numNeighbors = 0;
    for (Cell* neighbor = head; neighbor; neighbor = neighbor->next) {
      if (neighbor->x == cell->x && neighbor->y == cell->y) {
        numNeighbors++;
      }
    }

    // Update the state of the cell based on the number of neighbors
    if (numNeighbors < 2) {
      cell->state = 0;
    } else if (numNeighbors == 2) {
      cell->state = 1;
    } else if (numNeighbors > 2) {
      cell->state = 0;
    }
  }

  // Update the game board
  for (Cell* cell = head; cell; cell = cell->next) {
    if (cell->state == 1) {
      printf("%c ", '*');
    } else {
      printf("%c ", '.');
    }
  }
  printf("\n");
}

int main() {
  Cell* head = NULL;
  initializeGame(&head);

  // Simulate the game for 10 generations
  for (int gen = 0; gen < 10; gen++) {
    simulateGame(head);
  }

  return 0;
}