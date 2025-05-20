//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: active
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_SPEED 5

typedef struct car {
  int x, y, speed, direction;
  struct car* next;
} car;

car* create_car() {
  car* new_car = malloc(sizeof(car));
  new_car->x = rand() % 1000;
  new_car->y = rand() % 1000;
  new_car->speed = rand() % MAX_SPEED;
  new_car->direction = rand() % 4;
  new_car->next = NULL;
  return new_car;
}

void simulate_traffic(car* head) {
  time_t start_time = time(NULL);
  while (time(NULL) - start_time < 10) {
    for (car* current = head; current; current = current->next) {
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
      if (current->speed <= 0) {
        current->speed = rand() % MAX_SPEED;
        current->direction = rand() % 4;
      }
    }

    sleep(1);
  }
}

int main() {
  car* head = create_car();
  simulate_traffic(head);
  return 0;
}