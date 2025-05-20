//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: immersive
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_SPEED 5

typedef struct Car {
  int x, y, speed, direction;
  struct Car* next;
} Car;

Car* createCar() {
  Car* car = malloc(sizeof(Car));
  car->x = rand() % 10;
  car->y = rand() % 10;
  car->speed = rand() % MAX_SPEED;
  car->direction = rand() % 4;
  car->next = NULL;
  return car;
}

void simulateTrafficFlow() {
  Car* head = createCar();
  while (head) {
    switch (head->direction) {
      case 0:
        head->x++;
        break;
      case 1:
        head->x--;
        break;
      case 2:
        head->y++;
        break;
      case 3:
        head->y--;
        break;
    }

    head->speed--;

    if (head->speed == 0) {
      head = head->next;
    }
  }
}

int main() {
  simulateTrafficFlow();
  return 0;
}