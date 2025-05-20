//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: expert-level
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
  int lane;
  int position;
  int direction;
  struct Car* next;
} Car;

void create_car(Car** head) {
  *head = malloc(sizeof(Car));
  (*head)->lane = rand() % MAX_LANE;
  (*head)->position = rand() % 100;
  (*head)->direction = rand() % 2;
  (*head)->next = NULL;
}

void move_cars(Car* head) {
  Car* current = head;
  while (current) {
    switch (current->direction) {
      case 0:
        current->position++;
        break;
      case 1:
        current->position--;
        break;
    }
    current = current->next;
  }
}

void print_cars(Car* head) {
  Car* current = head;
  while (current) {
    printf("Lane: %d, Position: %d, Direction: %d\n", current->lane, current->position, current->direction);
    current = current->next;
  }
}

int main() {
  srand(time(NULL));

  Car* head = NULL;
  create_car(&head);
  create_car(&head);
  create_car(&head);
  create_car(&head);

  move_cars(head);

  print_cars(head);

  return 0;
}