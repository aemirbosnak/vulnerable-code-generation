//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: invasive
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 3
#define MAX_CARS 20

typedef struct Car {
  int lane;
  int speed;
  int position;
  struct Car* next;
} Car;

Car* createCar() {
  Car* car = malloc(sizeof(Car));
  car->lane = rand() % NUM_LANE;
  car->speed = rand() % 5 + 1;
  car->position = rand() % 1000;
  car->next = NULL;
  return car;
}

void moveCars(Car* head) {
  Car* current = head;
  while (current) {
    current->position += current->speed;
    if (current->position >= 1000) {
      current->position = 0;
    }
    current = current->next;
  }
}

void collide(Car* car1, Car* car2) {
  if (car1->lane == car2->lane && car1->position == car2->position) {
    printf("Crash!\n");
    exit(1);
  }
}

int main() {
  srand(time(NULL));

  Car* head = createCar();
  head->next = createCar();
  head->next->next = createCar();

  moveCars(head);

  collide(head, head->next);

  return 0;
}