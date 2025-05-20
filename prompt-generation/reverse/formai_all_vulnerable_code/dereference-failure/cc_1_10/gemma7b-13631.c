//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5

typedef struct Passenger {
  char name[20];
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
  int randomFloor = rand() % MAX_FLOORS;
  elevator->currentFloor = randomFloor;

  printf("Elevator bell rings at floor %d.\n", elevator->currentFloor);

  // Simulate passenger boarding and exiting
  for (int i = 0; i < MAX_PASSENGERS; i++) {
    int passengerFloor = rand() % MAX_FLOORS;
    if (passengerFloor != elevator->currentFloor) {
      Passenger* passenger = (Passenger*)malloc(sizeof(Passenger));
      strcpy(passenger->name, "Passenger " + i);
      passenger->floor = passengerFloor;
      passenger->next = elevator->passengers;
      elevator->passengers = passenger;
    }
  }

  // Simulate elevator moving to a floor
  for (int i = 0; i < MAX_FLOORS; i++) {
    if (elevator->passengers && elevator->passengers->floor == i) {
      elevator->currentFloor = i;
      printf("Elevator stops at floor %d.\n", elevator->currentFloor);
    }
  }

  // Free passengers
  Passenger* passenger = elevator->passengers;
  while (passenger) {
    Passenger* nextPassenger = passenger->next;
    free(passenger);
    passenger = nextPassenger;
  }

  // Update time
  t = time(NULL) - t;
  printf("Time spent on elevator: %d seconds.\n", t);
}

int main() {
  Elevator* elevator = (Elevator*)malloc(sizeof(Elevator));
  elevator->currentFloor = 0;
  elevator->passengers = NULL;
  elevator->next = NULL;

  simulateElevator(elevator);

  return 0;
}