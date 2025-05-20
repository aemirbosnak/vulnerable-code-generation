//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: mind-bending
#include <stdlib.h>

#define FLOORS 5
#define BUTTONS 3

typedef struct Elevator {
  int currentFloor;
  int targetFloor;
  int passengers;
  struct Elevator *next;
} Elevator;

Elevator *head = NULL;

void addPassenger(int floor, int numPassengers) {
  Elevator *newElevator = malloc(sizeof(Elevator));
  newElevator->currentFloor = floor;
  newElevator->targetFloor = floor;
  newElevator->passengers = numPassengers;
  newElevator->next = NULL;

  if (head == NULL) {
    head = newElevator;
  } else {
    Elevator *prev = head;
    while (prev->next) {
      prev = prev->next;
    }
    prev->next = newElevator;
  }
}

void moveElevator() {
  if (head == NULL) {
    return;
  }

  Elevator *current = head;

  while (current->currentFloor != current->targetFloor) {
    current->currentFloor++;

    if (current->passengers > 0) {
      current->passengers--;
    }

    printf("Elevator on floor %d, with %d passengers.\n", current->currentFloor, current->passengers);

    sleep(1);
  }

  printf("Elevator has reached floor %d.\n", current->targetFloor);
}

int main() {
  addPassenger(1, 5);
  addPassenger(3, 2);
  addPassenger(4, 3);

  moveElevator();

  return 0;
}