//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: shocked
#include <stdlib.h>
#include <time.h>

#define MAX_Cars 10

typedef struct Car {
  int x, y, direction, speed;
  struct Car* next;
} Car;

Car* createCar() {
  Car* car = malloc(sizeof(Car));
  car->x = rand() % 10;
  car->y = rand() % 10;
  car->direction = rand() % 4;
  car->speed = rand() % 3;
  car->next = NULL;
  return car;
}

void moveCars(Car* car) {
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

  car->speed++;
  if (car->speed > 5) {
    car->speed = 5;
  }
}

void simulateTrafficFlow() {
  srand(time(NULL));

  Car* head = createCar();
  Car* tail = head;

  while (tail->next) {
    moveCars(tail);
    tail = tail->next;
  }

  moveCars(head);

  free(head);
}

int main() {
  simulateTrafficFlow();

  return 0;
}