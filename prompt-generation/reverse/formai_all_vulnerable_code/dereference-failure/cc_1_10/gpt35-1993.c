//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for remote controlled vehicles
typedef struct {
    char* name; // Name of the vehicle
    int speed; // Speed of the vehicle
    int direction; // Direction of the vehicle
} RCVehicle;

// Function to initialize a new remote controlled vehicle
RCVehicle* initializeVehicle(char* name, int speed, int direction) {
    RCVehicle* vehicle = (RCVehicle*) malloc(sizeof(RCVehicle));
    vehicle->name = name;
    vehicle->speed = speed;
    vehicle->direction = direction;
    return vehicle;
}

// Function to drive the vehicle forward
void driveForward(RCVehicle* vehicle) {
    printf("Driving %s forward...\n", vehicle->name);
    vehicle->direction = 1;
}

// Function to drive the vehicle backward
void driveBackward(RCVehicle* vehicle) {
    printf("Driving %s backward...\n", vehicle->name);
    vehicle->direction = -1;
}

// Function to turn the vehicle left
void turnLeft(RCVehicle* vehicle) {
    printf("Turning %s left...\n", vehicle->name);
    vehicle->direction -= 1;
}

// Function to turn the vehicle right
void turnRight(RCVehicle* vehicle) {
    printf("Turning %s right...\n", vehicle->name);
    vehicle->direction += 1;
}

// Function to stop the vehicle
void stop(RCVehicle* vehicle) {
    printf("%s has stopped.\n", vehicle->name);
    vehicle->direction = 0;
}

int main() {
    // Initialize two vehicles
    RCVehicle* car = initializeVehicle("Car", 50, 0);
    RCVehicle* truck = initializeVehicle("Truck", 35, 0);

    // Drive the car forward and turn it left
    driveForward(car);
    turnLeft(car);

    // Drive the truck backward and turn it right
    driveBackward(truck);
    turnRight(truck);

    // Stop both vehicles
    stop(car);
    stop(truck);

    // Free the memory allocated to the vehicles
    free(car);
    free(truck);

    return 0;
}