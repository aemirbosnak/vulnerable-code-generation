//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
  int x, y, direction, speed;
  struct Car* next;
} Car;

Car* createCar() {
  Car* newCar = malloc(sizeof(Car));
  newCar->x = rand() % MAX_LANE;
  newCar->y = rand() % MAX_LANE;
  newCar->direction = rand() % 2;
  newCar->speed = rand() % 5;
  newCar->next = NULL;
  return newCar;
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
  if (car->speed <= 0) {
    car->speed = rand() % 5;
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