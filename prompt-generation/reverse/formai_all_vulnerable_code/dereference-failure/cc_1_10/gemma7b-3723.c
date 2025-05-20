//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: grateful
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

struct Car {
  int x, y, direction, speed, lane;
  struct Car* next;
};

void simulateTrafficFlow(struct Car* head) {
  struct Car* currentCar = head;
  while (currentCar) {
    switch (currentCar->direction) {
      case 0: // East
        currentCar->x++;
        break;
      case 1: // South
        currentCar->y--;
        break;
      case 2: // West
        currentCar->x--;
        break;
      case 3: // North
        currentCar->y++;
        break;
    }

    currentCar->speed++;

    if (currentCar->speed >= 5) {
      currentCar->speed = 5;
    }

    currentCar = currentCar->next;
  }
}

int main() {
  struct Car* head = NULL;

  // Create a few cars
  for (int i = 0; i < MAX_CARS; i++) {
    struct Car* newCar = malloc(sizeof(struct Car));
    newCar->x = i;
    newCar->y = 0;
    newCar->direction = 0;
    newCar->speed = 1;
    newCar->lane = 1;
    newCar->next = head;
    head = newCar;
  }

  // Simulate traffic flow
  simulateTrafficFlow(head);

  return 0;
}