//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: optimized
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5

typedef struct Passenger {
  int floor;
  struct Passenger* next;
} Passenger;

typedef struct Elevator {
  int currentFloor;
  Passenger* passengers;
  int direction;
  int destinationFloor;
  struct Elevator* next;
} Elevator;

Elevator* createElevator(int floors) {
  Elevator* elevator = malloc(sizeof(Elevator));
  elevator->currentFloor = 1;
  elevator->passengers = NULL;
  elevator->direction = 0;
  elevator->destinationFloor = floors;
  elevator->next = NULL;

  return elevator;
}

void addPassenger(Elevator* elevator, int floor) {
  Passenger* passenger = malloc(sizeof(Passenger));
  passenger->floor = floor;
  passenger->next = NULL;

  if (elevator->passengers == NULL) {
    elevator->passengers = passenger;
  } else {
    passenger->next = elevator->passengers;
    elevator->passengers = passenger;
  }
}

void moveElevator(Elevator* elevator) {
  int targetFloor = elevator->destinationFloor;
  int currentFloor = elevator->currentFloor;

  if (elevator->direction == 0) { // Upward
    if (currentFloor < targetFloor) {
      elevator->currentFloor++;
    } else {
      elevator->currentFloor = targetFloor;
      elevator->direction = 1; // Downward
      elevator->destinationFloor = currentFloor;
    }
  } else { // Downward
    if (currentFloor > targetFloor) {
      elevator->currentFloor--;
    } else {
      elevator->currentFloor = targetFloor;
      elevator->direction = 0; // Upward
      elevator->destinationFloor = currentFloor;
    }
  }
}

int main() {
  Elevator* elevator = createElevator(MAX_FLOORS);
  addPassenger(elevator, 3);
  addPassenger(elevator, 5);
  addPassenger(elevator, 7);
  addPassenger(elevator, 2);

  moveElevator(elevator);

  return 0;
}