//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Floor {
    int id;
    int numOfPassengers;
    int capacity;
};

struct Elevator {
    int floor;
    struct Floor* floors;
    int numOfFloors;
    int currentFloor;
    int maxPassengers;
};

struct Elevator elevator;

void initialize_elevator(int numOfFloors, int maxPassengers) {
    elevator.numOfFloors = numOfFloors;
    elevator.maxPassengers = maxPassengers;
    elevator.currentFloor = 0;
    elevator.floors = (struct Floor*) malloc(numOfFloors * sizeof(struct Floor));
    for (int i = 0; i < numOfFloors; i++) {
        elevator.floors[i].id = i;
        elevator.floors[i].numOfPassengers = 0;
        elevator.floors[i].capacity = 10;
    }
}

void print_elevator_state() {
    printf("Current Floor: %d\n", elevator.currentFloor);
    printf("Passengers: ");
    for (int i = 0; i < elevator.numOfFloors; i++) {
        printf("%d ", elevator.floors[i].numOfPassengers);
    }
    printf("\n");
}

int move_elevator(int direction) {
    if (direction == 1) {
        if (elevator.currentFloor == elevator.numOfFloors - 1) {
            return 0;
        } else {
            elevator.currentFloor++;
            return 1;
        }
    } else if (direction == 2) {
        if (elevator.currentFloor == 0) {
            return 0;
        } else {
            elevator.currentFloor--;
            return 1;
        }
    }
    return 0;
}

void update_passengers() {
    for (int i = 0; i < elevator.numOfFloors; i++) {
        if (elevator.floors[i].numOfPassengers < elevator.floors[i].capacity) {
            elevator.floors[i].numOfPassengers++;
        } else {
            elevator.floors[i].numOfPassengers = 0;
        }
    }
}

int main() {
    srand(time(NULL));
    int numOfFloors = 10;
    int maxPassengers = 20;
    initialize_elevator(numOfFloors, maxPassengers);
    print_elevator_state();
    int direction = 0;
    while (1) {
        direction = rand() % 2 + 1;
        if (direction == 1) {
            move_elevator(1);
            update_passengers();
        } else if (direction == 2) {
            move_elevator(2);
            update_passengers();
        }
        print_elevator_state();
    }
    return 0;
}