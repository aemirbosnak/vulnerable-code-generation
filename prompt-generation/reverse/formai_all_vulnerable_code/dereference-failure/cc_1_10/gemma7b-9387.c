//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5

typedef struct Passenger {
    char name[20];
    int floor;
    struct Passenger* next;
} Passenger;

typedef struct Elevator {
    int currentFloor;
    int destinationFloor;
    Passenger* passengers;
    struct Elevator* next;
} Elevator;

void addPassenger(Elevator* elevator, Passenger* passenger) {
    passenger->next = elevator->passengers;
    elevator->passengers = passenger;
}

void moveElevator(Elevator* elevator) {
    int direction = 0;
    if (elevator->currentFloor < elevator->destinationFloor) {
        direction = 1;
    } else if (elevator->currentFloor > elevator->destinationFloor) {
        direction = -1;
    }

    elevator->currentFloor += direction;

    if (elevator->currentFloor == elevator->destinationFloor) {
        printf("Door opening.\n");
    }
}

int main() {
    time_t t;
    srand(time(&t));

    Elevator* elevator = (Elevator*)malloc(sizeof(Elevator));
    elevator->currentFloor = 1;
    elevator->destinationFloor = rand() % MAX_FLOORS + 1;
    elevator->passengers = NULL;

    Passenger* passenger = (Passenger*)malloc(sizeof(Passenger));
    passenger->name[0] = 'A';
    passenger->floor = rand() % MAX_FLOORS + 1;
    addPassenger(elevator, passenger);

    passenger = (Passenger*)malloc(sizeof(Passenger));
    passenger->name[0] = 'B';
    passenger->floor = rand() % MAX_FLOORS + 1;
    addPassenger(elevator, passenger);

    passenger = (Passenger*)malloc(sizeof(Passenger));
    passenger->name[0] = 'C';
    passenger->floor = rand() % MAX_FLOORS + 1;
    addPassenger(elevator, passenger);

    moveElevator(elevator);

    return 0;
}