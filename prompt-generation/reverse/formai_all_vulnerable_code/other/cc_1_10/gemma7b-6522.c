//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define the number of floors
#define NUM_FLOORS 10

// Define the elevator capacity
#define CAPACITY 4

// Define the elevator current floor
int currentFloor = 1;

// Define the elevator direction
int direction = 0;

// Define the elevator passengers
int passengers = 0;

// Function to move the elevator up one floor
void moveUp() {
  currentFloor++;
  if (currentFloor > NUM_FLOORS) {
    currentFloor = NUM_FLOORS;
  }
}

// Function to move the elevator down one floor
void moveDown() {
  currentFloor--;
  if (currentFloor < 1) {
    currentFloor = 1;
  }
}

// Function to add a passenger to the elevator
void addPassenger() {
  if (passengers < CAPACITY) {
    passengers++;
  }
}

// Function to remove a passenger from the elevator
void removePassenger() {
  if (passengers > 0) {
    passengers--;
  }
}

// Main loop
int main() {

  // Simulate the elevator movement
  while (1) {
    // Display the current floor
    printf("Current floor: %d\n", currentFloor);

    // Get the direction and floor number from the user
    int directionInput = getchar();
    int floorNumber = atoi(gets());

    // Move the elevator according to the input
    switch (directionInput) {
      case 'u':
        moveUp();
        break;
      case 'd':
        moveDown();
        break;
    }

    // Add or remove passengers according to the input
    switch (floorNumber) {
      case 1:
        addPassenger();
        break;
      case 2:
        removePassenger();
        break;
    }

    // Check if the elevator is at the desired floor
    if (currentFloor == floorNumber) {
      // Announce arrival at the desired floor
      printf("Arrived at floor %d!\n", floorNumber);

      // Pause for a while
      sleep(2);

      // Reset the direction and floor number
      direction = 0;
      floorNumber = 0;
    }
  }

  return 0;
}