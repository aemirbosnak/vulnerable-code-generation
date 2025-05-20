//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10
#define NUM_PASSENGERS 5

typedef struct Passenger {
    char name[20];
    int floor;
    struct Passenger* next;
} Passenger;

Passenger* createPassenger(char* name, int floor) {
    Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    newPassenger->floor = floor;
    newPassenger->next = NULL;
    return newPassenger;
}

void simulateElevator(Passenger* passengers) {
    int currentFloor = 1;
    time_t timerStart = time(NULL);

    while (passengers) {
        if (passengers->floor == currentFloor) {
            printf("%s has reached floor %d.\n", passengers->name, currentFloor);
            passengers = passengers->next;
        } else if (passengers->floor > currentFloor) {
            currentFloor++;
        } else {
            currentFloor--;
        }
    }

    time_t timerEnd = time(NULL);
    int timeTaken = timerEnd - timerStart;

    printf("Total time taken: %d seconds.\n", timeTaken);
}

int main() {
    Passenger* passengers = createPassenger("John", 5);
    passengers = createPassenger("Mary", 2);
    passengers = createPassenger("Bob", 7);
    passengers = createPassenger("Alice", 3);
    passengers = createPassenger("Tom", 4);

    simulateElevator(passengers);

    return 0;
}