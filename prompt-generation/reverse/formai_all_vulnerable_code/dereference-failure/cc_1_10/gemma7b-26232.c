//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
  int x, y, direction, speed;
  struct Car* next;
} Car;

void simulateTrafficFlow(Car** head) {
  time_t start = time(NULL);
  int elapsedTime = 0;
  while (elapsedTime < 10) {
    for (Car* car = head; car; car = car->next) {
      switch (car->direction) {
        case 0:
          car->x++;
          break;
        case 1:
          car->y++;
          break;
        case 2:
          car->x--;
          break;
        case 3:
          car->y--;
          break;
      }

      car->speed++;
      if (car->speed > 5) {
        car->speed = 5;
      }

      if (time(NULL) - start >= 1) {
        elapsedTime++;
        start = time(NULL);
      }
    }
  }

  for (Car* car = head; car; car = car->next) {
    printf("Car position: (%d, %d)\n", car->x, car->y);
  }
}

int main() {
  Car** head = malloc(sizeof(Car*) * MAX_CARS);
  for (int i = 0; i < MAX_CARS; i++) {
    head[i] = malloc(sizeof(Car));
  }

  simulateTrafficFlow(head);

  for (int i = 0; i < MAX_CARS; i++) {
    free(head[i]);
  }
  free(head);

  return 0;
}