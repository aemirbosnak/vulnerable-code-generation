//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PESS_PER_FLOOR 5

typedef struct Passenger {
    char name[20];
    int floor;
    struct Passenger* next;
} Passenger;

void addPassenger(Passenger** head, char name, int floor) {
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
    time_t t = time(NULL);
    int currentFloor = 1;
    int destinationFloor;

    while (head) {
        destinationFloor = head->floor;

        if (currentFloor != destinationFloor) {
            currentFloor++;

            if (currentFloor > destinationFloor) {
                currentFloor--;
            }

            printf("The elevator is moving to floor %d.\n", currentFloor);

            sleep(1);
        } else {
            printf("Passenger %s has reached their destination floor.\n", head->name);

            free(head);
            head = NULL;
        }
    }

    printf("The elevator has reached the top floor.\n");

    t = time(NULL) - t;
    printf("Time taken: %d seconds.\n", t);
}

int main() {
    Passenger* head = NULL;

    addPassenger(&head, "John Doe", 5);
    addPassenger(&head, "Jane Doe", 3);
    addPassenger(&head, "Peter Pan", 8);
    addPassenger(&head, "Mary Poppins", 2);
    addPassenger(&head, "The Cat in the Hat", 6);

    simulateElevator(head);

    return 0;
}