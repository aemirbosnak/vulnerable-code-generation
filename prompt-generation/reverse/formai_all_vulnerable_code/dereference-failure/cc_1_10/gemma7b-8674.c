//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Cyberpunk
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
  car->position = rand() % 100;
  car->next = NULL;
  return car;
}

void simulateTrafficFlow() {
  srand(time(NULL));
  Car* head = createCar();
  Car* tail = head;

  for (int i = 0; i < MAX_CARS; i++) {
    tail->next = createCar();
    tail = tail->next;
  }

  tail = head;

  for (int i = 0; i < 10; i++) {
    for (Car* car = head; car; car = car->next) {
      car->position += car->speed;

      if (car->position >= 100) {
        car->position = 0;
      }

      printf("%d ", car->position);
    }

    printf("\n");
    sleep(1);
  }
}

int main() {
  simulateTrafficFlow();

  return 0;
}