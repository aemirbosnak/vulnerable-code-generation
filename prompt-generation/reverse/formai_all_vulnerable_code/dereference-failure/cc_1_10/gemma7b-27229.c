//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: ultraprecise
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
    Passenger* passengers;
    struct Elevator* next;
} Elevator;

void simulateElevator(Elevator* elevator) {
    time_t t;
    int destinationFloor;

    t = time(NULL);
    printf("Elevator door opens at floor %d.", elevator->currentFloor);
    sleep(t);

    printf("Please enter your destination floor:");
    scanf("%d", &destinationFloor);

    while (elevator->currentFloor != destinationFloor) {
        t = time(NULL);
        elevator->currentFloor++;
        printf("Elevator moving to floor %d.", elevator->currentFloor);
        sleep(t);
    }

    t = time(NULL);
    printf("Elevator door opens at floor %d.", destinationFloor);
    sleep(t);

    printf("Thank you for riding, %s.", elevator->passengers->name);
    free(elevator->passengers);
    elevator->passengers = NULL;
}

int main() {
    Elevator* elevator = (Elevator*)malloc(sizeof(Elevator));
    elevator->currentFloor = 1;
    elevator->passengers = NULL;

    simulateElevator(elevator);

    return 0;
}