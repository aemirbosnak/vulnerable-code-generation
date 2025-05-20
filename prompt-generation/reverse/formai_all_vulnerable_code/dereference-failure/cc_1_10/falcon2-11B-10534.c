//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

typedef struct Elevator {
    int currentFloor;
    int maxCapacity;
    int numPeople;
    int numFloors;
} Elevator;

Elevator* createElevator(int capacity, int numFloors) {
    Elevator* e = malloc(sizeof(Elevator));
    e->currentFloor = 0;
    e->maxCapacity = capacity;
    e->numPeople = 0;
    e->numFloors = numFloors;
    return e;
}

void addPerson(Elevator* e) {
    if (e->numPeople < e->maxCapacity) {
        e->numPeople++;
    }
}

void removePerson(Elevator* e) {
    if (e->numPeople > 0) {
        e->numPeople--;
    }
}

void goUp(Elevator* e) {
    if (e->currentFloor < e->numFloors - 1) {
        e->currentFloor++;
    }
}

void goDown(Elevator* e) {
    if (e->currentFloor > 0) {
        e->currentFloor--;
    }
}

int main() {
    Elevator* e = createElevator(10, 5);
    addPerson(e);
    addPerson(e);
    addPerson(e);
    addPerson(e);
    addPerson(e);
    addPerson(e);
    addPerson(e);
    addPerson(e);
    addPerson(e);
    addPerson(e);
    addPerson(e);
    removePerson(e);
    removePerson(e);
    removePerson(e);
    removePerson(e);
    removePerson(e);
    removePerson(e);
    removePerson(e);
    goUp(e);
    goUp(e);
    goUp(e);
    goUp(e);
    goDown(e);
    goDown(e);
    goDown(e);
    goDown(e);
    goDown(e);
    goDown(e);
    goDown(e);
    goDown(e);
    goDown(e);
    goDown(e);
    goDown(e);
    printf("Elevator state: current floor = %d, num people = %d\n", e->currentFloor, e->numPeople);
    free(e);
    return 0;
}