//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLOOR_COUNT 20
#define ELEVATOR_CAPACITY 10

typedef struct {
    int floorNumber;
    int peopleCount;
} Floor;

typedef struct {
    int currentFloor;
    int direction; // 1 for up, -1 for down, 0 for idle
    int peopleCount;
    int *floorRequests;
} Elevator;

void initElevator(Elevator *elevator) {
    elevator->currentFloor = 0;
    elevator->direction = 0;
    elevator->peopleCount = 0;
    elevator->floorRequests = (int*)calloc(FLOOR_COUNT, sizeof(int));
}

void freeElevator(Elevator *elevator) {
    free(elevator->floorRequests);
}

void generateFloorRequests(int *floorRequests) {
    // simulate people arriving at random floors
    for (int i = 0; i < FLOOR_COUNT; i++) {
        double chance = (double)rand() / RAND_MAX;
        if (chance < 0.1) { // 10% chance of someone arriving at a floor
            floorRequests[i] += rand() % 5 + 1; // 1-5 people arrived at floor
        }
    }
}

void printFloorRequests(int *floorRequests) {
    printf("Floor requests:\n");
    for (int i = 0; i < FLOOR_COUNT; i++) {
        printf("%d: %d\n", i, floorRequests[i]);
    }
}

void updateElevator(Elevator *elevator) {
    // check if anyone wants to get off
    if (elevator->floorRequests[elevator->currentFloor] > 0) {
        int numPeople = elevator->floorRequests[elevator->currentFloor];
        elevator->floorRequests[elevator->currentFloor] = 0; // clear floor request
        printf("Elevator arrived at floor %d and %d people got off\n", elevator->currentFloor, numPeople);
        elevator->peopleCount -= numPeople;
    }
    
    // check if anyone wants to get on
    if (elevator->direction == 0) { // if elevator is idle, check all floors
        for (int i = 0; i < FLOOR_COUNT; i++) {
            if (elevator->floorRequests[i] > 0) {
                elevator->direction = i > elevator->currentFloor ? 1 : -1; // set direction
                break;
            }
        }
    } else { // otherwise, only check floors in the direction of travel
        int i = elevator->currentFloor + elevator->direction;
        while (i >= 0 && i < FLOOR_COUNT) {
            if (elevator->floorRequests[i] > 0) break; // found someone who wants to get on
            i += elevator->direction; // continue in direction of travel
        }
        if (i >= 0 && i < FLOOR_COUNT) { // someone wants to get on
            elevator->floorRequests[i] = 0; // clear floor request
            int numPeople = rand() % (ELEVATOR_CAPACITY - elevator->peopleCount) + 1; // 1 - remaining space people get on
            printf("Elevator picked up %d people on floor %d\n", numPeople, i);
            elevator->peopleCount += numPeople;
        } else { // no one wants to get on, elevator is idle
            printf("Elevator is now idle\n");
            elevator->direction = 0;
        }
    }
    
    // move to next floor
    elevator->currentFloor += elevator->direction;
    printf("Elevator is now on floor %d going %s\n", elevator->currentFloor, elevator->direction == 1 ? "up" : elevator->direction == -1 ? "down" : "nowhere");
}

int main() {
    srand(time(NULL)); // seed random number generator with current time
    
    Elevator elevator;
    initElevator(&elevator);
    printf("Elevator simulation started\n");
    
    for (int i = 0; i < 100; i++) { // simulate 100 iterations of elevator movement
        generateFloorRequests(elevator.floorRequests);
        printFloorRequests(elevator.floorRequests);
        updateElevator(&elevator);
    }
    
    freeElevator(&elevator);
    
    return 0;
}