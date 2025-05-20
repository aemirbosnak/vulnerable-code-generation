//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 100

struct car {
  int x, y, direction, speed;
  struct car* next;
};

void move_car(struct car* car) {
  switch (car->direction) {
    case 0:
      car->x++;
      break;
    case 1:
      car->y++;
      break;
    case 2:
      car->x--;
      break;
    case 3:
      car->y--;
      break;
  }

  car->speed++;
  if (car->speed > 5) {
    car->speed = 5;
  }
}

void create_traffic_flow(struct car** head) {
  *head = malloc(sizeof(struct car));
  (*head)->x = 0;
  (*head)->y = 0;
  (*head)->direction = 0;
  (*head)->speed = 1;
  (*head)->next = NULL;

  struct car* tail = *head;

  for (int i = 1; i < MAX_CARS; i++) {
    tail->next = malloc(sizeof(struct car));
    tail = tail->next;
    tail->x = 0;
    tail->y = 0;
    tail->direction = 0;
    tail->speed = 1;
    tail->next = NULL;
  }
}

int main() {
  struct car* head = NULL;
  create_traffic_flow(&head);

  time_t start_time = time(NULL);

  while (time(NULL) - start_time < 10) {
    for (struct car* car = head; car; car = car->next) {
      move_car(car);
    }
  }

  return 0;
}