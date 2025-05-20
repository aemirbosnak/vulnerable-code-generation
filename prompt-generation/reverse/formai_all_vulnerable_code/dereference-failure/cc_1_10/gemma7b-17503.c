//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLOOR 10

typedef struct Passenger {
    char name[20];
    int floor;
    struct Passenger* next;
} Passenger;

Passenger* insertPassenger(Passenger* head, char* name, int floor) {
    Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    newPassenger->floor = floor;
    newPassenger->next = NULL;

    if (head == NULL) {
        head = newPassenger;
    } else {
        head->next = newPassenger;
    }

    return head;
}

void simulateElevator(Passenger* head) {
    int currentFloor = 1;
    int targetFloor;

    printf("Current floor: %d\n", currentFloor);

    while (head) {
        targetFloor = head->floor;

        if (targetFloor > currentFloor) {
            printf("Going up to floor %d...\n", targetFloor);
            currentFloor++;
        } else if (targetFloor < currentFloor) {
            printf("Going down to floor %d...\n", targetFloor);
            currentFloor--;
        } else {
            printf("Reaching floor %d.\n", targetFloor);
            head = head->next;
        }
    }

    printf("Reached the top floor. Thank you for riding!\n");
}

int main() {
    Passenger* head = NULL;

    insertPassenger(head, "John Doe", 5);
    insertPassenger(head, "Jane Doe", 3);
    insertPassenger(head, "Peter Pan", 8);

    simulateElevator(head);

    return 0;
}