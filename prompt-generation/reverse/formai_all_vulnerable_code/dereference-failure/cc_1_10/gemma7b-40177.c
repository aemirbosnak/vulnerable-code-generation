//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_Cars 100
#define MAX_Speed 5

typedef struct Car {
  int x, y, speed, direction, lane;
  struct Car* next;
} Car;

Car* createCar() {
  Car* car = malloc(sizeof(Car));
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
  if (car->speed > MAX_Speed) {
    car->speed = MAX_Speed;
  }
}

void simulateTrafficFlow() {
  Car* head = createCar();
  head->next = createCar();
  head->next->next = createCar();

  time_t start = time(NULL);
  while (time(NULL) - start < 10) {
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