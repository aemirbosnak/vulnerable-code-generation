//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
  int lane;
  int position;
  int speed;
  struct Car* next;
} Car;

Car* createCar() {
  Car* car = malloc(sizeof(Car));
  car->lane = rand() % MAX_LANE;
  car->position = rand() % MAX_CARS;
  car->speed = rand() % 5;
  car->next = NULL;
  return car;
}

void simulateTrafficFlow() {
  Car* head = createCar();
  Car* tail = head;

  for (int i = 0; i < 1000; i++) {
    // Move cars
    tail->position++;
    if (tail->position >= MAX_CARS) {
      tail->position = 0;
    }

    // Change lanes
    if (rand() % 20 == 0) {
      tail->lane = rand() % MAX_LANE;
    }

    // Update tail
    if (tail->next) {
      tail = tail->next;
    } else {
      tail = head;
    }
  }

  // Print traffic flow
  printf("Traffic flow:\n");
  for (Car* car = head; car; car = car->next) {
    printf("Lane: %d, Position: %d, Speed: %d\n", car->lane, car->position, car->speed);
  }
}

int main() {
  simulateTrafficFlow();
  return 0;
}