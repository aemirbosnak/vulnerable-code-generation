//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
  int position;
  int direction;
  int speed;
  struct Car* next;
} Car;

void initializeCars(Car** head) {
  *head = NULL;
  for (int i = 0; i < MAX_CARS; i++) {
    Car* newCar = malloc(sizeof(Car));
    newCar->position = rand() % 10;
    newCar->direction = rand() % 2;
    newCar->speed = rand() % 5;
    newCar->next = *head;
    *head = newCar;
  }
}

void simulateTrafficFlow(Car* head) {
  time_t t = time(NULL);
  int time = 0;
  while (time < 60) {
    for (Car* car = head; car; car = car->next) {
      switch (car->direction) {
        case 0:
          car->position++;
          break;
        case 1:
          car->position--;
          break;
      }

      car->speed++;
      if (car->speed > 10) {
        car->speed = 10;
      }

      printf("Car %d: position %d, speed %d\n", car->position, car->speed);
    }

    time++;
    sleep(1);
  }
}

int main() {
  Car* head = NULL;
  initializeCars(&head);
  simulateTrafficFlow(head);

  return 0;
}