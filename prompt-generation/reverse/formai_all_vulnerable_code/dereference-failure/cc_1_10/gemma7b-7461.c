//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct Cell {
  int state;
  struct Cell* next;
} Cell;

void initialize(Cell** head) {
  *head = NULL;
}

void insert(Cell** head, int state) {
  Cell* newNode = malloc(sizeof(Cell));
  newNode->state = state;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void simulate(Cell* head) {
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

    switch (current->state) {
      case 0:
        if (neighbors == 3) {
          current->state = 1;
        }
        break;
      case 1:
        if (neighbors < 2 || neighbors > 3) {
          current->state = 0;
        }
        break;
    }

    current = current->next;
  }
}

int main() {
  Cell* head = NULL;
  initialize(&head);

  insert(head, 1);
  insert(head, 0);
  insert(head, 1);
  insert(head, 0);

  simulate(head);

  Cell* current = head;
  while (current) {
    printf("%d ", current->state);
    current = current->next;
  }

  return 0;
}