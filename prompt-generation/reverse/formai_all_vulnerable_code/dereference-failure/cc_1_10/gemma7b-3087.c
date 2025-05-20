//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
  int x, y, direction, speed;
  struct Car* next;
} Car;

Car* createCar() {
  Car* car = (Car*)malloc(sizeof(Car));
  car->x = rand() % 10;
  car->y = rand() % 10;
  car->direction = rand() % 4;
  car->speed = rand() % 3;
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

  car->speed--;
  if (car->speed == 0) {
    car->direction = rand() % 4;
    car->speed = rand() % 3;
  }
}

void main() {
  srand(time(NULL));

  Car* head = createCar();
  Car* current = head;

  while (current) {
    moveCar(current);
    current = current->next;
  }

  return;
}