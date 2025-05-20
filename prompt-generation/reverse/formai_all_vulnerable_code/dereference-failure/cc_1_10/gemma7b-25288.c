//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
  int x, y, dir, speed, lane;
  struct Car* next;
} Car;

Car* createCar() {
  Car* newCar = malloc(sizeof(Car));
  newCar->x = 0;
  newCar->y = 0;
  newCar->dir = 1;
  newCar->speed = 1;
  newCar->lane = 1;
  newCar->next = NULL;
  return newCar;
}

void moveCar(Car* car) {
  switch (car->dir) {
    case 1:
      car->x++;
      break;
    case 2:
      car->y++;
      break;
    case 3:
      car->x--;
      break;
    case 4:
      car->y--;
      break;
  }
  car->speed++;
  if (car->speed > 5) {
    car->speed = 5;
  }
}

void simulateTrafficFlow() {
  srand(time(NULL));

  Car* head = createCar();
  head->next = createCar();
  head->next->next = createCar();

  while (1) {
    moveCar(head);
    moveCar(head->next);
    moveCar(head->next->next);

    if (head->x >= 10) {
      head->dir = 2;
    }
    if (head->y >= 10) {
      head->dir = 3;
    }
    if (head->x <= 0) {
      head->dir = 4;
    }
    if (head->y <= 0) {
      head->dir = 1;
    }

    sleep(1);
  }
}

int main() {
  simulateTrafficFlow();

  return 0;
}