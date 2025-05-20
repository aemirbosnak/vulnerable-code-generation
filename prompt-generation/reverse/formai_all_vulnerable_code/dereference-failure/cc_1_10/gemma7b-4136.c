//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: expert-level
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_SPEED 5

typedef struct Car {
  int x, y, speed, direction, lane;
  struct Car* next;
} Car;

Car* createCar() {
  Car* car = (Car*)malloc(sizeof(Car));
  car->x = 0;
  car->y = 0;
  car->speed = 0;
  car->direction = 0;
  car->lane = 0;
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

  car->speed++;

  if (car->speed > MAX_SPEED) {
    car->speed = MAX_SPEED;
  }
}

void simulateTrafficFlow() {
  srand(time(NULL));

  Car* head = createCar();
  head->next = createCar();
  head->next->next = createCar();

  for (int i = 0; i < 1000; i++) {
    moveCar(head);
    moveCar(head->next);
    moveCar(head->next->next);
  }

  free(head);
}

int main() {
  simulateTrafficFlow();
  return 0;
}