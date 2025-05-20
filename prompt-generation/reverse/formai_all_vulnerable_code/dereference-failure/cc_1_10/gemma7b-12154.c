//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: enthusiastic
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50

typedef struct car {
  int x, y, direction, speed;
  struct car* next;
} car;

car* createCar() {
  car* newCar = (car*)malloc(sizeof(car));
  newCar->x = rand() % 1000;
  newCar->y = rand() % 1000;
  newCar->direction = rand() % 4;
  newCar->speed = rand() % 10;
  newCar->next = NULL;
  return newCar;
}

void simulateTrafficFlow() {
  srand(time(NULL));
  car* head = createCar();
  head->next = createCar();
  head->next->next = createCar();
  head->next->next->next = createCar();

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