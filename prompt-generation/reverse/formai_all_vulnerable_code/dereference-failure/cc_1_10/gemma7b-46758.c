//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Linus Torvalds
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_LANE 3
#define NUM_CARS 5

typedef struct car {
  int lane;
  int speed;
  struct car* next;
} car;

void simulateTrafficFlow(car* head) {
  time_t t = time(NULL);
  int i = 0;

  // Cars move forward at their speed
  while (head) {
    sleep(head->speed);

    // Change lane if necessary
    if (head->lane != NUM_LANE - 1 && rand() % 20 == 0) {
      head->lane++;
    }

    // Move forward in the lane
    head->next = malloc(sizeof(car));
    head->next->lane = head->lane;
    head->next->speed = head->speed;
    head = head->next;
  }

  // Wait for a while
  sleep(t + 10);

  // Free the cars
  free(head);
}

int main() {
  // Create the cars
  car* head = malloc(sizeof(car));
  head->lane = 0;
  head->speed = rand() % 5 + 1;

  for (int i = 1; i < NUM_CARS; i++) {
    car* newCar = malloc(sizeof(car));
    newCar->lane = rand() % NUM_LANE;
    newCar->speed = rand() % 5 + 1;
    newCar->next = head;
    head = newCar;
  }

  // Simulate traffic flow
  simulateTrafficFlow(head);

  return 0;
}