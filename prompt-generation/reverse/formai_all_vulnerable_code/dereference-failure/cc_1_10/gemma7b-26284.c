//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
  int lane;
  int speed;
  int position;
  struct Car* next;
} Car;

Car* createCar(int lane, int speed, int position) {
  Car* car = malloc(sizeof(Car));
  car->lane = lane;
  car->speed = speed;
  car->position = position;
  car->next = NULL;
  return car;
}

void simulateTrafficFlow(Car* head) {
  time_t start = time(NULL);
  while (time(NULL) - start < 10) {
    for (Car* car = head; car; car = car->next) {
      car->position++;
      if (car->position >= MAX_LANE * 2) {
        car->position = 0;
      }
      switch (car->speed) {
        case 1:
          car->lane = (car->lane - 1) % MAX_LANE;
          break;
        case 2:
          car->lane = (car->lane + 1) % MAX_LANE;
          break;
        case 3:
          car->lane = (car->lane - 2) % MAX_LANE;
          break;
      }
    }
    sleep(1);
  }
}

int main() {
  Car* head = createCar(0, 1, 0);
  head = createCar(1, 2, 1);
  head = createCar(2, 3, 2);

  simulateTrafficFlow(head);

  return 0;
}