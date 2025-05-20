//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: paranoid
#include <stdlib.h>
#include <time.h>

#define MAX_POP 20

typedef struct Cell {
  int alive;
  struct Cell *next;
} Cell;

void initialize(Cell **head) {
  *head = NULL;
}

void add_cell(Cell **head, int alive) {
  Cell *new_cell = malloc(sizeof(Cell));
  new_cell->alive = alive;
  new_cell->next = NULL;

  if (*head == NULL) {
    *head = new_cell;
  } else {
    (*head)->next = new_cell;
  }
}

void simulate(Cell *head) {
  srand(time(NULL));

  for (head = head; head; head = head->next) {
    int chance = rand() % MAX_POP;

    if (head->alive && chance < 2) {
      head->alive = 0;
    } else if (!head->alive && chance > 1) {
      head->alive = 1;
    }
  }
}

int main() {
  Cell *head = NULL;

  initialize(&head);
  add_cell(&head, 1);
  add_cell(&head, 1);
  add_cell(&head, 0);
  add_cell(&head, 1);

  simulate(head);

  for (head = head; head; head = head->next) {
    printf("%d ", head->alive);
  }

  return 0;
}