//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: detailed
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
  int x, y, direction, speed;
  struct Car* next;
} Car;

void initialize_cars(Car** head) {
  *head = NULL;
  for (int i = 0; i < MAX_CARS; i++) {
    *head = malloc(sizeof(Car));
    (*head)->x = rand() % MAX_LANE;
    (*head)->y = rand() % MAX_LANE;
    (*head)->direction = rand() % 2;
    (*head)->speed = rand() % 5 + 1;
    (*head)->next = NULL;
    head = &((*head)->next);
  }
}

void simulate_traffic(Car* head) {
  time_t start_time = time(NULL);
  while (time(NULL) - start_time < 10) {
    for (Car* current = head; current; current = current->next) {
      switch (current->direction) {
        case 0:
          current->x++;
          break;
        case 1:
          current->x--;
          break;
      }

      current->y++;

      if (current->x == MAX_LANE - 1) {
        current->direction = 1;
      } else if (current->x == 0) {
        current->direction = 0;
      }

      sleep(current->speed);
    }
  }
}

int main() {
  Car* head = NULL;
  initialize_cars(&head);
  simulate_traffic(head);

  return 0;
}