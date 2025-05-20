//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: scientific
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
  int x, y, direction, speed;
  struct Car* next;
} Car;

Car* createCar() {
  Car* car = (Car*)malloc(sizeof(Car));
  car->x = rand() % 10;
  car->y = rand() % 10;
  car->direction = rand() % 2;
  car->speed = rand() % 5;
  car->next = NULL;
  return car;
}

void simulateTrafficFlow() {
  Car* head = createCar();
  head->next = createCar();
  head->next->next = createCar();

  time_t t = time(NULL);
  while (time(NULL) - t < 10) {
    for (Car* car = head; car; car = car->next) {
      switch (car->direction) {
        case 0:
          car->x++;
          break;
        case 1:
          car->y++;
          break;
      }

      if (car->x >= 10 || car->x < 0) {
        car->direction = (car->direction + 1) % 2;
      }

      if (car->y >= 10 || car->y < 0) {
        car->direction = (car->direction + 1) % 2;
      }
    }

    sleep(1);
  }

  free(head);
}

int main() {
  simulateTrafficFlow();
  return 0;
}