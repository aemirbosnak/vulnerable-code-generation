//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: random
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ALTITUDE_LIMIT 50   // in meters
#define BATTERY_LIMIT 10    // in percent

// Function to generate random drone ID
char* generateDroneID() {
    char* droneID = malloc(sizeof(char) * 7);
    static const char charSet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < 6; i++) {
        int index = rand() % (sizeof(charSet) - 1);
        droneID[i] = charSet[index];
    }
    droneID[6] = '\0';
    return droneID;
}

// Drone structure
struct Drone {
    char* ID;
    int battery;
    int altitude;
    bool isFlying;
};

// Function to initialize drone structure
struct Drone* initializeDrone() {
    struct Drone* drone = malloc(sizeof(struct Drone));
    drone->ID = generateDroneID();
    drone->battery = 100;
    drone->altitude = 0;
    drone->isFlying = false;
    return drone;
}

// Function to check if drone is within altitude limit
bool isWithinAltitudeLimit(struct Drone* drone) {
    if (drone->altitude > ALTITUDE_LIMIT) {
        return false;
    }
    return true;
}

// Function to check if drone is within battery limit
bool isWithinBatteryLimit(struct Drone* drone) {
    if (drone->battery < BATTERY_LIMIT) {
        return false;
    }
    return true;
}

// Function to simulate drone movement
void moveDrone(struct Drone* drone) {
    if (drone->isFlying) {
        int movement = rand() % 10;
        int direction = rand() % 4;  // 0 - North, 1 - East, 2 - South, 3 - West
        switch (direction) {
            case 0:
                drone->altitude += movement;
                break;
            case 1:
                drone->altitude -= movement;
                break;
            case 2:
                drone->battery -= movement;
                break;
            case 3:
                drone->battery += movement;
                break;
        }
    }
}

// Main function
int main() {
    srand(time(NULL));  // ensure random numbers in each program run
    struct Drone* drone = initializeDrone();
    printf("Drone ID: %s\n", drone->ID);

    int option;
    do {
        printf("Choose an option:\n");
        printf("1 - Take off\n");
        printf("2 - Land\n");
        printf("3 - Move\n");
        printf("4 - Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (drone->isFlying) {
                    printf("Drone is already flying!\n");
                } else {
                    drone->isFlying = true;
                    printf("Drone has taken off!\n");
                }
                break;
            case 2:
                if (!drone->isFlying) {
                    printf("Drone is already on the ground!\n");
                } else {
                    drone->isFlying = false;
                    printf("Drone has landed!\n");
                }
                break;
            case 3:
                if (!drone->isFlying) {
                    printf("Drone needs to be in the air to move!\n");
                } else if (!isWithinAltitudeLimit(drone)) {
                    printf("Drone is above the altitude limit!\n");
                } else if (!isWithinBatteryLimit(drone)) {
                    printf("Drone is below the battery limit!\n");
                } else {
                    moveDrone(drone);
                    printf("Drone has moved!\n");
                    printf("Battery: %d%%\n", drone->battery);
                    printf("Altitude: %dm\n", drone->altitude);
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
        
    } while (option != 4);

    free(drone->ID);
    free(drone);
    return 0;
}