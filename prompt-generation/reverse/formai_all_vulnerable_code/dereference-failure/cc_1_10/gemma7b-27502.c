//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: retro
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_LANE 3
#define NUM_CARS 5

typedef struct Car {
  int lane;
  int position;
  int speed;
  struct Car* next;
} Car;

Car* head = NULL;

void initialize_cars() {
  head = malloc(sizeof(Car));
  head->lane = 1;
  head->position = 0;
  head->speed = 2;
  head->next = NULL;

  for (int i = 1; i < NUM_CARS; i++) {
    Car* new_car = malloc(sizeof(Car));
    new_car->lane = i + 1;
    new_car->position = i * 10;
    new_car->speed = 2;
    new_car->next = NULL;

    head->next = new_car;
    head = new_car;
  }
}

void simulate_traffic() {
  time_t t = time(NULL);
  srand(t);

  for (int i = 0; i < 100; i++) {
    for (Car* car = head; car; car = car->next) {
      car->position += car->speed * rand() % 2;

      if (car->position >= NUM_LANE * 10) {
        car->position = 0;
      }
    }

    sleep(1);
  }
}

int main() {
  initialize_cars();
  simulate_traffic();

  return 0;
}