//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: accurate
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100

struct car {
  int x, y, speed, direction;
  struct car* next;
};

void simulateTrafficFlow(int numCars) {
  struct car* head = NULL;
  for (int i = 0; i < numCars; i++) {
    struct car* newCar = malloc(sizeof(struct car));
    newCar->x = rand() % 1000;
    newCar->y = rand() % 1000;
    newCar->speed = rand() % 10;
    newCar->direction = rand() % 4;
    newCar->next = head;
    head = newCar;
  }

  time_t startTime = time(NULL);
  while (time(NULL) - startTime < 60) {
    for (struct car* currentCar = head; currentCar; currentCar = currentCar->next) {
      switch (currentCar->direction) {
        case 0:
          currentCar->x++;
          break;
        case 1:
          currentCar->y++;
          break;
        case 2:
          currentCar->x--;
          break;
        case 3:
          currentCar->y--;
          break;
      }

      if (currentCar->x >= 1000 || currentCar->x <= 0) {
        currentCar->direction = (currentCar->direction + 1) % 4;
      }

      if (currentCar->y >= 1000 || currentCar->y <= 0) {
        currentCar->direction = (currentCar->direction + 1) % 4;
      }
    }

    sleep(1);
  }

  free(head);
}

int main() {
  simulateTrafficFlow(20);
  return 0;
}