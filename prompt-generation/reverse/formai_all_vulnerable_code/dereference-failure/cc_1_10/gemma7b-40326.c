//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
  int lane;
  int position;
  int speed;
  int direction;
  struct Car* next;
} Car;

Car* createCar() {
  Car* car = (Car*)malloc(sizeof(Car));
  car->lane = rand() % MAX_LANE;
  car->position = rand() % 100;
  car->speed = rand() % 5;
  car->direction = rand() % 2;
  car->next = NULL;
  return car;
}

void simulateTrafficFlow() {
  Car* head = createCar();
  head->next = createCar();
  head->next->next = createCar();

  for (int i = 0; i < 10; i++) {
    for (Car* car = head; car; car = car->next) {
      switch (car->direction) {
        case 0:
          car->position++;
          break;
        case 1:
          car->position--;
          break;
      }

      if (car->position >= 100) {
        car->direction = 1;
      } else if (car->position <= 0) {
        car->direction = 0;
      }
    }

    printf("Time: %d\n", i);
    for (Car* car = head; car; car = car->next) {
      printf("Lane: %d, Position: %d, Speed: %d, Direction: %d\n", car->lane, car->position, car->speed, car->direction);
    }
    printf("\n");
  }
}

int main() {
  simulateTrafficFlow();
  return 0;
}