//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
  int lane;
  int position;
  int speed;
  struct Car* next;
} Car;

Car* createCar(int lane, int position, int speed) {
  Car* newCar = malloc(sizeof(Car));
  newCar->lane = lane;
  newCar->position = position;
  newCar->speed = speed;
  newCar->next = NULL;
  return newCar;
}

void simulateTrafficFlow(Car* head) {
  while (head) {
    switch (head->speed) {
      case 1:
        head->position++;
        break;
      case 2:
        head->position += 2;
        break;
      case 3:
        head->position += 3;
        break;
    }

    if (head->position >= MAX_LANE) {
      head->position = MAX_LANE - 1;
    }

    head = head->next;
  }
}

int main() {
  Car* head = createCar(0, 0, 2);
  head->next = createCar(1, 1, 1);
  head->next->next = createCar(2, 2, 3);

  simulateTrafficFlow(head);

  return 0;
}