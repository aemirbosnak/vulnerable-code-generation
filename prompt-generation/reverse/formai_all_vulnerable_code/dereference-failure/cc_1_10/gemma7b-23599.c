//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: protected
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 3
#define NUM_CARS 10

typedef struct Car {
  int lane;
  int speed;
  int position;
} Car;

void simulateTrafficFlow(Car **cars, int numCars) {
  srand(time(NULL));

  for (int i = 0; i < numCars; i++) {
    cars[i]->lane = rand() % NUM_LANE;
    cars[i]->speed = rand() % 5 + 1;
    cars[i]->position = rand() % 1000;
  }

  for (int t = 0; t < 1000; t++) {
    for (int i = 0; i < numCars; i++) {
      cars[i]->position += cars[i]->speed;

      if (cars[i]->position >= 1000) {
        cars[i]->position = 0;
      }

      if (cars[i]->lane != rand() % NUM_LANE) {
        cars[i]->lane = rand() % NUM_LANE;
      }
    }

    // Display traffic flow
    for (int i = 0; i < numCars; i++) {
      printf("Car %d: Lane %d, Position %d, Speed %d\n", i + 1, cars[i]->lane, cars[i]->position, cars[i]->speed);
    }

    printf("\n");
  }
}

int main() {
  Car *cars = malloc(NUM_CARS * sizeof(Car));

  simulateTrafficFlow(cars, NUM_CARS);

  free(cars);

  return 0;
}