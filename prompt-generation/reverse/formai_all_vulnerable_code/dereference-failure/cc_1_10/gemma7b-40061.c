//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 3
#define MAX_CARS 10

typedef struct Car {
  int lane;
  int speed;
  int position;
  struct Car* next;
} Car;

void simulateTrafficFlow(Car* head) {
  time_t tStart = time(NULL);
  while (time(NULL) - tStart < 60) {
    for (Car* car = head; car; car = car->next) {
      switch (car->lane) {
        case 0:
          car->position++;
          if (car->position >= 10) {
            car->position = 0;
          }
          break;
        case 1:
          car->position++;
          if (car->position >= 8) {
            car->position = 0;
          }
          break;
        case 2:
          car->position++;
          if (car->position >= 6) {
            car->position = 0;
          }
          break;
      }
    }
    sleep(1);
  }
}

int main() {
  Car* head = NULL;
  for (int i = 0; i < MAX_CARS; i++) {
    Car* car = (Car*)malloc(sizeof(Car));
    car->lane = rand() % NUM_LANE;
    car->speed = rand() % 5 + 1;
    car->position = rand() % 10;
    car->next = head;
    head = car;
  }

  simulateTrafficFlow(head);

  return 0;
}