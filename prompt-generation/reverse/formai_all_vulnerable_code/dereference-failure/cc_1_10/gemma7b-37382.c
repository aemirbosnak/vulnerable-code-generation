//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: detailed
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_LANE 3
#define NUM_CARS 10

typedef struct Car {
  int position;
  int lane;
  int direction;
  struct Car* next;
} Car;

void simulateTrafficFlow(Car* head) {
  time_t t = time(NULL);
  while (time(NULL) - t < 60) {
    for (Car* car = head; car; car = car->next) {
      switch (car->direction) {
        case 0:
          car->position++;
          if (car->position >= NUM_LANE) {
            car->direction = 1;
          }
          break;
        case 1:
          car->position--;
          if (car->position <= 0) {
            car->direction = 0;
          }
          break;
      }
    }
    sleep(1);
  }
}

int main() {
  Car* head = NULL;
  for (int i = 0; i < NUM_CARS; i++) {
    Car* car = malloc(sizeof(Car));
    car->position = rand() % NUM_LANE;
    car->lane = rand() % NUM_LANE;
    car->direction = rand() % 2;
    car->next = head;
    head = car;
  }

  simulateTrafficFlow(head);

  return 0;
}