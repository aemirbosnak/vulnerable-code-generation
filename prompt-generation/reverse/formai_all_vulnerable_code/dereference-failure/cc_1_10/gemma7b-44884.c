//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10

typedef struct Elevator {
  int currentFloor;
  int destinationFloor;
  int passengers;
  int direction;
  struct Elevator *next;
} Elevator;

void simulateElevator(Elevator *elevator) {
  time_t tStart = time(NULL);
  int timeSpent = 0;

  // Move the elevator to the destination floor
  while (elevator->currentFloor != elevator->destinationFloor) {
    int currentFloor = elevator->currentFloor;
    elevator->currentFloor += elevator->direction;
    timeSpent++;

    // Simulate floor arrival
    printf("Elevator at floor %d.\n", elevator->currentFloor);
    sleep(1);

    // Update the time spent
    timeSpent++;
  }

  // Door opens
  printf("Elevator door opens.\n");

  // Passengers get off and on
  elevator->passengers = rand() % MAX_FLOORS;

  // Door closes
  printf("Elevator door closes.\n");

  // Calculate the time spent
  timeSpent += time(NULL) - tStart;

  // Print the time spent
  printf("Time spent: %d seconds.\n", timeSpent);
}

int main() {
  // Create a linked list of elevators
  Elevator *head = NULL;
  head = malloc(sizeof(Elevator));
  head->currentFloor = 1;
  head->destinationFloor = 5;
  head->passengers = 3;
  head->direction = 1;
  head->next = NULL;

  // Simulate the elevator
  simulateElevator(head);

  return 0;
}