//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
  int x, y, direction, speed;
  struct Car* next;
} Car;

Car* head = NULL;

void add_car() {
  Car* new_car = malloc(sizeof(Car));
  new_car->x = rand() % 10;
  new_car->y = rand() % 10;
  new_car->direction = rand() % 4;
  new_car->speed = rand() % 3;
  new_car->next = head;
  head = new_car;
}

void move_cars() {
  Car* current = head;
  while (current) {
    switch (current->direction) {
      case 0:
        current->x++;
        break;
      case 1:
        current->y++;
        break;
      case 2:
        current->x--;
        break;
      case 3:
        current->y--;
        break;
    }

    current->speed--;
    if (current->speed == 0) {
      add_car();
    }
    current = current->next;
  }
}

int main() {
  srand(time(NULL));
  for (int i = 0; i < MAX_CARS; i++) {
    add_car();
  }

  while (1) {
    move_cars();
    sleep(1);
  }

  return 0;
}