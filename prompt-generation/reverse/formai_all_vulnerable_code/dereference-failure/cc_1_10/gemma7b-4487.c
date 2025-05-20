//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: minimalist
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
  int x, y, dir, speed;
  struct Car* next;
} Car;

Car* createCar() {
  Car* car = malloc(sizeof(Car));
  car->x = rand() % 10;
  car->y = rand() % 10;
  car->dir = rand() % 4;
  car->speed = rand() % 3 + 1;
  car->next = NULL;
  return car;
}

void simulateTrafficFlow() {
  Car* head = createCar();
  head->next = createCar();
  head->next->next = createCar();

  time_t t = time(NULL);
  while (time(NULL) - t < 60) {
    for (Car* car = head; car; car = car->next) {
      switch (car->dir) {
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

      car->x = (car->x + car->speed) % 10;
      car->y = (car->y + car->speed) % 10;
    }

    sleep(1);
  }
}

int main() {
  simulateTrafficFlow();
  return 0;
}