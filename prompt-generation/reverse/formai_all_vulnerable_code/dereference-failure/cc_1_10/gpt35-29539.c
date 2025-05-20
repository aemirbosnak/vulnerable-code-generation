//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define the drone struct
typedef struct {
    int x_pos;
    int y_pos;
    int z_pos;
    int battery_level;
    int speed;
    int direction;
} Drone;

// Define the remote control struct
typedef struct {
    Drone *drone;
} RemoteControl;

// Function to move the drone
int moveDrone(Drone *drone, int x, int y, int z) {
    if(drone->battery_level <= 0) {
        printf("Cannot move the drone. Battery level is too low.\n");
        return 0;
    }
    drone->x_pos += x;
    drone->y_pos += y;
    drone->z_pos += z;
    drone->battery_level -= 10;
    printf("Drone moved to position (%d, %d, %d).\n", drone->x_pos, drone->y_pos, drone->z_pos);
    return 1;
}

// Function to charge the drone
void chargeDrone(Drone *drone) {
    drone->battery_level = 100;
    printf("Drone battery level is now at %d percent.\n", drone->battery_level);
}

// Function to change the drone's speed
void changeSpeed(Drone *drone, int newSpeed) {
    drone->speed = newSpeed;
    printf("Drone speed is now set to %d meters per second.\n", drone->speed);
}

// Function to change the drone's direction
void changeDirection(Drone *drone, int newDirection) {
    drone->direction = newDirection;
    printf("Drone direction is now set to %d degrees.\n", drone->direction);
}

// Function to select a drone to control
Drone *selectDrone() {
    int option;
    Drone *drone = NULL;
    printf("Please select the drone you would like to control:\n");
    printf("1. Drone 1\n");
    printf("2. Drone 2\n");
    printf("3. Drone 3\n");
    scanf("%d", &option);
    switch(option) {
        case 1:
            drone = (Drone *)malloc(sizeof(Drone));
            drone->x_pos = 0;
            drone->y_pos = 0;
            drone->z_pos = 0;
            drone->battery_level = 100;
            drone->speed = 10;
            drone->direction = 0;
            break;
        case 2:
            drone = (Drone *)malloc(sizeof(Drone));
            drone->x_pos = 0;
            drone->y_pos = 0;
            drone->z_pos = 0;
            drone->battery_level = 100;
            drone->speed = 15;
            drone->direction = 90;
            break;
        case 3:
            drone = (Drone *)malloc(sizeof(Drone));
            drone->x_pos = 0;
            drone->y_pos = 0;
            drone->z_pos = 0;
            drone->battery_level = 100;
            drone->speed = 20;
            drone->direction = 180;
            break;
        default:
            printf("Invalid option. Please try again.\n");
            break;
    }
    return drone;
}

// Function to control the drone
void controlDrone(RemoteControl *remoteControl) {
    int option, x, y, z;
    Drone *drone = remoteControl->drone;
    while(1) {
        printf("Current drone position: (%d, %d, %d)\n", drone->x_pos, drone->y_pos, drone->z_pos);
        printf("Current battery level: %d percent\n", drone->battery_level);
        printf("Current speed: %d meters per second\n", drone->speed);
        printf("Current direction: %d degrees\n", drone->direction);
        printf("Please select an option:\n");
        printf("1. Move drone\n");
        printf("2. Charge drone\n");
        printf("3. Change speed\n");
        printf("4. Change direction\n");
        printf("5. Select another drone\n");
        printf("6. Quit\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("Enter the x, y, and z coordinates (separated by spaces) to move the drone:\n");
                scanf("%d %d %d", &x, &y, &z);
                moveDrone(drone, x, y, z);
                break;
            case 2:
                chargeDrone(drone);
                break;
            case 3:
                printf("Enter the new speed:\n");
                scanf("%d", &x);
                changeSpeed(drone, x);
                break;
            case 4:
                printf("Enter the new direction (in degrees):\n");
                scanf("%d", &x);
                changeDirection(drone, x);
                break;
            case 5:
                drone = selectDrone();
                remoteControl->drone = drone;
                break;
            case 6:
                printf("Goodbye!\n");
                return;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
}

int main() {
    RemoteControl remoteControl;
    Drone *drone;
    printf("Welcome to the C Drone Remote Control program!\n");
    drone = selectDrone();
    remoteControl.drone = drone;
    controlDrone(&remoteControl);
    return 0;
}