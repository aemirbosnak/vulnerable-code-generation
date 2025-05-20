//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 20

typedef struct car {
  int x, y, direction, speed, lane;
  struct car* next;
} car;

void create_traffic_flow(car* head) {
  head = malloc(sizeof(car));
  head->x = 0;
  head->y = 0;
  head->direction = 1;
  head->speed = 1;
  head->lane = 0;
  head->next = NULL;

  time_t t = time(NULL);
  srand(t);

  for (int i = 1; i < MAX_CARS; i++) {
    car* new_car = malloc(sizeof(car));
    new_car->x = rand() % 10;
    new_car->y = rand() % 10;
    new_car->direction = rand() % 2;
    new_car->speed = 1 + rand() % 3;
    new_car->lane = rand() % 3;
    new_car->next = NULL;

    head->next = new_car;
    head = new_car;
  }
}

void simulate_traffic_flow(car* head) {
  time_t t = time(NULL);
  srand(t);

  for (int i = 0; head; i++) {
    switch (head->direction) {
      case 1:
        head->x++;
        break;
      case 2:
        head->x--;
        break;
    }

    switch (head->lane) {
      case 0:
        head->y++;
        break;
      case 1:
        head->y--;
        break;
    }

    head->speed = 1 + rand() % 3;
    head->direction = rand() % 2;

    head = head->next;
  }
}

int main() {
  car* head = NULL;
  create_traffic_flow(head);
  simulate_traffic_flow(head);

  return 0;
}