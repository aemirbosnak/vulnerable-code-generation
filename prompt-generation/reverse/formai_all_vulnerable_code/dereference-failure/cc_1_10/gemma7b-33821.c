//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
  int x, y, speed, direction;
  struct Car* next;
} Car;

Car* createCar(int x, int y, int speed, int direction) {
  Car* car = (Car*)malloc(sizeof(Car));
  car->x = x;
  car->y = y;
  car->speed = speed;
  car->direction = direction;
  car->next = NULL;
  return car;
}

void moveCar(Car* car, int direction) {
  switch (direction) {
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
}

void simulateTrafficFlow(int numCars) {
  Car* head = NULL;
  for (int i = 0; i < numCars; i++) {
    Car* car = createCar(rand() % MAX_LANE, rand() % MAX_LANE, rand() % 5, rand() % 4);
    moveCar(car, rand() % 4);
    head = car;
  }

  while (head) {
    moveCar(head, rand() % 4);
    head = head->next;
  }
}

int main() {
  simulateTrafficFlow(5);
  return 0;
}