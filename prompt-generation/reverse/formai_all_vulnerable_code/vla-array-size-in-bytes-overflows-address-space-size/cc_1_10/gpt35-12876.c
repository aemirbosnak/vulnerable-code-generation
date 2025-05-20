//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Struct to hold information about each vehicle
typedef struct Vehicle {
    int id;
    int speed;
    int distance;
    char direction;
} Vehicle;

// Function to initialize a new vehicle with random speed and direction
Vehicle* initVehicle(int id) {
    Vehicle* vehicle = malloc(sizeof(Vehicle));
    vehicle->id = id;
    vehicle->speed = rand() % 10 + 1;
    vehicle->distance = 0;
    int dir = rand() % 2;
    if (dir == 0) {
        vehicle->direction = 'N';
    } else {
        vehicle->direction = 'S';
    }
    return vehicle;
}

// Function to update the position of a vehicle based on its speed
void updateVehicle(Vehicle* vehicle) {
    vehicle->distance += vehicle->speed;
}

int main() {
    srand(time(NULL)); // Seed random number generator
    int num_vehicles;
    printf("Enter number of vehicles: ");
    scanf("%d", &num_vehicles);

    // Create an array to hold vehicles
    Vehicle* vehicles[num_vehicles];

    // Initialize each vehicle in the array
    for (int i = 0; i < num_vehicles; i++) {
        vehicles[i] = initVehicle(i);
    }

    // Simulate traffic flow for 10 seconds
    int time_elapsed = 0;
    while (time_elapsed < 10) {
        printf("Time elapsed: %d seconds\n", time_elapsed);

        // Update the positions of each vehicle
        for (int i = 0; i < num_vehicles; i++) {
            updateVehicle(vehicles[i]);
        }

        // Check for collisions and print out the position of each vehicle
        for (int i = 0; i < num_vehicles; i++) {
            for (int j = i + 1; j < num_vehicles; j++) {
                if (vehicles[i]->direction == vehicles[j]->direction &&
                    abs(vehicles[i]->distance - vehicles[j]->distance) < 10) {
                    printf("COLLISION: Vehicle %d and Vehicle %d\n", vehicles[i]->id, vehicles[j]->id);
                }
            }
            printf("Vehicle %d: %d %c\n", vehicles[i]->id, vehicles[i]->distance, vehicles[i]->direction);
        }

        // Wait for one second
        printf("\n");
        time_elapsed++;
        sleep(1);
    }

    // Free memory used by the vehicles
    for (int i = 0; i < num_vehicles; i++) {
        free(vehicles[i]);
    }

    return 0;
}