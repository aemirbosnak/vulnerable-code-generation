//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate traffic flow
void trafficFlowSimulation(int numCars, int numSeconds) {
    int i, j, k;
    int* road = (int*) malloc(numCars * sizeof(int));
    int maxSpeed = 60;
    
    // Initialize the road
    for (i = 0; i < numCars; i++) {
        road[i] = -1; //Empty
    }
    
    // Start the simulation
    for (i = 0; i < numSeconds; i++) {
        // Add a new car at random intervals
        if (rand() % 2 == 0) {
            // Find an empty position on the road to insert the new car
            for (j = 0; j < numCars; j++) {
                if (road[j] == -1) {
                    road[j] = 0;
                    break;
                }
            }
        }
        // Update the speed of each car
        for (j = 0; j < numCars; j++) {
            if (road[j] != -1) {
                int speed = maxSpeed;
                // Check for cars in front and adjust speed accordingly
                for (k = j+1; k < numCars; k++) {
                    if (road[k] != -1) {
                        int distance = k - j;
                        if (distance <= road[j] + speed) {
                            speed = distance - road[j];
                            if (speed <= 0) {
                                speed = 1;
                            }
                            break;
                        }
                    }
                }
                // Check for random slow down
                if (rand() % 3 == 0) {
                    if (speed > 1) {
                        speed--;
                    }
                }
                road[j] += speed;
            }
        }
        // Print the status of the road
        for (j = 0; j < numCars; j++) {
            if (road[j] == -1) {
                printf(".");
            } else {
                printf("%d", road[j] % 10);
            }
        }
        printf("\n");
    }
    free(road);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Run the traffic flow simulation
    trafficFlowSimulation(50, 100);
    
    return 0;
}