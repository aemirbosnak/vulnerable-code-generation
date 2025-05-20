//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random seed
    int numVehicles = 1000; // Total number of vehicles
    int numLanes = 4; // Number of lanes on the road
    int speed = 60; // Maximum speed of vehicles

    int *vehicles = (int *)malloc(numVehicles * sizeof(int)); // Create an array to store vehicle positions
    for (int i = 0; i < numVehicles; i++) {
        vehicles[i] = rand() % numLanes; // Assign random position to each vehicle
    }

    printf("Traffic simulation with %d vehicles on %d lanes, maximum speed %d mph:\n", numVehicles, numLanes, speed);

    int currentVehicle = 0; // Current vehicle index
    int currentLane = 0; // Current lane index
    int lastMovement = 0; // Last movement time

    int movementTime = 1; // Time between movements (in seconds)

    while (currentVehicle < numVehicles) {
        printf("Vehicle %d is at lane %d\n", currentVehicle + 1, vehicles[currentVehicle]);

        int movement = rand() % 3; // Randomly choose a movement option

        if (movement == 0) {
            if (currentLane < numLanes - 1) { // Move to the next lane
                currentLane++;
            } else { // Move to the first lane
                currentLane = 0;
            }
        } else if (movement == 1) {
            if (currentLane > 0) { // Move to the previous lane
                currentLane--;
            } else { // Move to the last lane
                currentLane = numLanes - 1;
            }
        } else if (movement == 2) { // Move to the next lane
            currentLane++;
        }

        if (currentLane!= lastMovement) { // Check if the lane changed
            lastMovement = currentLane; // Update last movement time
            sleep(movementTime); // Wait for the movement time
        }

        currentVehicle++; // Move to the next vehicle
    }

    free(vehicles); // Free the allocated memory

    return 0;
}