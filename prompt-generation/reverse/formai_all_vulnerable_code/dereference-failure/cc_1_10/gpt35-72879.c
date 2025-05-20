//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ELEVATORS 4
#define MAX_FLOORS 10

struct Elevator {
    int currentFloor;
    int numPassengers;
    int maxPassengers;
    bool isGoingUp;
    bool isIdle;
};

void initElevators(struct Elevator elevators[], int numElevators) {
    for (int i = 0; i < numElevators; i++) {
        elevators[i].currentFloor = 1;
        elevators[i].numPassengers = 0;
        elevators[i].maxPassengers = 10;
        elevators[i].isGoingUp = true;
        elevators[i].isIdle = true;
    }
}

void moveElevator(struct Elevator *elevator) {
    if (elevator->isIdle) {
        return;
    }
    if (elevator->isGoingUp) {
        elevator->currentFloor++;
    } else {
        elevator->currentFloor--;
    }
    if (elevator->currentFloor == MAX_FLOORS || elevator->currentFloor == 1) {
        elevator->isGoingUp = !elevator->isGoingUp;
    }
}

void printElevator(struct Elevator *elevator) {
    printf("Current floor: %d\n", elevator->currentFloor);
    printf("Number of passengers: %d/%d\n", elevator->numPassengers, elevator->maxPassengers);
    printf("Direction: %s\n", elevator->isGoingUp ? "Up" : "Down");
}

void printAllElevators(struct Elevator elevators[], int numElevators) {
    for (int i = 0; i < numElevators; i++) {
        printf("Elevator %d:\n", i + 1);
        printElevator(&elevators[i]);
    }
}

void callElevator(struct Elevator elevators[], int numElevators, int floor) {
    int bestElevatorIndex = -1;
    int minDistance = MAX_FLOORS + 1;
    for (int i = 0; i < numElevators; i++) {
        int distance = abs(elevators[i].currentFloor - floor);
        if (elevators[i].isIdle && distance < minDistance) {
            bestElevatorIndex = i;
            minDistance = distance;
        }
    }
    if (bestElevatorIndex == -1) {
        printf("No elevators available at the moment. Please try again later.\n");
        return;
    }
    printf("Elevator %d has been called to floor %d.\n", bestElevatorIndex + 1, floor);
    elevators[bestElevatorIndex].isIdle = false;
}

void boardElevator(struct Elevator *elevator, int numPassengers) {
    if (elevator->numPassengers + numPassengers > elevator->maxPassengers) {
        printf("Elevator is at capacity. Please wait for another elevator.\n");
        return;
    }
    elevator->numPassengers += numPassengers;
    printf("%d passengers have boarded the elevator. There are now %d passengers on the elevator.\n", numPassengers, elevator->numPassengers);
}

void exitElevator(struct Elevator *elevator, int numPassengers) {
    if (elevator->numPassengers < numPassengers) {
        printf("There aren't that many passengers on the elevator to exit. Please try again.\n");
        return;
    }
    elevator->numPassengers -= numPassengers;
    printf("%d passengers have exited the elevator. There are now %d passengers on the elevator.\n", numPassengers, elevator->numPassengers);
}

int main() {
    struct Elevator elevators[MAX_ELEVATORS];
    initElevators(elevators, MAX_ELEVATORS);
    printf("Welcome to the elevator simulator!\n");
    while (true) {
        printAllElevators(elevators, MAX_ELEVATORS);
        printf("What would you like to do?\n");
        printf("1. Call elevator\n");
        printf("2. Board elevator\n");
        printf("3. Exit elevator\n");
        printf("4. Quit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("Which floor would you like to call the elevator to?\n");
                int floor;
                scanf("%d", &floor);
                callElevator(elevators, MAX_ELEVATORS, floor);
                break;
            }
            case 2: {
                printf("Which elevator would you like to board?\n");
                int elevatorIndex;
                scanf("%d", &elevatorIndex);
                elevatorIndex--;
                printf("How many passengers are boarding the elevator?\n");
                int numPassengers;
                scanf("%d", &numPassengers);
                boardElevator(&elevators[elevatorIndex], numPassengers);
                break;
            }
            case 3: {
                printf("Which elevator would you like to exit?\n");
                int elevatorIndex;
                scanf("%d", &elevatorIndex);
                elevatorIndex--;
                printf("How many passengers are exiting the elevator?\n");
                int numPassengers;
                scanf("%d", &numPassengers);
                exitElevator(&elevators[elevatorIndex], numPassengers);
                break;
            }
            case 4:
                printf("Thank you for using the elevator simulator!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        for (int i = 0; i < MAX_ELEVATORS; i++) {
            moveElevator(&elevators[i]);
        }
    }
}