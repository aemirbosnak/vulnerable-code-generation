//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10

typedef struct Elevator {
    int currentFloor;
    int targetFloor;
    int direction;
    int passengers;
    struct Elevator *next;
} Elevator;

void moveElevator(Elevator *elevator) {
    int floorsToGo = abs(elevator->targetFloor - elevator->currentFloor);
    for (int i = 0; i < floorsToGo; i++) {
        elevator->currentFloor++;
        if (elevator->direction == 0) {
            printf("Elevator moving up to floor %d.\n", elevator->currentFloor);
        } else {
            printf("Elevator moving down to floor %d.\n", elevator->currentFloor);
        }
    }
    elevator->currentFloor = elevator->targetFloor;
}

int main() {
    Elevator *head = NULL;
    Elevator *tail = NULL;

    // Create a few elevators
    for (int i = 0; i < 5; i++) {
        Elevator *newElevator = (Elevator *)malloc(sizeof(Elevator));
        newElevator->currentFloor = 1;
        newElevator->targetFloor = rand() % MAX_FLOORS;
        newElevator->direction = rand() % 2;
        newElevator->passengers = rand() % 10;

        if (head == NULL) {
            head = newElevator;
            tail = newElevator;
        } else {
            tail->next = newElevator;
            tail = newElevator;
        }
    }

    // Move each elevator
    for (Elevator *elevator = head; elevator; elevator = elevator->next) {
        moveElevator(elevator);
    }

    return 0;
}