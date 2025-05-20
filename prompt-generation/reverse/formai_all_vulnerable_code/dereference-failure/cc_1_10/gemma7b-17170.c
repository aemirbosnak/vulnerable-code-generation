//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_NUM_CARS 10
#define MAX_SPEED 5

typedef struct Car {
  int x, y, speed, direction;
  struct Car* next;
} Car;

void initializeTrafficFlow(Car** head) {
  *head = NULL;
  for (int i = 0; i < MAX_NUM_CARS; i++) {
    Car* newCar = malloc(sizeof(Car));
    newCar->x = rand() % 100;
    newCar->y = rand() % 100;
    newCar->speed = rand() % MAX_SPEED;
    newCar->direction = rand() % 4;
    newCar->next = *head;
    *head = newCar;
  }
}

void simulateTrafficFlow(Car* head) {
  time_t t = time(NULL);
  while (time(NULL) - t < 60) {
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
    }
    sleep(1);
  }
}

int main() {
  Car* head = NULL;
  initializeTrafficFlow(&head);
  simulateTrafficFlow(head);
  return 0;
}