//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: modular
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

void simulateTrafficFlow(Car* head) {
  time_t t = time(NULL);
  srand(t);

  while (head) {
    Car* currentCar = head;
    while (currentCar) {
      // Randomly change direction
      if (rand() % 100 < 20) {
        currentCar->direction *= -1;
      }

      // Move car forward
      currentCar->position += currentCar->direction;

      // Wrap car around the lane
      if (currentCar->position >= MAX_LANE) {
        currentCar->position = 0;
      } else if (currentCar->position < 0) {
        currentCar->position = MAX_LANE - 1;
      }

      // Update car's position
      currentCar->next->position = currentCar->position;

      currentCar = currentCar->next;
    }

    // Sleep for a while
    sleep(rand() % 2);
  }
}

int main() {
  Car* head = NULL;

  // Create some cars
  for (int i = 0; i < MAX_CARS; i++) {
    Car* newCar = malloc(sizeof(Car));
    newCar->lane = rand() % MAX_LANE;
    newCar->position = rand() % MAX_LANE;
    newCar->direction = rand() % 2 - 1;
    newCar->next = head;
    head = newCar;
  }

  // Simulate traffic flow
  simulateTrafficFlow(head);

  return 0;
}