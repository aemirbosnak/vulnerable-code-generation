//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOOR 10

typedef struct Elevator {
    int currentFloor;
    int targetFloor;
    int passengers;
    int direction;
    struct Elevator *next;
} Elevator;

void simulateElevator(Elevator *elevator) {
    // Calculate time to reach target floor
    int time = abs(elevator->targetFloor - elevator->currentFloor) * 2;
    // Sleep for the time
    sleep(time);

    // Move elevator to target floor
    elevator->currentFloor = elevator->targetFloor;

    // Drop off passengers
    elevator->passengers = 0;

    // Free the elevator
    free(elevator);
}

int main() {
    // Create a linked list of elevators
    Elevator *head = NULL;

    // Simulate a few elevators
    for (int i = 0; i < 5; i++) {
        Elevator *elevator = (Elevator *)malloc(sizeof(Elevator));
        elevator->currentFloor = rand() % MAX_FLOOR;
        elevator->targetFloor = rand() % MAX_FLOOR;
        elevator->passengers = rand() % 10;
        elevator->direction = rand() % 2;
        elevator->next = head;
        head = elevator;
    }

    // Simulate the elevators
    while (head) {
        simulateElevator(head);
        head = head->next;
    }

    return 0;
}