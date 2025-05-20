//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    // Initializing variables
    int floors, passengers, capacity;
    printf("Welcome to the Happy Elevator Simulation!\n\n");
    printf("Please enter the number of floors in the building: ");
    scanf("%d", &floors);
    printf("Please enter the number of passengers the elevator can hold: ");
    scanf("%d", &capacity);

    //Creating an array for floors and their passenger requests
    int floorRequests[floors];
    for(int i = 0; i < floors; i++){
        floorRequests[i] = rand() % 10; //Maximum number of passengers going at once is 10
    }

    //Initializing the elevator
    int currentFloor = 1; //Starting on the first floor
    int passengersOnboard = 0; //Starting with no passengers
    printf("\nElevator initialized!\n\n");

    //Elevator Simulation loop
    for(int i = 0; i < floors; i++){
        printf("Elevator arrives at floor %d.\n", currentFloor);
        if(passengersOnboard == 0){ //If the elevator is empty
            if(floorRequests[currentFloor-1] == 0){ //If there are no passengers waiting on the current floor
                printf("The elevator is empty and there are no passengers on floor %d waiting, moving to the next floor.\n", currentFloor);
            } else {
                passengers = rand() % capacity + 1; //Number of passengers entering the elevator is random, but cannot exceed capacity
                if(floorRequests[currentFloor-1] < passengers){
                    printf("Picking up %d passengers from floor %d.\n", floorRequests[currentFloor-1], currentFloor);
                    passengersOnboard = floorRequests[currentFloor-1];
                    floorRequests[currentFloor-1] = 0;
                } else {
                    printf("Picking up %d passengers from floor %d.\n", passengers, currentFloor);
                    passengersOnboard = passengers;
                    floorRequests[currentFloor-1] -= passengers;
                }
            }
        } else { //If the elevator has passengers
            if(floorRequests[currentFloor-1] == 0){ //If there are no passengers waiting on the current floor
                printf("There are no passengers on floor %d waiting, moving to the next floor.\n", currentFloor);
            } else {
                printf("Dropping off %d passengers on floor %d and picking up %d passengers.\n", passengersOnboard, currentFloor, floorRequests[currentFloor-1]);
                passengers = rand() % (capacity - passengersOnboard) + 1; //Number of passengers entering the elevator is random, but cannot exceed capacity minus passengers already onboard
                if(floorRequests[currentFloor-1] < passengers){
                    passengersOnboard += floorRequests[currentFloor-1];
                    floorRequests[currentFloor-1] = 0;
                } else {
                    passengersOnboard += passengers;
                    floorRequests[currentFloor-1] -= passengers;
                }
            }
        }
        currentFloor += 1; //Moving the elevator to the next floor
        if(currentFloor > floors){ //If the elevator has reached the top floor
            printf("\nThe elevator has reached the top floor and will now descend.\n\n");
            currentFloor = floors; //Starting from the top floor
            for(int j = floors; j >= 1; j--){
                printf("Elevator arrives at floor %d.\n", currentFloor);
                if(passengersOnboard == 0){ //If the elevator is empty
                    if(floorRequests[currentFloor-1] == 0){ //If there are no passengers waiting on the current floor
                        printf("The elevator is empty and there are no passengers on floor %d waiting, moving to the next floor.\n", currentFloor);
                    } else {
                        passengers = rand() % capacity + 1; //Number of passengers entering the elevator is random, but cannot exceed capacity
                        if(floorRequests[currentFloor-1] < passengers){
                            printf("Picking up %d passengers from floor %d.\n", floorRequests[currentFloor-1], currentFloor);
                            passengersOnboard = floorRequests[currentFloor-1];
                            floorRequests[currentFloor-1] = 0;
                        } else {
                            printf("Picking up %d passengers from floor %d.\n", passengers, currentFloor);
                            passengersOnboard = passengers;
                            floorRequests[currentFloor-1] -= passengers;
                        }
                    }
                } else { //If the elevator has passengers
                    if(floorRequests[currentFloor-1] == 0){ //If there are no passengers waiting on the current floor
                        printf("There are no passengers on floor %d waiting, moving to the next floor.\n", currentFloor);
                    } else {
                        printf("Dropping off %d passengers on floor %d and picking up %d passengers.\n", passengersOnboard, currentFloor, floorRequests[currentFloor-1]);
                        passengers = rand() % (capacity - passengersOnboard) + 1; //Number of passengers entering the elevator is random, but cannot exceed capacity minus passengers already onboard
                        if(floorRequests[currentFloor-1] < passengers){
                            passengersOnboard += floorRequests[currentFloor-1];
                            floorRequests[currentFloor-1] = 0;
                        } else {
                            passengersOnboard += passengers;
                            floorRequests[currentFloor-1] -= passengers;
                        }
                    }
                }
                currentFloor -= 1; //Moving the elevator down to the next floor
            }
            printf("\nThe elevator has returned to the first floor and the simulation is complete!\n");
            break;
        }
    }

    return 0;
}