//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_LANE 3
#define MAX_CARS 10

typedef struct Car {
  int lane;
  int position;
  int speed;
} Car;

void simulateTrafficFlow(Car **cars, int numCars) {
  for (int i = 0; i < numCars; i++) {
    cars[i]->position++;
    switch (cars[i]->lane) {
      case 0:
        if (cars[i]->position >= MAX_LANE) {
          cars[i]->lane = 1;
        }
        break;
      case 1:
        if (cars[i]->position >= MAX_LANE) {
          cars[i]->lane = 2;
        }
        break;
      case 2:
        if (cars[i]->position >= MAX_LANE) {
          cars[i]->lane = 0;
        }
        break;
    }
  }
}

int main() {
  Car **cars = (Car **)malloc(MAX_CARS * sizeof(Car));
  for (int i = 0; i < MAX_CARS; i++) {
    cars[i] = (Car *)malloc(sizeof(Car));
    cars[i]->lane = 0;
    cars[i]->position = 0;
    cars[i]->speed = 1;
  }

  simulateTrafficFlow(cars, MAX_CARS);

  for (int i = 0; i < MAX_CARS; i++) {
    printf("Car %d is in lane %d, position %d\n", i, cars[i]->lane, cars[i]->position);
  }

  return 0;
}