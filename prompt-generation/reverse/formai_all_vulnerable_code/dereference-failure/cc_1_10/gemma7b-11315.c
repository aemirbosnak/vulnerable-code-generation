//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define NUM_FLOORS 5

typedef struct Elevator {
  int currentFloor;
  int targetFloor;
  int passengers;
  int direction;
  struct Elevator *next;
} Elevator;

Elevator *createElevator(int floor, int passengers) {
  Elevator *elevate = malloc(sizeof(Elevator));
  elevate->currentFloor = floor;
  elevate->targetFloor = floor;
  elevate->passengers = passengers;
  elevate->direction = 0;
  elevate->next = NULL;

  return elevate;
}

void moveElevator(Elevator *elevate) {
  int targetFloor = elevate->targetFloor;
  int currentFloor = elevate->currentFloor;

  if (currentFloor < targetFloor) {
    elevate->direction = 1;
  } else if (currentFloor > targetFloor) {
    elevate->direction = -1;
  }

  currentFloor += elevate->direction;
  elevate->currentFloor = currentFloor;

  if (currentFloor == targetFloor) {
    elevate->passengers = 0;
  }
}

int main() {
  Elevator *head = createElevator(1, 5);
  moveElevator(head);

  printf("Current floor: %d\n", head->currentFloor);
  printf("Target floor: %d\n", head->targetFloor);
  printf("Passengers: %d\n", head->passengers);

  return 0;
}