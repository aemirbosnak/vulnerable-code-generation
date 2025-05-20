//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int numFloors, numElevators, elevatorSpeed; // variables for number of floors, elevators, and elevator speed
    printf("Welcome to the HILARIOUS Elevator Simulation!\n");
    printf("How many floors does your building have? ");
    scanf("%d", &numFloors);
    printf("How many elevators does your building have? ");
    scanf("%d", &numElevators);
    printf("How fast are your elevators (in floors per second)? ");
    scanf("%d", &elevatorSpeed);

    printf("\n\nLadies and gentlemen, please hold onto your hats as we begin the simulation!\n\n");

    int floors[numFloors]; // array for each floor of the building
    int elevatorFloors[numElevators]; // array for each elevator's current floor
    bool elevatorUp[numElevators]; // array for whether each elevator is going up or down
    bool elevatorOccupied[numElevators]; // array for whether each elevator is occupied or empty

    for (int i = 0; i < numElevators; i++) {
        elevatorFloors[i] = 0; // start each elevator on the ground floor
        elevatorUp[i] = true; // start each elevator going up
        elevatorOccupied[i] = false; // start each elevator empty
    }

    while (true) { // simulation loop
        printf("Current elevator status:\n");
        for (int i = 0; i < numElevators; i++) {
            printf("Elevator %d is currently on floor %d, is %s, and is %soccupied.\n", i+1, elevatorFloors[i]+1, elevatorUp[i] ? "going up" : "going down", elevatorOccupied[i] ? "" : "un");
        }
        printf("\nWhich floor are you on? (enter a number between 1 and %d, or 0 to exit) ", numFloors);
        int currentFloor;
        scanf("%d", &currentFloor);
        if (currentFloor == 0) { // exit if user enters 0
            printf("Thank you for riding the HILARIOUS Elevator Simulation!\n");
            return 0;
        }
        printf("Which direction are you going? (enter 'up' or 'down') ");
        char direction[10];
        scanf("%s", direction);
        bool goingUp = (*direction == 'u');

        // find the closest unoccupied elevator to the user's current floor
        int closestElevator = -1;
        int closestDistance = numFloors; // set initial value to maximum possible distance (from top floor to ground floor)
        for (int i = 0; i < numElevators; i++) {
            if (!elevatorOccupied[i]) {
                int distance = abs(elevatorFloors[i] - (currentFloor-1));
                if (distance < closestDistance) {
                    closestElevator = i;
                    closestDistance = distance;
                }
            }
        }

        if (closestElevator != -1) { // if there is an available elevator
            printf("The HILARIOUS Elevator Simulation recommends using elevator %d.\n", closestElevator+1);
            elevatorOccupied[closestElevator] = true; // occupy the elevator
            if (elevatorFloors[closestElevator] == currentFloor-1) { // if the elevator is already on the user's floor
                printf("The elevator is already here! Please step on board.\n");
            } else { // move the elevator to the user's floor
                printf("The elevator is on its way! Please be patient.\n");
                while (elevatorFloors[closestElevator] != currentFloor-1) {
                    elevatorFloors[closestElevator] += elevatorUp[closestElevator] ? 1 : -1; // move the elevator up or down
                    printf("Elevator %d is now on floor %d.\n", closestElevator+1, elevatorFloors[closestElevator]+1);
                }
                printf("The elevator has arrived! Please step on board.\n");
            }
            elevatorOccupied[closestElevator] = false; // empty the elevator
            printf("Which floor would you like to go to? (enter a number between 1 and %d) ", numFloors);
            int destinationFloor;
            scanf("%d", &destinationFloor);
            while (destinationFloor == currentFloor) { // prevent user choosing their current floor as destination
                printf("You're already on that floor! Please choose another. ");
                scanf("%d", &destinationFloor);
            }
            printf("Thank you! The HILARIOUS Elevator Simulation is now taking you to floor %d.\n", destinationFloor);
            elevatorOccupied[closestElevator] = true; // occupy the elevator again
            if (destinationFloor > currentFloor) {
                elevatorUp[closestElevator] = true;
            } else {
                elevatorUp[closestElevator] = false;
            }
            printf("The doors are closing...\n");
            while (elevatorFloors[closestElevator] != destinationFloor-1) { // move the elevator to the user's destination floor
                elevatorFloors[closestElevator] += elevatorUp[closestElevator] ? 1 : -1;
                printf("Elevator %d is now on floor %d.\n", closestElevator+1, elevatorFloors[closestElevator]+1);
            }
            printf("The doors are opening! You have arrived at floor %d.\n", destinationFloor);
            elevatorOccupied[closestElevator] = false; // empty the elevator again
        } else { // if there are no available elevators
            printf("Sorry, all our elevators are currently occupied! Please try again later.\n");
        }
    }

    return 0;
}