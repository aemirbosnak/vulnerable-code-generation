//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10

typedef struct car {
  int x, y, direction, speed;
  struct car* next;
} car;

car* head = NULL;

void addCar() {
  car* newCar = malloc(sizeof(car));
  newCar->x = 0;
  newCar->y = 0;
  newCar->direction = 0;
  newCar->speed = 1;
  newCar->next = NULL;

  if (head == NULL) {
    head = newCar;
  } else {
    head->next = newCar;
  }
}

void moveCars() {
  car* currentCar = head;

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

void simulateTraffic() {
  int i = 0;

  for (i = 0; i < MAX_CARS; i++) {
    addCar();
  }

  moveCars();

  for (i = 0; i < MAX_CARS; i++) {
    car* currentCar = head;

    while (currentCar) {
      printf("Car: x = %d, y = %d, direction = %d, speed = %d\n", currentCar->x, currentCar->y, currentCar->direction, currentCar->speed);

      currentCar = currentCar->next;
    }

    printf("\n");
  }
}

int main() {
  simulateTraffic();

  return 0;
}