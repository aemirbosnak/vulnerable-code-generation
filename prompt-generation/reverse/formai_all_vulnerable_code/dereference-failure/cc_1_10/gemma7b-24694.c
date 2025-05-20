//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: realistic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
  int x, y, direction, speed;
  struct Car* next;
} Car;

void create_traffic_flow(Car** head) {
  *head = NULL;
  for (int i = 0; i < MAX_CARS; i++) {
    Car* new_car = malloc(sizeof(Car));
    new_car->x = rand() % 10;
    new_car->y = rand() % 5;
    new_car->direction = rand() % 4;
    new_car->speed = rand() % 5;
    new_car->next = *head;
    *head = new_car;
  }
}

void simulate_traffic_flow(Car* head) {
  time_t start = time(NULL);
  while (time(NULL) - start < 60) {
    for (Car* car = head; car; car = car->next) {
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
      if (car->speed > 10) {
        car->speed = 10;
      }
    }

    sleep(1);
  }
}

int main() {
  Car* head = NULL;
  create_traffic_flow(&head);
  simulate_traffic_flow(head);
  return 0;
}