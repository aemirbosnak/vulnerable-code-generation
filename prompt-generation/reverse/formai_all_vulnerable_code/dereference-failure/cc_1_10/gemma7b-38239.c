//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: surrealist
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 4
#define NUM_CARS 10

typedef struct Car {
  int lane;
  int speed;
  int direction;
  struct Car* next;
} Car;

Car* createCar() {
  Car* car = malloc(sizeof(Car));
  car->lane = rand() % NUM_LANE;
  car->speed = rand() % 5;
  car->direction = rand() % 2;
  car->next = NULL;
  return car;
}

void simulateTrafficFlow() {
  srand(time(NULL));
  Car* head = createCar();
  head->next = createCar();
  head->next->next = createCar();
  head->next->next->next = createCar();

  while (head) {
    switch (head->direction) {
      case 0:
        head->lane++;
        break;
      case 1:
        head->lane--;
        break;
    }

    head->speed++;
    if (head->speed > 10) {
      head->speed = 10;
    }

    head = head->next;
  }
}

int main() {
  simulateTrafficFlow();
  return 0;
}