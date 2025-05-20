//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: shape shifting
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
  Car* car = (Car*)malloc(sizeof(Car));
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
  car->y++;
}

void simulateTrafficFlow() {
  Car* head = createCar();
  while (1) {
    moveCar(head);
    if (head->x == MAX_LANE - 1) {
      head->direction = 1;
    } else if (head->x == 0) {
      head->direction = 0;
    }
    sleep(head->speed);
  }
}

int main() {
  simulateTrafficFlow();
  return 0;
}