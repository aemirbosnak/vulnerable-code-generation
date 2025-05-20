//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 5

typedef struct {
    int floor;
    int capacity;
    int currentPassengers;
} Elevator;

typedef struct {
    int requestedFloor;
    int direction;
} Call;

Elevator* createElevator(int startFloor) {
    Elevator *elevator = (Elevator*)malloc(sizeof(Elevator));
    elevator->floor = startFloor;
    elevator->capacity = MAX_CAPACITY;
    elevator->currentPassengers = 0;
    return elevator;
}

void requestElevator(Call *call, int requestedFloor) {
    call->requestedFloor = requestedFloor;
    call->direction = (requestedFloor > call->requestedFloor) ? 1 : -1;
}

void boardPassengers(Elevator *elevator, int numPassengers) {
    if (elevator->currentPassengers + numPassengers <= elevator->capacity) {
        elevator->currentPassengers += numPassengers;
        printf("Boarded %d passengers. Current passengers: %d\n", numPassengers, elevator->currentPassengers);
    } else {
        printf("Cannot board %d passengers. Elevator is at full capacity!\n", numPassengers);
    }
}

void unloadPassengers(Elevator *elevator, int numPassengers) {
    if (elevator->currentPassengers >= numPassengers) {
        elevator->currentPassengers -= numPassengers;
        printf("Unloaded %d passengers. Current passengers: %d\n", numPassengers, elevator->currentPassengers);
    } else {
        printf("Cannot unload %d passengers. Current passengers: %d\n", numPassengers);
    }
}

void moveElevator(Elevator *elevator, int destinationFloor) {
    while (elevator->floor != destinationFloor) {
        elevator->floor += (elevator->floor < destinationFloor) ? 1 : -1;
        printf("Elevator moving to floor %d...\n", elevator->floor);
        sleep(1);
    }
    printf("Elevator has arrived at floor %d\n", elevator->floor);
}

void runElevator(Elevator *elevator, Call *call) {
    moveElevator(elevator, call->requestedFloor);
    unloadPassengers(elevator, (rand() % (elevator->currentPassengers + 1)));
    boardPassengers(elevator, (rand() % (MAX_CAPACITY - elevator->currentPassengers + 1)));
}

int main() {
    srand(time(0));
    Elevator *elevator = createElevator(1);
    Call call;

    printf("Welcome to the Elevator Simulation!\n");

    while (1) {
        int requestedFloor;
        printf("Enter the floor number you want to go to (1 to %d, or 0 to exit): ", MAX_FLOORS);
        scanf("%d", &requestedFloor);

        if (requestedFloor == 0) {
            printf("Exiting simulation...\n");
            break;
        } else if (requestedFloor < 1 || requestedFloor > MAX_FLOORS) {
            printf("Invalid floor! Please choose a floor between 1 and %d.\n", MAX_FLOORS);
            continue;
        }

        requestElevator(&call, requestedFloor);
        runElevator(elevator, &call);
    }

    free(elevator);
    return 0;
}