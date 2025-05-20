//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: brave
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
  car->y = rand() % ROAD_LENGTH;
  car->direction = rand() % 4;
  car->speed = rand() % 5 + 1;
  car->next = NULL;
  return car;
}

void simulateTrafficFlow() {
  Car* head = createCar();
  Car* tail = head;

  for (int i = 0; i < MAX_CARS; i++) {
    tail = createCar();
    tail->next = head;
    head = tail;
  }

  time_t start = time(NULL);
  time_t end = start + 10;

  while (time(NULL) < end) {
    for (Car* car = head; car; car = car->next) {
      switch (car->direction) {
        case 0:
          car->x++;
          break;
        case 1:
          car->x--;
          break;
        case 2:
          car->y++;
          break;
        case 3:
          car->y--;
          break;
      }

      car->speed--;
      if (car->speed == 0) {
        car->direction = rand() % 4;
        car->speed = rand() % 5 + 1;
      }
    }

    sleep(1);
  }

  free(head);
}

int main() {
  simulateTrafficFlow();
  return 0;
}