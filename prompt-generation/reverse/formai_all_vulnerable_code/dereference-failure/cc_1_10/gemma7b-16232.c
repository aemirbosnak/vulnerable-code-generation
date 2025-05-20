//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define NUM_FLOORS 10

typedef struct Elevator {
  int currentFloor;
  int destinationFloor;
  int passengers;
  struct Elevator *next;
} Elevator;

void simulateElevator(Elevator *elevators) {
  while (!elevators) {
    return;
  }

  int currentFloor = elevators->currentFloor;
  int destinationFloor = elevators->destinationFloor;
  int passengers = elevators->passengers;

  printf("Current floor: %d, Destination floor: %d, Passengers: %d\n", currentFloor, destinationFloor, passengers);

  // Move the elevator to the destination floor
  if (currentFloor < destinationFloor) {
    currentFloor++;
  } else if (currentFloor > destinationFloor) {
    currentFloor--;
  }

  // Drop off passengers if the destination floor is reached
  if (currentFloor == destinationFloor) {
    passengers--;
  }

  // Update the elevator's state
  elevators->currentFloor = currentFloor;
  elevators->passengers = passengers;

  // Simulate the next elevator event
  simulateElevator(elevators->next);
}

int main() {
  Elevator *elevators = NULL;

  // Create a few elevators
  for (int i = 0; i < 10; i++) {
    elevators = malloc(sizeof(Elevator));
    elevators->currentFloor = i;
    elevators->destinationFloor = rand() % NUM_FLOORS;
    elevators->passengers = rand() % 10;
    elevators->next = elevators;
  }

  // Simulate the elevators
  simulateElevator(elevators);

  return 0;
}