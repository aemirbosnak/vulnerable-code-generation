//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: excited
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
  int x, y, direction, speed;
  struct Car* next;
} Car;

void initialize_cars(Car** head) {
  *head = NULL;
  for (int i = 0; i < MAX_CARS; i++) {
    *head = malloc(sizeof(Car));
    ((*head)->x = rand() % MAX_LANE) * 2;
    ((*head)->y = rand() % MAX_LANE) * 2;
    ((*head)->direction = rand() % 4) + 1;
    ((*head)->speed = rand() % 5) + 1;
    ((*head)->next = NULL);
    head = &((*head)->next);
  }
}

void simulate_traffic(Car* head) {
  time_t start = time(NULL);
  while (time(NULL) - start < 10) {
    for (Car* car = head; car; car = car->next) {
      switch (car->direction) {
        case 1:
          car->x++;
          break;
        case 2:
          car->x--;
          break;
        case 3:
          car->y++;
          break;
        case 4:
          car->y--;
          break;
      }

      car->speed++;
      if (car->speed > MAX_CARS) {
        car->speed = MAX_CARS;
      }
    }

    sleep(1);
  }
}

int main() {
  Car* head = NULL;
  initialize_cars(&head);
  simulate_traffic(head);

  return 0;
}