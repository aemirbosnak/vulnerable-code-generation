//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: surprised
// Traffic Flow Simulation
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    int cars = 0;
    int intersection = 0;
    int startTime = 0;
    int endTime = 0;
    int simulationTime = 0;
    int carSpeed = 0;
    int carWaitTime = 0;
    int trafficLightWaitTime = 0;

    // Initialize random number generator
    srand(time(0));

    // Start simulation
    printf("Starting simulation...\n");

    // Loop through simulation time
    while (simulationTime < endTime) {
        // Generate random number for car speed
        carSpeed = rand() % 100;

        // Calculate car wait time
        carWaitTime = (carSpeed * (simulationTime - startTime)) / 60;

        // Generate random number for traffic light wait time
        trafficLightWaitTime = rand() % 60;

        // Check if car is at intersection
        if (intersection == 1) {
            // Wait for traffic light to change
            printf("Traffic light: %d\n", trafficLightWaitTime);
            sleep(trafficLightWaitTime);

            // Check if car can enter intersection
            if (trafficLightWaitTime == 0) {
                printf("Car enters intersection\n");
            } else {
                printf("Car waits at intersection\n");
            }
        }

        // Update car and intersection variables
        cars++;
        intersection = 1;

        // Update simulation time
        simulationTime++;
    }

    // End simulation
    printf("Simulation ended.\n");

    // Print results
    printf("Total cars: %d\n", cars);
    printf("Average car speed: %.2f mph\n", (carSpeed / cars) * 60);
    printf("Average car wait time: %.2f seconds\n", carWaitTime);

    return 0;
}