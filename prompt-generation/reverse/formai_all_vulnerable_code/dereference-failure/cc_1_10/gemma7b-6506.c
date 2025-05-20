//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define ROAD_LENGTH 100

typedef struct Car {
  int position;
  int direction;
  int speed;
  struct Car* next;
} Car;

void simulateTrafficFlow() {
  Car* head = NULL;
  for (int i = 0; i < MAX_CARS; i++) {
    Car* newCar = malloc(sizeof(Car));
    newCar->position = rand() % ROAD_LENGTH;
    newCar->direction = rand() % 2;
    newCar->speed = rand() % 5;
    newCar->next = head;
    head = newCar;
  }

  time_t start = time(NULL);
  while (time(NULL) - start < 10) {
    for (Car* car = head; car; car = car->next) {
      switch (car->direction) {
        case 0:
          car->position++;
          break;
        case 1:
          car->position--;
          break;
      }

      if (car->position >= ROAD_LENGTH) {
        car->direction = 1;
      } else if (car->position <= 0) {
        car->direction = 0;
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