//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_SPEED 5
#define ROAD_LENGTH 100

typedef struct Car {
  int x, y, speed, direction;
  struct Car* next;
} Car;

Car* createCar() {
  Car* car = malloc(sizeof(Car));
  car->x = 0;
  car->y = 0;
  car->speed = 0;
  car->direction = 0;
  car->next = NULL;
  return car;
}

void moveCar(Car* car) {
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
  if (car->speed > MAX_SPEED) {
    car->speed = MAX_SPEED;
  }
}

void simulateTrafficFlow(int numCars) {
  Car* head = NULL;
  for (int i = 0; i < numCars; i++) {
    Car* car = createCar();
    head = car;
    head->next = head;
  }

  time_t start = time(NULL);
  while (time(NULL) - start < 60) {
    for (Car* car = head; car; car = car->next) {
      moveCar(car);
    }

    sleep(1);
  }

  free(head);
}

int main() {
  simulateTrafficFlow(5);
  return 0;
}