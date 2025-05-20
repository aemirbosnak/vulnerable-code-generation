//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5

typedef struct Passenger {
    char name[20];
    int floor;
    struct Passenger* next;
} Passenger;

void addPassenger(Passenger** head, char* name, int floor) {
    Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    newPassenger->floor = floor;
    newPassenger->next = NULL;

    if (*head == NULL) {
        *head = newPassenger;
    } else {
        (*head)->next = newPassenger;
    }
}

void simulateElevator(Passenger* head) {
    int currentFloor = 1;
    int destinationFloor;

    while (head) {
        destinationFloor = head->floor;

        if (currentFloor < destinationFloor) {
            currentFloor++;
            printf("Elevator moving up to floor %d...\n", currentFloor);
        } else if (currentFloor > destinationFloor) {
            currentFloor--;
            printf("Elevator moving down to floor %d...\n", currentFloor);
        } else {
            printf("Passenger %s reached floor %d.\n", head->name, destinationFloor);
            head = head->next;
        }
    }

    printf("Elevator at floor %d.\n", currentFloor);
}

int main() {
    Passenger* head = NULL;

    addPassenger(&head, "John Doe", 5);
    addPassenger(&head, "Jane Doe", 3);
    addPassenger(&head, "Peter Pan", 8);
    addPassenger(&head, "Mary Poppins", 2);
    addPassenger(&head, "The Cat in the Hat", 4);

    simulateElevator(head);

    return 0;
}