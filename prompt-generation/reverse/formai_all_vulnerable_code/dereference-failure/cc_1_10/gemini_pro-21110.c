//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct car_t {
  int x, y;
  int speed;
  struct car_t *next;
} car_t;

car_t *head = NULL;

void create_car() {
  car_t *new_car = malloc(sizeof(car_t));
  new_car->x = rand() % 100;
  new_car->y = rand() % 100;
  new_car->speed = rand() % 10 + 1;
  new_car->next = head;
  head = new_car;
}

void move_cars() {
  car_t *curr = head;
  while (curr != NULL) {
    curr->x += curr->speed;
    curr->y += curr->speed;
    curr = curr->next;
  }
}

void draw_cars() {
  car_t *curr = head;
  while (curr != NULL) {
    printf("Car at (%d, %d)\n", curr->x, curr->y);
    curr = curr->next;
  }
}

int main() {
  srand(time(NULL));

  for (int i = 0; i < 10; i++) {
    create_car();
  }

  while (1) {
    move_cars();
    draw_cars();
  }

  return 0;
}