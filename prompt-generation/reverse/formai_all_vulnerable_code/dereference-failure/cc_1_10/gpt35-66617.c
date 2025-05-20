//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Ada Lovelace
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

// Define constants for drone control
#define MAX_SPEED 100
#define MIN_SPEED 0

// Define drone struct
typedef struct {
    uint32_t id;
    char* name;
    uint32_t speed;
    bool isFlying;
} Drone;

// Define function to create a drone
Drone* createDrone(uint32_t id, char* name, uint32_t speed) {
    Drone* drone = malloc(sizeof(Drone));
    drone->id = id;
    drone->name = name;
    drone->speed = speed;
    drone->isFlying = false;
    return drone;
}

// Define function to fly the drone
void flyDrone(Drone* drone) {
    if (!drone->isFlying) {
        printf("%s is now flying!\n", drone->name);
        drone->isFlying = true;
    }
    else {
        printf("%s is already flying!\n", drone->name);
    }
}

// Define function to land the drone
void landDrone(Drone* drone) {
    if (drone->isFlying) {
        printf("%s is now landing!\n", drone->name);
        drone->isFlying = false;
    }
    else {
        printf("%s is already on the ground!\n", drone->name);
    }
}

// Define function to increase the speed of the drone
void increaseSpeed(Drone* drone) {
    if (drone->speed < MAX_SPEED) {
        drone->speed++;
        printf("%s speed increased to %d\n", drone->name, drone->speed);
    }
    else {
        printf("%s is already at maximum speed!\n", drone->name);
    }
}

// Define function to decrease the speed of the drone
void decreaseSpeed(Drone* drone) {
    if (drone->speed > MIN_SPEED) {
        drone->speed--;
        printf("%s speed decreased to %d\n", drone->name, drone->speed);
    }
    else {
        printf("%s is already at minimum speed!\n", drone->name);
    }
}

// Define main function to control the drone remotely
int main() {
    // Create a drone with ID 1 and name "Mavic Pro"
    Drone* drone = createDrone(1, "Mavic Pro", 0);
    
    // Fly the drone
    flyDrone(drone);
    
    // Increase the speed of the drone
    increaseSpeed(drone);
    
    // Decrease the speed of the drone
    decreaseSpeed(drone);
    
    // Land the drone
    landDrone(drone);
    
    // Free the drone memory
    free(drone);
    
    return 0;
}