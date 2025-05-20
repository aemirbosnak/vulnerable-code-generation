//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: scalable
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define ROAD_LENGTH 1000

typedef struct Car {
  int x, y, direction, speed;
  struct Car* next;
} Car;

Car* createCar() {
  Car* car = (Car*)malloc(sizeof(Car));
  car->x = rand() % ROAD_LENGTH;
  car->y = rand() % ROAD_LENGTH;
  car->direction = rand() % 4;
  car->speed = rand() % 5 + 1;
  car->next = NULL;
  return car;
}

void simulateTrafficFlow() {
  Car* head = createCar();
  Car* tail = head;

  for (int i = 0; i < MAX_CARS; i++) {
    tail->next = createCar();
    tail = tail->next;
  }

  time_t start = time(NULL);
  while (time(NULL) - start < 10) {
    for (Car* car = head; car; car = car->next) {
      switch (car->direction) {
        case 0:
          car->x++;
          break;
        case 1:
          car->x--;
          break;
        case 2:
          car->y++;
          break;
        case 3:
          car->y--;
          break;
      }

      car->x = (car->x >= ROAD_LENGTH) ? 0 : car->x;
      car->x = (car->x < 0) ? ROAD_LENGTH - 1 : car->x;
      car->y = (car->y >= ROAD_LENGTH) ? 0 : car->y;
      car->y = (car->y < 0) ? ROAD_LENGTH - 1 : car->y;
    }

    sleep(1);
  }

  free(head);
}

int main() {
  simulateTrafficFlow();
  return 0;
}