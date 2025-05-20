//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
  int x, y, direction, speed;
  struct Car* next;
} Car;

void initialize_traffic_flow(Car** head) {
  *head = NULL;
  for (int i = 0; i < MAX_CARS; i++) {
    Car* new_car = malloc(sizeof(Car));
    new_car->x = rand() % MAX_LANE;
    new_car->y = 0;
    new_car->direction = rand() % 2;
    new_car->speed = rand() % 3;
    new_car->next = *head;
    *head = new_car;
  }
}

void simulate_traffic_flow(Car* head) {
  time_t start_time = time(NULL);
  while (time(NULL) - start_time < 10) {
    for (Car* car = head; car; car = car->next) {
      switch (car->direction) {
        case 0:
          car->y++;
          break;
        case 1:
          car->y--;
          break;
      }
      car->x += car->speed;
      if (car->x >= MAX_LANE || car->x < 0) {
        car->direction = (car->direction + 1) % 2;
      }
    }
    sleep(1);
  }
}

int main() {
  Car* head = NULL;
  initialize_traffic_flow(&head);
  simulate_traffic_flow(head);

  return 0;
}