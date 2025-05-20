//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
  int x, y, direction, speed;
  struct Car* next;
} Car;

Car* createCar() {
  Car* car = malloc(sizeof(Car));
  car->x = rand() % MAX_LANE;
  car->y = rand() % MAX_CARS;
  car->direction = rand() % 2;
  car->speed = rand() % 5;
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
  }

  switch (car->speed) {
    case 0:
      car->y++;
      break;
    case 1:
      car->y++;
      break;
    case 2:
      car->y++;
      break;
  }
}

void simulateTrafficFlow() {
  Car* head = createCar();
  while (head) {
    moveCar(head);
    head = head->next;
  }
}

int main() {
  simulateTrafficFlow();
  return 0;
}