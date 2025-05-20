//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: energetic
#include <stdio.h>

int main() {
    int numCars = 0, numLanes = 0, maxSpeed = 0;
    printf("Enter the number of cars: ");
    scanf("%d", &numCars);
    printf("Enter the number of lanes: ");
    scanf("%d", &numLanes);
    printf("Enter the maximum speed limit: ");
    scanf("%d", &maxSpeed);

    int carPosition[numCars];
    for (int i = 0; i < numCars; i++) {
        carPosition[i] = i * numLanes;
    }

    printf("\nStarting Simulation...\n\n");

    int time = 0;
    while (1) {
        printf("Time: %d\n", time);

        for (int i = 0; i < numCars; i++) {
            // Acceleration
            carPosition[i] += rand() % (maxSpeed + 1);
            // Deceleration
            for (int j = 0; j < numCars; j++) {
                if (i != j && carPosition[j] >= carPosition[i] && carPosition[j] - carPosition[i] <= 10) {
                    carPosition[i] = carPosition[j] - 11;
                }
            }
            // Random slowing down
            if (rand() % 5 == 0) {
                carPosition[i] -= rand() % 10;
            }
            // Boundaries and reset
            if (carPosition[i] < 0) {
                carPosition[i] = 0;
            } else if (carPosition[i] > numLanes * (numCars - 1)) {
                printf("Car %d finished the simulation!\n", i+1);
                carPosition[i] = i * numLanes;
            }
        }

        // Print lanes
        for (int i = 0; i < numLanes; i++) {
            for (int j = 0; j < numCars; j++) {
                if (carPosition[j] == i + (j * numLanes)) {
                    printf("C");
                } else {
                    printf("-");
                }
            }
            printf("\n");
        }

        // Sleep for 1 second
        printf("\n");
        time++;
        sleep(1);
    }

    return 0;
}