//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 100

typedef struct Car {
  int x, y, direction, speed;
  struct Car* next;
} Car;

Car* createCar() {
  Car* car = malloc(sizeof(Car));
  car->x = rand() % 1000;
  car->y = rand() % 1000;
  car->direction = rand() % 4;
  car->speed = rand() % 5 + 1;
  car->next = NULL;
  return car;
}

void moveCar(Car* car) {
  switch (car->direction) {
    case 0:
      car->x++;
      break;
    case 1:
      car->x--;
      break;
    case 2:
      car->y++;
      break;
    case 3:
      car->y--;
      break;
  }

  car->speed--;
  if (car->speed == 0) {
    car->direction = rand() % 4;
    car->speed = rand() % 5 + 1;
  }
}

void simulateTrafficFlow(int numCars) {
  Car* head = NULL;
  for (int i = 0; i < numCars; i++) {
    Car* car = createCar();
    if (head == NULL) {
      head = car;
    } else {
      car->next = head;
      head = car;
    }
  }

  time_t start = time(NULL);
  while (time(NULL) - start < 10) {
    for (Car* car = head; car; car = car->next) {
      moveCar(car);
    }
    sleep(1);
  }

  free(head);
}

int main() {
  simulateTrafficFlow(20);
  return 0;
}