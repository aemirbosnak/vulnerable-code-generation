//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LANE 3
#define MAX_CARS 10

typedef struct Car {
  int lane;
  int position;
  int speed;
  struct Car* next;
} Car;

void simulateTrafficFlow() {
  Car* head = NULL;
  int numCars = 0;

  // Create a few cars
  for (int i = 0; i < MAX_CARS; i++) {
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->lane = rand() % MAX_LANE;
    newCar->position = rand() % 100;
    newCar->speed = rand() % 10;
    newCar->next = head;
    head = newCar;
    numCars++;
  }

  // Simulate traffic flow
  time_t t = time(NULL);
  while (time(NULL) - t < 10) {
    // Move cars
    for (Car* car = head; car; car = car->next) {
      car->position += car->speed * (time(NULL) - t) / 1000;
      if (car->position >= 100) {
        car->position = 0;
      }
    }

    // Update traffic light status
    // (In this example, the traffic light status is not implemented)

    // Print car positions
    for (Car* car = head; car; car = car->next) {
      printf("Car %d: Lane %d, Position %d\n", numCars, car->lane, car->position);
    }

    t = time(NULL);
  }

  // Free memory
  free(head);
}

int main() {
  simulateTrafficFlow();

  return 0;
}