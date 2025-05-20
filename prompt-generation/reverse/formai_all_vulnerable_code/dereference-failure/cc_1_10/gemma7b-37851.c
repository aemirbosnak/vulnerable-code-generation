//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 20

typedef struct Cell {
  int state;
  struct Cell* next;
} Cell;

void initGame(Cell** head) {
  *head = NULL;
  for (int i = 0; i < MAX_CELLS; i++) {
    *head = malloc(sizeof(Cell));
    (*head)->state = 0;
    (*head)->next = NULL;
    head = &((*head)->next);
  }
}

void playGame(Cell* head) {
  for (Cell* cell = head; cell; cell = cell->next) {
    int neighbors = 0;
    for (Cell* neighbor = head; neighbor; neighbor = neighbor->next) {
      if (neighbor != cell && neighbor->state == 1) {
        neighbors++;
      }
    }

    if (cell->state == 0 && neighbors == 3) {
      cell->state = 1;
    } else if (cell->state == 1 && (neighbors < 2 || neighbors > 3)) {
      cell->state = 0;
    }
  }

  printf("Generation:\n");
  for (Cell* cell = head; cell; cell = cell->next) {
    printf("%d ", cell->state);
  }
  printf("\n");
}

int main() {
  Cell* head = NULL;
  initGame(&head);

  playGame(head);

  return 0;
}