//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: peaceful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10

struct car {
  int x, y, direction, speed;
  struct car* next;
};

void create_car(struct car** head) {
  struct car* new_car = malloc(sizeof(struct car));
  new_car->x = rand() % 10;
  new_car->y = rand() % 10;
  new_car->direction = rand() % 4;
  new_car->speed = rand() % 3;
  new_car->next = *head;
  *head = new_car;
}

void simulate_traffic(struct car* head) {
  time_t t = time(NULL);
  struct car* current_car = head;
  while (current_car) {
    switch (current_car->direction) {
      case 0:
        current_car->x++;
        break;
      case 1:
        current_car->y++;
        break;
      case 2:
        current_car->x--;
        break;
      case 3:
        current_car->y--;
        break;
    }

    current_car->speed++;
    if (current_car->speed > 5) {
      current_car->speed = 5;
    }

    printf("Car at (%d, %d) moving %d at speed %d\n", current_car->x, current_car->y, current_car->direction, current_car->speed);

    sleep(1);
    t = time(NULL);
  }
}

int main() {
  struct car* head = NULL;
  for (int i = 0; i < MAX_CARS; i++) {
    create_car(&head);
  }
  simulate_traffic(head);
  return 0;
}