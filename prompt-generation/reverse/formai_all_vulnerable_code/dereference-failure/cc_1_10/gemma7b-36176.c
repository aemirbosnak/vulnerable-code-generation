//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: genius
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_LANE 3
#define NUM_CARS 10

typedef struct Car {
  int lane;
  int speed;
  int position;
  struct Car* next;
} Car;

Car* createCar(int lane, int speed, int position) {
  Car* car = malloc(sizeof(Car));
  car->lane = lane;
  car->speed = speed;
  car->position = position;
  car->next = NULL;
  return car;
}

void simulateTrafficFlow(Car* cars) {
  time_t start = time(NULL);
  while (time(NULL) - start < 10) {
    for (Car* car = cars; car; car = car->next) {
      switch (car->lane) {
        case 0:
          car->position++;
          if (car->position >= 10) {
            car->position = 0;
          }
          break;
        case 1:
          car->position--;
          if (car->position <= 0) {
            car->position = 10;
          }
          break;
        case 2:
          car->position += 2;
          if (car->position >= 10) {
            car->position = 0;
          }
          break;
      }
    }
    sleep(1);
  }
}

int main() {
  Car* cars = createCar(0, 5, 0);
  cars = createCar(1, 3, 5);
  cars = createCar(2, 7, 10);

  simulateTrafficFlow(cars);

  return 0;
}