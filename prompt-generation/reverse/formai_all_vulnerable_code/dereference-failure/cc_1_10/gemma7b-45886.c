//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: Linus Torvalds
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_FLOORS 10
#define MAX_PASSENGERS 5

typedef struct Passenger {
    char name[20];
    int floor;
    struct Passenger* next;
} Passenger;

void addPassenger(Passenger** head, char* name, int floor) {
    Passenger* newPassenger = malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    newPassenger->floor = floor;
    newPassenger->next = NULL;

    if (*head == NULL) {
        *head = newPassenger;
    } else {
        (*head)->next = newPassenger;
    }
}

void simulateElevator(Passenger** head) {
    time_t start = time(NULL);
    int currentFloor = 1;
    int destinationFloor;

    while (time(NULL) - start < 5) {
        printf("Current floor: %d\n", currentFloor);

        // Get the destination floor from the passenger
        destinationFloor = rand() % NUM_FLOORS + 1;

        // Move the elevator to the destination floor
        while (currentFloor != destinationFloor) {
            currentFloor++;
            printf("Moving to floor %d... \n", currentFloor);
            sleep(1);
        }

        // Serve the passenger
        printf("Serving passenger %s on floor %d\n", (*head)->name, currentFloor);

        // Remove the passenger from the elevator
        *head = (*head)->next;

        // Sleep for a while
        sleep(rand() % 2);
    }

    printf("Elevator doors open.\n");
}

int main() {
    Passenger** head = NULL;

    // Add some passengers to the elevator
    addPassenger(&head, "John Doe", 3);
    addPassenger(&head, "Jane Doe", 5);
    addPassenger(&head, "Bob Smith", 2);
    addPassenger(&head, "Alice White", 4);

    // Simulate the elevator
    simulateElevator(head);

    return 0;
}