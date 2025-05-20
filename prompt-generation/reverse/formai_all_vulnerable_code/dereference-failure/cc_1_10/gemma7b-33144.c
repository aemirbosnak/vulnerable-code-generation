//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_SPEED 10

typedef struct Car {
  int x, y, speed, direction;
  struct Car* next;
} Car;

Car* head = NULL;

void addCar() {
  Car* newCar = malloc(sizeof(Car));
  newCar->x = 0;
  newCar->y = 0;
  newCar->speed = rand() % MAX_SPEED;
  newCar->direction = rand() % 4;
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

    currentCar->speed--;
    if (currentCar->speed <= 0) {
      currentCar->speed = rand() % MAX_SPEED;
      currentCar->direction = rand() % 4;
    }

    currentCar = currentCar->next;
  }
}

int main() {
  srand(time(NULL));

  for (int i = 0; i < MAX_CARS; i++) {
    addCar();
  }

  moveCars();

  return 0;
}