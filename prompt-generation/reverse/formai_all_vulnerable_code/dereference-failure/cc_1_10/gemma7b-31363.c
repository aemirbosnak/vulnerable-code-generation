//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: rigorous
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
    Car* new_car = malloc(sizeof(Car));
    new_car->x = rand() % MAX_LANE;
    new_car->y = rand() % MAX_LANE;
    new_car->direction = rand() % 2;
    new_car->speed = rand() % 3;
    new_car->next = *head;
    *head = new_car;
  }
}

void move_cars(Car* head) {
  time_t start_time = time(NULL);
  while (time(NULL) - start_time < 10) {
    for (Car* car = head; car; car = car->next) {
      switch (car->direction) {
        case 0:
          car->x++;
          break;
        case 1:
          car->x--;
          break;
      }
      car->y++;
      car->speed++;
    }
    sleep(0.1);
  }
}

int main() {
  Car* head = NULL;
  initialize_cars(&head);
  move_cars(head);
  return 0;
}