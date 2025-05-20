//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_CARS 10
#define MAX_LANE 3

struct car {
  int x, y, speed, direction, lane;
  struct car* next;
};

void simulateTrafficFlow() {
  struct car* head = NULL;
  for (int i = 0; i < MAX_CARS; i++) {
    struct car* newCar = malloc(sizeof(struct car));
    newCar->x = rand() % MAX_LANE;
    newCar->y = rand() % MAX_LANE;
    newCar->speed = rand() % 5;
    newCar->direction = rand() % 4;
    newCar->lane = rand() % MAX_LANE;
    newCar->next = head;
    head = newCar;
  }

  while (head) {
    switch (head->direction) {
      case 0:
        head->x++;
        break;
      case 1:
        head->x--;
        break;
      case 2:
        head->y++;
        break;
      case 3:
        head->y--;
        break;
    }

    head->lane = (head->x + head->y) % MAX_LANE;

    if (head->next) {
      struct car* current = head;
      struct car* previous = NULL;
      while (current->next) {
        if (current->lane == previous->lane) {
          current->speed = previous->speed;
        }
        previous = current;
        current = current->next;
      }
    }

    head = head->next;
  }
}

int main() {
  simulateTrafficFlow();
  return 0;
}