//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define the elevator structure
typedef struct Elevator {
  int currentFloor;
  int targetFloor;
  int direction;
  int passengers;
  struct Elevator *next;
} Elevator;

// Create a linked list of elevators
Elevator *head = NULL;

// Function to add an elevator to the linked list
void addElevator(int currentFloor, int targetFloor, int direction, int passengers) {
  Elevator *newElevator = (Elevator *)malloc(sizeof(Elevator));
  newElevator->currentFloor = currentFloor;
  newElevator->targetFloor = targetFloor;
  newElevator->direction = direction;
  newElevator->passengers = passengers;
  newElevator->next = NULL;

  if (head == NULL) {
    head = newElevator;
  } else {
    Elevator *lastElevator = head;
    while (lastElevator->next) {
      lastElevator = lastElevator->next;
    }
    lastElevator->next = newElevator;
  }
}

// Function to simulate the elevator movement
void simulateElevator() {
  Elevator *currentElevator = head;
  while (currentElevator) {
    // Move the elevator towards its target floor
    if (currentElevator->direction == 0) {
      currentElevator->currentFloor++;
    } else if (currentElevator->direction == 1) {
      currentElevator->currentFloor--;
    }

    // Check if the elevator has reached its target floor
    if (currentElevator->currentFloor == currentElevator->targetFloor) {
      // Open the elevator door
      printf("Door open on floor %d.\n", currentElevator->currentFloor);

      // Let the passengers out
      currentElevator->passengers = 0;

      // Close the elevator door
      printf("Door closed on floor %d.\n", currentElevator->currentFloor);

      // Reset the target floor
      currentElevator->targetFloor = -1;
    }

    currentElevator = currentElevator->next;
  }
}

int main() {
  // Add some elevators to the linked list
  addElevator(1, 5, 0, 2);
  addElevator(3, 7, 1, 4);
  addElevator(5, 3, 0, 1);
  addElevator(7, 1, 1, 3);

  // Simulate the elevator movement
  simulateElevator();

  return 0;
}