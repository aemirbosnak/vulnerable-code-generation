//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: peaceful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 5

typedef struct Car {
  int x, y, direction, speed;
  struct Car* next;
} Car;

void initializeCars(Car** head) {
  *head = NULL;
  for (int i = 0; i < MAX_CARS; i++) {
    Car* newCar = malloc(sizeof(Car));
    newCar->x = rand() % 10;
    newCar->y = rand() % 10;
    newCar->direction = rand() % 2;
    newCar->speed = rand() % 3;
    newCar->next = *head;
    *head = newCar;
  }
}

void moveCars(Car* head) {
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
    if (currentCar->speed == 0) {
      currentCar->direction = rand() % 2;
      currentCar->speed = rand() % 3;
    }
    currentCar = currentCar->next;
  }
}

int main() {
  srand(time(NULL));
  Car* head = NULL;
  initializeCars(&head);
  moveCars(head);

  return 0;
}