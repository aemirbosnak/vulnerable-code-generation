//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 5
#define MAX_PASSENGERS 10

typedef struct Passenger {
    char name[20];
    int floor;
    struct Passenger* next;
} Passenger;

typedef struct Elevator {
    int currentFloor;
    int targetFloor;
    Passenger* passengers;
    struct Elevator* next;
} Elevator;

void simulateElevator(Elevator* elevator) {
    time_t start_time = time(NULL);
    int time_elapsed = 0;

    while (time_elapsed < 3) {
        // Move the elevator to the target floor
        if (elevator->currentFloor != elevator->targetFloor) {
            int direction = elevator->targetFloor - elevator->currentFloor;
            elevator->currentFloor += direction;
            time_elapsed++;
        }

        // Serve passengers
        Passenger* passenger = elevator->passengers;
        while (passenger) {
            if (passenger->floor == elevator->currentFloor) {
                printf("%s has reached floor %d.\n", passenger->name, elevator->currentFloor);
                free(passenger);
                elevator->passengers = elevator->passengers->next;
            } else {
                passenger = passenger->next;
            }
        }

        // Sleep for a while
        time_elapsed++;
        sleep(1);
    }

    // Announce arrival at the destination floor
    printf("The elevator has arrived at floor %d.\n", elevator->targetFloor);
}

int main() {
    Elevator* elevator = malloc(sizeof(Elevator));
    elevator->currentFloor = 1;
    elevator->targetFloor = 3;
    elevator->passengers = NULL;

    simulateElevator(elevator);

    return 0;
}