//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: surrealist
#include <stdlib.h>
#include <time.h>

#define NUM_LANES 3
#define NUM_CARS 50

typedef struct Car {
  int lane;
  int speed;
  int direction;
  struct Car* next;
} Car;

void simulateTrafficFlow() {
  Car* head = malloc(sizeof(Car));
  head->lane = 1;
  head->speed = rand() % 5 + 1;
  head->direction = rand() % 2 == 0 ? -1 : 1;
  head->next = NULL;

  Car* tail = head;
  for (int i = 0; i < NUM_CARS - 1; i++) {
    tail->next = malloc(sizeof(Car));
    tail = tail->next;
    tail->lane = rand() % NUM_LANES + 1;
    tail->speed = rand() % 5 + 1;
    tail->direction = rand() % 2 == 0 ? -1 : 1;
    tail->next = NULL;
  }

  time_t start = time(NULL);
  while (time(NULL) - start < 30) {
    for (Car* car = head; car; car = car->next) {
      switch (car->direction) {
        case -1:
          car->lane++;
          break;
        case 1:
          car->lane--;
          break;
      }

      if (car->lane > NUM_LANES - 1) {
        car->direction = 1;
      } else if (car->lane < 0) {
        car->direction = -1;
      }

      car->speed--;
      if (car->speed < 0) {
        car->speed = 0;
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