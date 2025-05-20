//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define the elevator structure
typedef struct Elevator {
    int currentFloor;
    int targetFloor;
    int passengers;
    struct Elevator *next;
} Elevator;

// Function to create a new elevator
Elevator *createElevator() {
    Elevator *elevator = (Elevator *)malloc(sizeof(Elevator));
    elevator->currentFloor = 1;
    elevator->targetFloor = 0;
    elevator->passengers = 0;
    elevator->next = NULL;
    return elevator;
}

// Function to move the elevator to a target floor
void moveElevator(Elevator *elevator, int targetFloor) {
    if (elevator->currentFloor != targetFloor) {
        int direction = targetFloor - elevator->currentFloor;
        elevator->currentFloor += direction;
    }
}

// Function to add a passenger to the elevator
void addPassenger(Elevator *elevator) {
    elevator->passengers++;
}

// Function to remove a passenger from the elevator
void removePassenger(Elevator *elevator) {
    elevator->passengers--;
}

// Main function
int main() {
    // Create a linked list of elevators
    Elevator *head = createElevator();

    // Add passengers to the elevator
    addPassenger(head);
    addPassenger(head);
    addPassenger(head);

    // Move the elevator to a target floor
    moveElevator(head, 5);

    // Remove passengers from the elevator
    removePassenger(head);
    removePassenger(head);

    // Print the current floor of the elevator
    printf("Current floor: %d", head->currentFloor);

    return 0;
}