//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3
#define SIMULATION_TIME 60

typedef struct Car {
  int lane;
  int position;
  int speed;
  int direction;
  struct Car* next;
} Car;

void initialize_cars(Car** head) {
  *head = NULL;
  for (int i = 0; i < MAX_CARS; i++) {
    Car* new_car = malloc(sizeof(Car));
    new_car->lane = rand() % MAX_LANE;
    new_car->position = rand() % 1000;
    new_car->speed = rand() % 5 + 1;
    new_car->direction = rand() % 2;
    new_car->next = *head;
    *head = new_car;
  }
}

void simulate_traffic(Car* head) {
  time_t start_time = time(NULL);
  for (int i = 0; i < SIMULATION_TIME; i++) {
    for (Car* current_car = head; current_car; current_car = current_car->next) {
      current_car->position += current_car->speed * i;
      if (current_car->direction == 0) {
        if (current_car->lane == 0) {
          current_car->direction = 1;
        } else {
          current_car->lane--;
        }
      } else {
        if (current_car->lane == MAX_LANE - 1) {
          current_car->direction = 0;
        } else {
          current_car->lane++;
        }
      }
    }
    time_t end_time = time(NULL);
    if (end_time - start_time > 1) {
      start_time = end_time;
    }
  }
}

int main() {
  Car* head = NULL;
  initialize_cars(&head);
  simulate_traffic(head);
  return 0;
}