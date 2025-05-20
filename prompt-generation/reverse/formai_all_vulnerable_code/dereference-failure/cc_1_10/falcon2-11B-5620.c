//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int floor;
    int people;
} Passenger;

typedef struct {
    int floor;
    int maxPeople;
    int currentPeople;
    int capacity;
} Elevator;

int main() {
    Elevator* elevators = malloc(100 * sizeof(Elevator));
    Passenger* passengers = malloc(100 * sizeof(Passenger));

    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        elevators[i].floor = rand() % 20 + 1;
        elevators[i].maxPeople = rand() % 10 + 1;
        elevators[i].currentPeople = 0;
        elevators[i].capacity = rand() % 10 + 1;
    }

    for (int i = 0; i < 100; i++) {
        passengers[i].floor = rand() % 20 + 1;
        passengers[i].people = rand() % 10 + 1;
    }

    for (int i = 0; i < 100; i++) {
        int passenger = rand() % 100;
        elevators[passenger].currentPeople++;
        passengers[passenger].people--;
    }

    for (int i = 0; i < 100; i++) {
        if (passengers[i].people == 0) {
            int elevator = rand() % 100;
            elevators[elevator].currentPeople--;
            passengers[i].people++;
        }
    }

    for (int i = 0; i < 100; i++) {
        printf("Elevator %d: floor %d, current people %d, capacity %d\n", i, elevators[i].floor, elevators[i].currentPeople, elevators[i].capacity);
        printf("Passenger %d: floor %d, people %d\n", i, passengers[i].floor, passengers[i].people);
    }

    return 0;
}