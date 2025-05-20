//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: mind-bending
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define ROAD_LENGTH 100

typedef struct Car {
  int x, y, direction, speed;
  struct Car* next;
} Car;

Car* createCar() {
  Car* car = malloc(sizeof(Car));
  car->x = rand() % ROAD_LENGTH;
  car->y = rand() % MAX_CARS;
  car->direction = rand() % 4;
  car->speed = rand() % 5;
  car->next = NULL;
  return car;
}

void simulateTrafficFlow() {
  Car* head = createCar();
  Car* tail = head;

  while (tail->next) {
    switch (tail->direction) {
      case 0:
        tail->x++;
        break;
      case 1:
        tail->x--;
        break;
      case 2:
        tail->y++;
        break;
      case 3:
        tail->y--;
        break;
    }

    tail = tail->next;
  }

  free(head);
}

int main() {
  simulateTrafficFlow();

  return 0;
}