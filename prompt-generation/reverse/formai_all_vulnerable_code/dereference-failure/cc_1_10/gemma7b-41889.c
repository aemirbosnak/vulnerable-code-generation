//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARS 10

typedef struct Car {
  int x, y, direction, speed;
  struct Car* next;
} Car;

void simulateTrafficFlow(Car* head) {
  while (head) {
    switch (head->direction) {
      case 0:
        head->x++;
        break;
      case 1:
        head->y++;
        break;
      case 2:
        head->x--;
        break;
      case 3:
        head->y--;
        break;
    }

    head = head->next;
  }
}

int main() {
  Car* head = NULL;

  for (int i = 0; i < MAX_CARS; i++) {
    Car* newCar = malloc(sizeof(Car));
    newCar->x = i;
    newCar->y = i;
    newCar->direction = rand() % 4;
    newCar->speed = rand() % 5;

    if (head) {
      newCar->next = head;
    }

    head = newCar;
  }

  simulateTrafficFlow(head);

  return 0;
}