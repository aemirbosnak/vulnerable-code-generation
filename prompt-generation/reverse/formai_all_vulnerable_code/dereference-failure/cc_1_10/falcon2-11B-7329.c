//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numVehicles = 100;
    int numLanes = 2;
    int numMinutes = 60;
    
    srand(time(NULL));
    
    int* vehicles = malloc(numVehicles * sizeof(int));
    for (int i = 0; i < numVehicles; i++) {
        vehicles[i] = rand() % (numLanes - 1) + 1;
    }
    
    int currentTime = 0;
    int currentVehicle = 0;
    int currentLane = 0;
    
    while (currentTime < numMinutes) {
        printf("Current time: %d minutes\n", currentTime);
        printf("Current vehicle: %d\n", currentVehicle);
        printf("Current lane: %d\n", currentLane);
        
        if (currentVehicle < numVehicles) {
            currentVehicle++;
            
            if (currentVehicle < numVehicles) {
                currentVehicle += vehicles[currentVehicle];
            }
            
            if (currentVehicle >= numVehicles) {
                currentVehicle = 0;
            }
            
            if (currentVehicle < numVehicles) {
                currentVehicle = 0;
            }
        }
        
        if (currentTime < numMinutes) {
            currentTime++;
        }
        
        if (currentTime < numMinutes) {
            currentTime++;
        }
        
        if (currentTime < numMinutes) {
            currentTime++;
        }
    }
    
    free(vehicles);
    
    return 0;
}