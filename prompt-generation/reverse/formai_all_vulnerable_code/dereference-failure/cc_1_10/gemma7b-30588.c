//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: romantic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_LANE 3
#define NUM_CARS 50

typedef struct Car {
  int x, y, speed, lane;
  struct Car* next;
} Car;

Car* createCar() {
  Car* car = malloc(sizeof(Car));
  car->x = 0;
  car->y = 0;
  car->speed = 1;
  car->lane = 1;
  car->next = NULL;
  return car;
}

void moveCars(Car* head) {
  Car* currentCar = head;
  while (currentCar) {
    currentCar->x++;
    currentCar->y++;
    switch (currentCar->lane) {
      case 1:
        currentCar->y = 0;
        break;
      case 2:
        currentCar->y = 1;
        break;
      case 3:
        currentCar->y = 2;
        break;
    }
    currentCar = currentCar->next;
  }
}

int main() {
  srand(time(NULL));
  Car* head = createCar();
  for (int i = 0; i < NUM_CARS; i++) {
    Car* car = createCar();
    car->next = head;
    head = car;
  }

  for (int i = 0; i < 1000; i++) {
    moveCars(head);
  }

  return 0;
}