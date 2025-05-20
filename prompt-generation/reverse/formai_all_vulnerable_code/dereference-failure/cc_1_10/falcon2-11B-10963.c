//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    // Define the number of vehicles in the simulation
    int numVehicles = 100;

    // Create an array to store the vehicles
    int* vehicles = (int*)malloc(numVehicles * sizeof(int));

    // Initialize the vehicles with random speeds
    for (int i = 0; i < numVehicles; i++) {
        vehicles[i] = rand() % 100;
    }

    // Calculate the total length of the road
    int totalLength = 1000;

    // Calculate the number of lanes
    int numLanes = totalLength / numVehicles;

    // Calculate the speed limit for each lane
    int speedLimit = 60;

    // Calculate the average speed of the vehicles
    int avgSpeed = 0;

    // Iterate through the vehicles and calculate the average speed
    for (int i = 0; i < numVehicles; i++) {
        avgSpeed += vehicles[i];
    }
    avgSpeed /= numVehicles;

    // Calculate the traffic flow
    int trafficFlow = numVehicles * numLanes;

    // Print the results
    printf("Total vehicles: %d\n", numVehicles);
    printf("Total length of road: %d\n", totalLength);
    printf("Number of lanes: %d\n", numLanes);
    printf("Average speed: %.2f mph\n", (avgSpeed / speedLimit));
    printf("Traffic flow: %d vehicles/hour\n", trafficFlow);

    free(vehicles);

    return 0;
}