//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of floors
#define MAX_FLOORS 20

// Define the elevator floor structure
typedef struct Floor {
    int number;
    struct Floor *next;
} Floor;

// Define the elevator structure
typedef struct Elevator {
    int currentFloor;
    struct Floor *floors;
    struct Elevator *next;
} Elevator;

// Function to create a new floor
Floor *createFloor(int number) {
    Floor *newFloor = (Floor *)malloc(sizeof(Floor));
    newFloor->number = number;
    newFloor->next = NULL;

    return newFloor;
}

// Function to add a new floor to the elevator
void addFloor(Elevator *elevator, int number) {
    Floor *newFloor = createFloor(number);

    if (elevator->floors == NULL) {
        elevator->floors = newFloor;
    } else {
        elevator->floors->next = newFloor;
        elevator->floors = newFloor;
    }
}

// Function to move the elevator to a new floor
void moveElevator(Elevator *elevator, int targetFloor) {
    int currentFloor = elevator->currentFloor;

    // Check if the target floor is within the bounds
    if (targetFloor < 0 || targetFloor >= MAX_FLOORS) {
        return;
    }

    // Calculate the direction of travel
    int direction = targetFloor - currentFloor;

    // Move the elevator in the direction of travel
    while (currentFloor != targetFloor) {
        currentFloor += direction;

        // Print the current floor
        printf("Current floor: %d\n", currentFloor);

        // Sleep for 1 second
        sleep(1);
    }

    // Set the current floor to the target floor
    elevator->currentFloor = targetFloor;
}

int main() {
    // Create a new elevator
    Elevator *elevator = (Elevator *)malloc(sizeof(Elevator));
    elevator->currentFloor = 0;
    elevator->floors = NULL;
    elevator->next = NULL;

    // Add some floors to the elevator
    addFloor(elevator, 10);
    addFloor(elevator, 15);
    addFloor(elevator, 20);

    // Move the elevator to a new floor
    moveElevator(elevator, 12);

    return 0;
}