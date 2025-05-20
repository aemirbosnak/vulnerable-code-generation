//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
  int lane;
  int position;
  int speed;
  struct Car* next;
} Car;

Car* createCar(int lane, int position, int speed) {
  Car* car = malloc(sizeof(Car));
  car->lane = lane;
  car->position = position;
  car->speed = speed;
  car->next = NULL;
  return car;
}

void simulateTrafficFlow(Car* head) {
  time_t tStart = time(NULL);
  while (time(NULL) - tStart < 10) {
    for (Car* car = head; car; car = car->next) {
      switch (car->speed) {
        case 1:
          car->position++;
          if (car->position >= MAX_LANE) {
            car->position = MAX_LANE - 1;
          }
          break;
        case 2:
          car->position++;
          if (car->position >= MAX_LANE) {
            car->position = MAX_LANE - 1;
          }
          car->position++;
          break;
        case 3:
          car->position++;
          if (car->position >= MAX_LANE) {
            car->position = MAX_LANE - 1;
          }
          car->position++;
          car->position++;
          break;
      }
    }

    sleep(1);
  }
}

int main() {
  Car* head = createCar(0, 0, 1);
  head = createCar(1, 0, 2);
  head = createCar(2, 0, 3);

  simulateTrafficFlow(head);

  return 0;
}