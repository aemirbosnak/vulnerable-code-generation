//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: future-proof
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
  int targetFloor;
  Passenger* passengers;
  struct Elevator* next;
} Elevator;

void simulateElevator(Elevator* elevator) {
  // Calculate time to reach target floor
  int time = abs(elevator->targetFloor - elevator->currentFloor) * 2;

  // Elevator moves to target floor
  elevator->currentFloor = elevator->targetFloor;

  // Passengers get off at their floors
  Passenger* passenger = elevator->passengers;
  while (passenger) {
    if (passenger->floor == elevator->currentFloor) {
      printf("%s has exited the elevator on floor %d.\n", passenger->name, elevator->currentFloor);
      passenger = passenger->next;
    } else {
      passenger = passenger->next;
    }
  }

  // Passengers get on at their floors
  passenger = elevator->passengers;
  while (passenger) {
    if (passenger->floor == elevator->currentFloor) {
      printf("%s has entered the elevator on floor %d.\n", passenger->name, elevator->currentFloor);
      passenger = passenger->next;
    } else {
      passenger = passenger->next;
    }
  }
}

int main() {
  // Create a list of passengers
  Passenger* passengers = NULL;
  passengers = malloc(sizeof(Passenger) * MAX_PASSENGERS);
  for (int i = 0; i < MAX_PASSENGERS; i++) {
    passengers[i].name[0] = '\0';
    passengers[i].floor = 0;
  }

  // Create an elevator
  Elevator* elevator = NULL;
  elevator = malloc(sizeof(Elevator));
  elevator->currentFloor = 1;
  elevator->targetFloor = 5;
  elevator->passengers = passengers;
  elevator->next = NULL;

  // Simulate the elevator
  simulateElevator(elevator);

  return 0;
}