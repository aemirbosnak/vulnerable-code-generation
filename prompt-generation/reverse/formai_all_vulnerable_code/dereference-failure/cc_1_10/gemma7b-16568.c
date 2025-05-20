//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
  int x, y, direction, speed;
  struct Car* next;
} Car;

void initialize_traffic_flow(Car** head) {
  *head = NULL;
  for (int i = 0; i < MAX_CARS; i++) {
    Car* new_car = malloc(sizeof(Car));
    new_car->x = i * 5;
    new_car->y = 0;
    new_car->direction = 1;
    new_car->speed = rand() % 5 + 1;
    new_car->next = *head;
    *head = new_car;
  }
}

void simulate_traffic_flow(Car* head) {
  time_t start_time = time(NULL);
  while (time(NULL) - start_time < 60) {
    for (Car* car = head; car; car = car->next) {
      switch (car->direction) {
        case 1:
          car->y++;
          break;
        case 2:
          car->y--;
          break;
        case 3:
          car->x++;
          break;
        case 4:
          car->x--;
          break;
      }

      if (car->x >= 20) {
        car->direction = 2;
      } else if (car->x <= 0) {
        car->direction = 4;
      }

      if (car->y >= 5) {
        car->direction = 3;
      } else if (car->y <= 0) {
        car->direction = 1;
      }

      car->speed--;
      if (car->speed == 0) {
        car->speed = rand() % 5 + 1;
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