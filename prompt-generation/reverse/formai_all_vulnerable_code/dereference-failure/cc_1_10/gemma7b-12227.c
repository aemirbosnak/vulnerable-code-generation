//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: sophisticated
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
  int x, y, direction, speed;
  struct Car* next;
} Car;

Car* createCar() {
  Car* car = (Car*)malloc(sizeof(Car));
  car->x = rand() % MAX_LANE;
  car->y = rand() % MAX_CARS;
  car->direction = rand() % 2;
  car->speed = rand() % 5 + 1;
  car->next = NULL;
  return car;
}

void moveCar(Car* car) {
  switch (car->direction) {
    case 0:
      car->x++;
      break;
    case 1:
      car->x--;
      break;
  }
  car->y++;
  car->speed--;
  if (car->speed == 0) {
    car->direction = rand() % 2;
    car->speed = rand() % 5 + 1;
  }
}

void simulateTrafficFlow() {
  srand(time(NULL));
  Car* head = createCar();
  while (head) {
    moveCar(head);
    Car* tmp = head;
    head = head->next;
    free(tmp);
  }
}

int main() {
  simulateTrafficFlow();
  return 0;
}