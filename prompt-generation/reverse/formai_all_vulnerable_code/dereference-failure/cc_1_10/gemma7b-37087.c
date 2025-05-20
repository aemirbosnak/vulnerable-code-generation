//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: innovative
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 3
#define MAX_CARS 10

typedef struct Car {
  int lane;
  int position;
  int speed;
  struct Car* next;
} Car;

Car* createCar() {
  Car* car = malloc(sizeof(Car));
  car->lane = rand() % NUM_LANE;
  car->position = rand() % 1000;
  car->speed = rand() % 5 + 1;
  car->next = NULL;
  return car;
}

void simulateTrafficFlow() {
  Car* head = NULL;
  for (int i = 0; i < MAX_CARS; i++) {
    Car* car = createCar();
    if (head) {
      car->next = head;
    }
    head = car;
  }

  time_t start = time(NULL);
  while (time(NULL) - start < 10) {
    for (Car* car = head; car; car = car->next) {
      car->position += car->speed * time(NULL) - start;
      if (car->position > 1000) {
        car->position = 0;
      }
    }

    sleep(1);
  }

  free(head);
}

int main() {
  simulateTrafficFlow();
  return 0;
}