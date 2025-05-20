//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Define the elevator structure
typedef struct Elevator {
    int currentFloor;
    int targetFloor;
    int passengers;
    struct Elevator *next;
} Elevator;

// Function to create an elevator
Elevator *createElevator(int currentFloor, int targetFloor, int passengers) {
    Elevator *elevator = (Elevator *)malloc(sizeof(Elevator));
    elevator->currentFloor = currentFloor;
    elevator->targetFloor = targetFloor;
    elevator->passengers = passengers;
    elevator->next = NULL;
    return elevator;
}

// Function to move the elevator to a target floor
void moveElevator(Elevator *elevator, int targetFloor) {
    // Calculate the direction of travel
    int direction = targetFloor - elevator->currentFloor;

    // Move the elevator one floor at a time
    for (int i = 0; i < direction; i++) {
        elevator->currentFloor++;
        printf("Elevator moving to floor %d...\n", elevator->currentFloor);
    }

    // Reach the target floor
    elevator->currentFloor = targetFloor;
}

// Main function
int main() {
    // Create a linked list of elevators
    Elevator *head = createElevator(1, 5, 2);
    Elevator *second = createElevator(3, 7, 4);
    Elevator *third = createElevator(5, 9, 6);

    // Link the elevators together
    head->next = second;
    second->next = third;

    // Move the elevators to their target floors
    moveElevator(head, 7);
    moveElevator(second, 9);
    moveElevator(third, 1);

    // Print the final positions of the elevators
    printf("Final positions:\n");
    printf("Elevator 1: Floor %d\n", head->currentFloor);
    printf("Elevator 2: Floor %d\n", second->currentFloor);
    printf("Elevator 3: Floor %d\n", third->currentFloor);

    return 0;
}