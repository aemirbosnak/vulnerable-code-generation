//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: futuristic
#include <stdlib.h>
#include <time.h>

#define NUM_LANES 3
#define NUM_CARS 20

typedef struct Car {
  int lane;
  int position;
  int speed;
  int direction;
  struct Car* next;
} Car;

Car* createCar() {
  Car* car = malloc(sizeof(Car));
  car->lane = rand() % NUM_LANES;
  car->position = 0;
  car->speed = rand() % 5 + 1;
  car->direction = rand() % 2;
  car->next = NULL;
  return car;
}

void simulateTrafficFlow() {
  srand(time(NULL));
  Car* head = createCar();
  Car* tail = head;

  for (int i = 0; i < NUM_CARS - 1; i++) {
    tail->next = createCar();
    tail = tail->next;
  }

  tail->next = head;

  for (int t = 0; t < 1000; t++) {
    for (Car* car = head; car; car = car->next) {
      switch (car->direction) {
        case 0:
          car->position++;
          break;
        case 1:
          car->position--;
          break;
      }

      if (car->position >= NUM_LANES - 1) {
        car->direction = 1;
      } else if (car->position <= 0) {
        car->direction = 0;
      }
    }

    sleep(1);
  }
}

int main() {
  simulateTrafficFlow();
  return 0;
}