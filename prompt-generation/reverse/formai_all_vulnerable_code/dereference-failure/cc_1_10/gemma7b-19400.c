//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
  int lane;
  int position;
  int direction;
  struct Car* next;
} Car;

Car* createCar() {
  Car* car = (Car*)malloc(sizeof(Car));
  car->lane = rand() % MAX_LANE;
  car->position = rand() % MAX_LANE;
  car->direction = rand() % 2;
  car->next = NULL;
  return car;
}

void simulateTrafficFlow(Car* head) {
  time_t t = time(NULL);
  int i = 0;
  while (time(NULL) - t < 10) {
    for (Car* car = head; car; car = car->next) {
      switch (car->direction) {
        case 0:
          car->position++;
          if (car->position >= MAX_LANE) {
            car->direction = 1;
            car->position = MAX_LANE - 1;
          }
          break;
        case 1:
          car->position--;
          if (car->position <= 0) {
            car->direction = 0;
            car->position = 0;
          }
          break;
      }
    }
    i++;
  }
}

int main() {
  Car* head = createCar();
  simulateTrafficFlow(head);
  return 0;
}