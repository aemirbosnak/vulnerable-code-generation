//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Cryptic
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct car {
  int x, y, direction, speed;
  struct car* next;
} car;

car* createCar() {
  car* newCar = malloc(sizeof(car));
  newCar->x = rand() % 10;
  newCar->y = rand() % 10;
  newCar->direction = rand() % 4;
  newCar->speed = rand() % 3;
  newCar->next = NULL;
  return newCar;
}

void moveCar(car* car) {
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
  if (car->speed >= 5) {
    car->speed = 5;
  }
}

int main() {
  srand(time(NULL));

  car* head = createCar();
  head->next = createCar();
  head->next->next = createCar();

  for (int i = 0; i < 100; i++) {
    moveCar(head);
  }

  return 0;
}