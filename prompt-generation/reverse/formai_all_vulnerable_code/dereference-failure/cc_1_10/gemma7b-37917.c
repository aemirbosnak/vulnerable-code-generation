//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 3
#define NUM_CARS 10

typedef struct Car {
  int lane;
  int position;
  int speed;
  struct Car* next;
} Car;

void simulateTrafficFlow(Car* head) {
  time_t start_time = time(NULL);
  time_t current_time = start_time;
  int elapsed_time = 0;

  while (elapsed_time < 10) {
    current_time = time(NULL);
    elapsed_time = current_time - start_time;

    Car* current_car = head;
    while (current_car) {
      switch (current_car->speed) {
        case 1:
          current_car->position++;
          break;
        case 2:
          current_car->position += 2;
          break;
        case 3:
          current_car->position += 3;
          break;
      }

      if (current_car->position >= NUM_LANE - 1) {
        current_car->position = 0;
      }

      current_car = current_car->next;
    }

    sleep(1);
  }
}

int main() {
  Car* head = NULL;
  for (int i = 0; i < NUM_CARS; i++) {
    Car* new_car = malloc(sizeof(Car));
    new_car->lane = rand() % NUM_LANE;
    new_car->position = rand() % NUM_LANE;
    new_car->speed = rand() % 3 + 1;
    new_car->next = head;
    head = new_car;
  }

  simulateTrafficFlow(head);

  return 0;
}