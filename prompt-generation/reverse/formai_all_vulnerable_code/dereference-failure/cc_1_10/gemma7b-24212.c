//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: active
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct car {
  int x, y, direction, speed;
  struct car* next;
} car;

car* createCar() {
  car* newCar = (car*)malloc(sizeof(car));
  newCar->x = rand() % MAX_LANE;
  newCar->y = rand() % MAX_CARS;
  newCar->direction = rand() % 2;
  newCar->speed = rand() % 5 + 1;
  newCar->next = NULL;
  return newCar;
}

void moveCar(car* car) {
  switch (car->direction) {
    case 0:
      car->x++;
      break;
    case 1:
      car->x--;
      break;
  }
  car->y++;
  if (car->y == MAX_CARS) {
    car->direction = (car->direction + 1) % 2;
  }
}

int main() {
  srand(time(NULL));

  car* head = createCar();
  while (head) {
    moveCar(head);
    printf("Car position: (%d, %d)\n", head->x, head->y);
    sleep(head->speed);
    head = head->next;
  }

  return 0;
}