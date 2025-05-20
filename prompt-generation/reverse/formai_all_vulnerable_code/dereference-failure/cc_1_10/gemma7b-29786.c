//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: active
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

Car* createCar() {
  Car* car = malloc(sizeof(Car));
  car->lane = rand() % NUM_LANE;
  car->speed = rand() % 5 + 1;
  car->position = 0;
  car->next = NULL;
  return car;
}

void simulateTrafficFlow() {
  srand(time(NULL));

  Car* head = NULL;
  for (int i = 0; i < MAX_CARS; i++) {
    Car* car = createCar();
    if (head == NULL) {
      head = car;
    } else {
      head->next = car;
      head = car;
    }
  }

  while (head) {
    // Move cars
    for (Car* car = head; car; car = car->next) {
      car->position++;
      if (car->position >= 100) {
        car->position = 0;
      }
    }

    // Collision detection
    for (Car* car1 = head; car1; car1 = car1->next) {
      for (Car* car2 = head; car2; car2 = car2->next) {
        if (car1 != car2 && car1->lane == car2->lane && car1->position == car2->position) {
          printf("Collision!\n");
          exit(1);
        }
      }
    }

    // Print car positions
    for (Car* car = head; car; car = car->next) {
      printf("Car %d: lane %d, position %d\n", car->position, car->lane, car->position);
    }

    // Sleep for a while
    sleep(1);
  }
}

int main() {
  simulateTrafficFlow();
  return 0;
}