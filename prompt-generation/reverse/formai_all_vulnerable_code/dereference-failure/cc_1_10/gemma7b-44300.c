//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: genius
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
  struct Elevator* next;
} Elevator;

void simulateElevator(Elevator* elevator) {
  // Randomly choose a destination floor
  int destinationFloor = rand() % MAX_FLOORS;

  // If the elevator is not already on the destination floor, move it there
  if (elevator->currentFloor != destinationFloor) {
    // Calculate the direction of travel
    int direction = destinationFloor - elevator->currentFloor;

    // Move the elevator in the direction of travel
    for (int i = 0; i < direction; i++) {
      elevator->currentFloor++;
      sleep(1);
    }
  }

  // Add the passenger to the elevator
  Passenger* passenger = malloc(sizeof(Passenger));
  passenger->floor = destinationFloor;
  passenger->next = elevator->passengers;
  elevator->passengers = passenger;
}

int main() {
  // Create a list of elevators
  Elevator* elevators = NULL;

  // Simulate a number of passengers
  for (int i = 0; i < MAX_PASSENGERS; i++) {
    simulateElevator(elevators);
  }

  return 0;
}