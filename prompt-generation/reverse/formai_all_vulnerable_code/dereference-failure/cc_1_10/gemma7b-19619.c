//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: peaceful
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
  int x, y, direction, speed;
  struct Car* next;
} Car;

void simulateTrafficFlow(Car* head) {
  srand(time(NULL));

  for (int i = 0; i < MAX_CARS; i++) {
    Car* newCar = malloc(sizeof(Car));
    newCar->x = rand() % 1000;
    newCar->y = rand() % 1000;
    newCar->direction = rand() % 4;
    newCar->speed = rand() % 5 + 1;

    if (head) {
      newCar->next = head;
      head = newCar;
    } else {
      head = newCar;
    }
  }

  while (head) {
    switch (head->direction) {
      case 0:
        head->x++;
        break;
      case 1:
        head->y++;
        break;
      case 2:
        head->x--;
        break;
      case 3:
        head->y--;
        break;
    }

    head->x += head->speed;
    head->y += head->speed;

    if (head->x > 1000 || head->x < 0) {
      head->direction = (head->direction + 1) % 4;
    }

    if (head->y > 1000 || head->y < 0) {
      head->direction = (head->direction + 1) % 4;
    }

    head = head->next;
  }
}

int main() {
  simulateTrafficFlow(NULL);

  return 0;
}