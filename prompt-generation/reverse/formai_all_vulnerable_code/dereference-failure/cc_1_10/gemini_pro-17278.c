//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Vehicle struct
typedef struct Vehicle {
    char model[20];
    int speed;
    int durability;
    int fuel;
} Vehicle;

// Environment struct
typedef struct Environment {
    char terrain[20];
    int obstacles;
    int radiation;
} Environment;

// Function to create a new vehicle
Vehicle* createVehicle(char* model, int speed, int durability, int fuel) {
    Vehicle* vehicle = malloc(sizeof(Vehicle));
    strcpy(vehicle->model, model);
    vehicle->speed = speed;
    vehicle->durability = durability;
    vehicle->fuel = fuel;
    return vehicle;
}

// Function to create a new environment
Environment* createEnvironment(char* terrain, int obstacles, int radiation) {
    Environment* environment = malloc(sizeof(Environment));
    strcpy(environment->terrain, terrain);
    environment->obstacles = obstacles;
    environment->radiation = radiation;
    return environment;
}

// Function to simulate the movement of the vehicle
void moveVehicle(Vehicle* vehicle, Environment* environment) {
    // Calculate the distance traveled
    int distance = vehicle->speed * 1;

    // Reduce fuel consumption
    vehicle->fuel -= distance / 10;

    // Check for obstacles
    if (environment->obstacles > 0) {
        // Reduce durability
        vehicle->durability -= environment->obstacles * 1;

        // Reduce speed
        vehicle->speed -= environment->obstacles * 1;
    }

    // Check for radiation
    if (environment->radiation > 0) {
        // Reduce durability
        vehicle->durability -= environment->radiation * 1;
    }

    // Check if the vehicle is destroyed
    if (vehicle->durability <= 0) {
        printf("Your vehicle has been destroyed!\n");
        exit(1);
    }

    // Check if the vehicle has run out of fuel
    if (vehicle->fuel <= 0) {
        printf("Your vehicle has run out of fuel!\n");
        exit(1);
    }
}

// Function to print the status of the vehicle
void printVehicleStatus(Vehicle* vehicle) {
    printf("Vehicle: %s\n", vehicle->model);
    printf("Speed: %d\n", vehicle->speed);
    printf("Durability: %d\n", vehicle->durability);
    printf("Fuel: %d\n", vehicle->fuel);
}

// Function to print the status of the environment
void printEnvironmentStatus(Environment* environment) {
    printf("Terrain: %s\n", environment->terrain);
    printf("Obstacles: %d\n", environment->obstacles);
    printf("Radiation: %d\n", environment->radiation);
}

// Function to simulate the remote control vehicle
void simulateRCVehicle() {
    // Create a new vehicle
    Vehicle* vehicle = createVehicle("Razorback", 10, 100, 100);

    // Create a new environment
    Environment* environment = createEnvironment("Wasteland", 10, 20);

    // Print the initial status of the vehicle and environment
    printVehicleStatus(vehicle);
    printEnvironmentStatus(environment);

    // Simulate the movement of the vehicle
    for (int i = 0; i < 10; i++) {
        moveVehicle(vehicle, environment);

        // Print the updated status of the vehicle and environment
        printVehicleStatus(vehicle);
        printEnvironmentStatus(environment);
    }
}

// Main function
int main() {
    srand(time(NULL));

    simulateRCVehicle();

    return 0;
}