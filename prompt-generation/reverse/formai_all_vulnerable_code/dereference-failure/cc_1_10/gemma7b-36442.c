//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

struct Car {
  int x, y, direction, speed;
  struct Car* next;
};

void create_car(struct Car** head) {
  *head = malloc(sizeof(struct Car));
  (*head)->x = 0;
  (*head)->y = 0;
  (*head)->direction = 0;
  (*head)->speed = 1;
  (*head)->next = NULL;
}

void move_car(struct Car* car) {
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
}

void simulate_traffic(struct Car** head) {
  time_t t = time(NULL);
  while (time(NULL) - t < 10) {
    struct Car* car = *head;
    while (car) {
      move_car(car);
      car = car->next;
    }
    sleep(1);
  }
}

int main() {
  struct Car* head = NULL;
  create_car(&head);
  create_car(&head);
  create_car(&head);
  simulate_traffic(&head);
  return 0;
}