//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: Linus Torvalds
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 5
#define MAX_PASSENGERS 10

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
  time_t t = time(NULL);
  int targetFloor = rand() % MAX_FLOORS;

  // Move the elevator to the target floor
  while (elevator->currentFloor != targetFloor) {
    int direction = targetFloor - elevator->currentFloor > 0 ? 1 : -1;
    elevator->currentFloor += direction;
    printf("Elevator moving to floor %d.\n", elevator->currentFloor);
    sleep(1);
  }

  // Load passengers
  Passenger* passenger = malloc(sizeof(Passenger));
  passenger->floor = targetFloor;
  passenger->next = elevator->passengers;
  elevator->passengers = passenger;

  // Simulate passenger departure
  sleep(rand() % 3);
  free(passenger);
  printf("Passenger departed from floor %d.\n", targetFloor);
}

int main() {
  Elevator* elevator = malloc(sizeof(Elevator));
  elevator->currentFloor = 1;
  elevator->passengers = NULL;
  elevator->next = NULL;

  simulateElevator(elevator);

  free(elevator);

  return 0;
}