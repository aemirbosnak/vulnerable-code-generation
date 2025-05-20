//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: ultraprecise
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 20

typedef struct Car {
  int x, y, direction, speed, lane;
  struct Car* next;
} Car;

Car* createCar(int x, int y, int direction, int speed, int lane) {
  Car* car = (Car*)malloc(sizeof(Car));
  car->x = x;
  car->y = y;
  car->direction = direction;
  car->speed = speed;
  car->lane = lane;
  car->next = NULL;
  return car;
}

void moveCar(Car* car, int dx, int dy) {
  car->x += dx;
  car->y += dy;
}

void updateCars(Car* head) {
  Car* current = head;
  while (current) {
    switch (current->direction) {
      case 0:
        moveCar(current, 1, 0);
        break;
      case 1:
        moveCar(current, 0, 1);
        break;
      case 2:
        moveCar(current, -1, 0);
        break;
      case 3:
        moveCar(current, 0, -1);
        break;
    }
    current = current->next;
  }
}

void simulateTrafficFlow(int numCars) {
  Car* head = NULL;
  for (int i = 0; i < numCars; i++) {
    head = createCar(rand() % 10, rand() % 10, rand() % 4, rand() % 5, rand() % 3);
    if (head) {
      head->next = head;
    }
  }

  updateCars(head);

  while (head) {
    printf("Car location: x=%d, y=%d, lane=%d\n", head->x, head->y, head->lane);
    head = head->next;
  }
}

int main() {
  simulateTrafficFlow(10);
  return 0;
}