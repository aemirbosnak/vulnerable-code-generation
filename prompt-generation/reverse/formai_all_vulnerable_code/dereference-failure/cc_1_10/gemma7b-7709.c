//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIM_TIME 100
#define MAX_NUMBER_OF_CARS 10

typedef struct Car {
  int x, y, direction, speed;
  struct Car* next;
} Car;

void initializeCars(Car** head) {
  *head = NULL;
  for (int i = 0; i < MAX_NUMBER_OF_CARS; i++) {
    Car* newCar = malloc(sizeof(Car));
    newCar->x = rand() % MAX_SIM_TIME;
    newCar->y = rand() % MAX_SIM_TIME;
    newCar->direction = rand() % 4;
    newCar->speed = rand() % 5;
    newCar->next = *head;
    *head = newCar;
  }
}

void simulateTrafficFlow(Car* head) {
  for (int t = 0; t < MAX_SIM_TIME; t++) {
    for (Car* car = head; car; car = car->next) {
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
        car->speed = rand() % 5;
      }
    }
  }
}

int main() {
  Car* head = NULL;
  initializeCars(&head);
  simulateTrafficFlow(head);

  return 0;
}