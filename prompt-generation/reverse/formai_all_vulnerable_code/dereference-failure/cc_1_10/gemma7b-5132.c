//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: immersive
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
  int x, y, direction, speed, lane;
  struct Car* next;
} Car;

void initializeCars(Car** head) {
  *head = NULL;
  for (int i = 0; i < MAX_CARS; i++) {
    Car* newCar = malloc(sizeof(Car));
    newCar->x = i;
    newCar->y = 0;
    newCar->direction = 1;
    newCar->speed = 1;
    newCar->lane = 0;
    newCar->next = *head;
    *head = newCar;
  }
}

void simulateTrafficFlow(Car* head) {
  time_t t = time(NULL);
  int elapsedTime = 0;
  while (elapsedTime < 60) {
    for (Car* car = head; car; car = car->next) {
      switch (car->direction) {
        case 1:
          car->y++;
          break;
        case -1:
          car->y--;
          break;
      }

      if (car->x == 0) {
        car->direction = -1;
      } else if (car->x == MAX_CARS - 1) {
        car->direction = 1;
      }

      car->speed++;
      elapsedTime = time(NULL) - t;
    }

    t = time(NULL);
  }
}

int main() {
  Car* head = NULL;
  initializeCars(&head);
  simulateTrafficFlow(head);

  return 0;
}