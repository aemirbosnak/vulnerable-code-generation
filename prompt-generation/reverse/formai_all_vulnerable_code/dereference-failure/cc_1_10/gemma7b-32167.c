//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Cell {
  int state;
  struct Cell* next;
} Cell;

void initGame(Cell** head) {
  *head = NULL;
  for (int i = 0; i < MAX; i++) {
    *head = malloc(sizeof(Cell));
    (*head)->state = 0;
    (*head)->next = NULL;
    head = &((*head)->next);
  }
}

void playGame(Cell* head) {
  for (Cell* current = head; current; current = current->next) {
    int neighbors = 0;
    for (Cell* neighbor = head; neighbor && neighbor != current; neighbor = neighbor->next) {
      if (neighbor->state == 1) {
        neighbors++;
      }
    }
    switch (neighbors) {
      case 2:
        current->state = 1;
        break;
      case 3:
        current->state = 1;
        break;
      default:
        current->state = 0;
    }
  }
}

int main() {
  Cell* head = NULL;
  initGame(&head);

  // Set some initial states
  head->state = 1;
  head->next->state = 1;
  head->next->next->state = 1;

  playGame(head);

  // Print the final states
  for (Cell* current = head; current; current = current->next) {
    printf("%d ", current->state);
  }

  return 0;
}