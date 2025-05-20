//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define vehicle struct
typedef struct {
    int id;
    int xPos;
    int yPos;
    char direction;
    int speed;
} Vehicle;

// Define function to print vehicle position and direction
void printVehicle(Vehicle vehicle) {
    printf("Vehicle %d is at position (%d, %d) facing %c\n", vehicle.id, vehicle.xPos, vehicle.yPos, vehicle.direction);
}

int main() {
    int numVehicles = 5;
    
    // Allocate memory for vehicle array with random positions, directions, and speeds
    Vehicle* vehicles = malloc(numVehicles * sizeof(Vehicle));
    srand(time(NULL));
    for (int i = 0; i < numVehicles; i++) {
        vehicles[i].id = i+1;
        vehicles[i].xPos = rand() % 10 + 1;
        vehicles[i].yPos = rand() % 10 + 1;
        vehicles[i].speed = rand() % 5 + 1;
        int randDir = rand() % 4 + 1;
        if (randDir == 1) {
            vehicles[i].direction = 'N';
        } else if (randDir == 2) {
            vehicles[i].direction = 'S';
        } else if (randDir == 3) {
            vehicles[i].direction = 'E';
        } else {
            vehicles[i].direction = 'W';
        }
        printVehicle(vehicles[i]);
    }
    
    // Simulate vehicles moving in their respective directions at their respective speeds
    for (int i = 0; i < 10; i++) {
        printf("------\n");
        for (int j = 0; j < numVehicles; j++) {
            if (vehicles[j].direction == 'N') {
                vehicles[j].yPos += vehicles[j].speed;
            } else if (vehicles[j].direction == 'S') {
                vehicles[j].yPos -= vehicles[j].speed;
            } else if (vehicles[j].direction == 'E') {
                vehicles[j].xPos += vehicles[j].speed;
            } else {
                vehicles[j].xPos -= vehicles[j].speed;
            }
            printVehicle(vehicles[j]);
        }
    }
    
    // Free memory for vehicle array
    free(vehicles);
    
    return 0;
}