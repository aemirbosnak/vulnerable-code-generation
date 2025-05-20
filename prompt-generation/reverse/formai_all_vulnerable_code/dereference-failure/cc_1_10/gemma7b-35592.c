//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
  int x, y, direction, speed;
  struct Car* next;
} Car;

Car* head = NULL;

void createCar() {
  Car* newCar = (Car*)malloc(sizeof(Car));
  newCar->x = rand() % 10;
  newCar->y = rand() % 10;
  newCar->direction = rand() % 2;
  newCar->speed = rand() % 3;
  newCar->next = head;
  head = newCar;
}

void moveCars() {
  Car* currentCar = head;
  while (currentCar) {
    switch (currentCar->direction) {
      case 0:
        currentCar->x++;
        break;
      case 1:
        currentCar->x--;
        break;
      case 2:
        currentCar->y++;
        break;
      case 3:
        currentCar->y--;
        break;
    }
    currentCar = currentCar->next;
  }
}

void drawCars() {
  for (Car* currentCar = head; currentCar; currentCar = currentCar->next) {
    printf("Car at (%d, %d) moving in direction %d with speed %d\n", currentCar->x, currentCar->y, currentCar->direction, currentCar->speed);
  }
}

int main() {
  srand(time(NULL));
  for (int i = 0; i < MAX_CARS; i++) {
    createCar();
  }
  moveCars();
  drawCars();
  return 0;
}