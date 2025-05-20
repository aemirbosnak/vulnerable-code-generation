//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct Cell {
  int state;
  struct Cell* next;
} Cell;

void initialize(Cell* head) {
  head = malloc(sizeof(Cell));
  head->state = 0;
  head->next = NULL;
}

void update(Cell* head) {
  Cell* current = head;
  while (current) {
    int neighbors = 0;
    Cell* neighbor = current->next;
    while (neighbor) {
      if (neighbor->state == 1) {
        neighbors++;
      }
      neighbor = neighbor->next;
    }

    if (current->state == 1 && neighbors < 2) {
      current->state = 0;
    } else if (current->state == 0 && neighbors == 3) {
      current->state = 1;
    }
    current = current->next;
  }
}

int main() {
  Cell* head = NULL;
  initialize(head);

  head->state = 1;
  head->next->state = 1;
  head->next->next->state = 0;
  head->next->next->next->state = 1;

  update(head);

  printf("%d", head->state);
  printf("%d", head->next->state);
  printf("%d", head->next->next->state);

  return 0;
}