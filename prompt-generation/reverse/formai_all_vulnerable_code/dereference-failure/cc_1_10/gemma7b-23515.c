//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: genius
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
  int x, y, dir, speed;
  struct Car* next;
} Car;

Car* createCar() {
  Car* car = malloc(sizeof(Car));
  car->x = rand() % 1000;
  car->y = rand() % 1000;
  car->dir = rand() % 4;
  car->speed = rand() % 5;
  car->next = NULL;
  return car;
}

void moveCar(Car* car) {
  switch (car->dir) {
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

  if (car->speed > 10) {
    car->speed = 10;
  }
}

int main() {
  srand(time(NULL));

  Car* head = createCar();
  Car* tail = head;

  for (int i = 0; i < MAX_CARS; i++) {
    tail = createCar();
    tail->next = head;
    head = tail;
  }

  for (int i = 0; i < 1000; i++) {
    for (Car* car = head; car; car = car->next) {
      moveCar(car);
    }
    sleep(1);
  }

  return 0;
}