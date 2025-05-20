//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEVATOR_FLOOR 10
#define MAX_ELEVATOR_PASSENGER 5

typedef struct Elevator {
  int currentFloor;
  int passengers;
  int direction;
  struct Elevator *next;
} Elevator;

void moveElevator(Elevator *elevator) {
  int targetFloor = elevator->currentFloor + elevator->direction;

  if (targetFloor >= 0 && targetFloor < MAX_ELEVATOR_FLOOR) {
    elevator->currentFloor = targetFloor;
  } else {
    elevator->direction = -elevator->direction;
  }
}

void addPassenger(Elevator *elevator, int numPassengers) {
  elevator->passengers += numPassengers;
  if (elevator->passengers > MAX_ELEVATOR_PASSENGER) {
    elevator->passengers = MAX_ELEVATOR_PASSENGER;
  }
}

void removePassenger(Elevator *elevator, int numPassengers) {
  elevator->passengers -= numPassengers;
  if (elevator->passengers < 0) {
    elevator->passengers = 0;
  }
}

int main() {
  time_t t;
  srand(time(&t));

  Elevator *elevator = malloc(sizeof(Elevator));
  elevator->currentFloor = rand() % MAX_ELEVATOR_FLOOR;
  elevator->passengers = rand() % MAX_ELEVATOR_PASSENGER;
  elevator->direction = rand() % 2;

  moveElevator(elevator);
  addPassenger(elevator, rand() % MAX_ELEVATOR_PASSENGER);
  removePassenger(elevator, rand() % MAX_ELEVATOR_PASSENGER);

  moveElevator(elevator);

  free(elevator);

  return 0;
}