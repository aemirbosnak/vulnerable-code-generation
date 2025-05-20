//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define NUM_LANE 3
#define MAX_CARS 10

typedef struct Car {
  int position;
  int speed;
  int lane;
  struct Car* next;
} Car;

void simulateTrafficFlow(Car* head) {
  // Define traffic light timing
  int timer = 0;
  int current_light = 0;

  // Simulate traffic flow for a certain time
  while (timer < 100) {
    // Update car positions and speeds
    Car* car = head;
    while (car) {
      car->position += car->speed;

      // Lane change logic
      if (car->speed > 0) {
        if (car->position % NUM_LANE == 0) {
          car->lane++;
        }
      }

      car = car->next;
    }

    // Update traffic light status
    timer++;
    current_light = (current_light + 1) % NUM_LANE;

    // Print traffic flow status
    printf("Time: %d, Light: %d, Cars: ", timer, current_light);
    car = head;
    while (car) {
      printf("Lane: %d, Position: %d, Speed: %d ", car->lane, car->position, car->speed);
      car = car->next;
    }
    printf("\n");
  }
}

int main() {
  // Create a linked list of cars
  Car* head = malloc(sizeof(Car));
  head->position = 0;
  head->speed = 5;
  head->lane = 1;
  head->next = malloc(sizeof(Car));
  head->next->position = 10;
  head->next->speed = 3;
  head->next->lane = 2;
  head->next->next = malloc(sizeof(Car));
  head->next->next->position = 20;
  head->next->next->speed = 2;
  head->next->next->lane = 1;

  // Simulate traffic flow
  simulateTrafficFlow(head);

  return 0;
}