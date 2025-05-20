//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SPEED 100
#define MIN_SPEED 0

struct remote_control_vehicle {
    int speed;
    bool reverse;
    char direction;
};

void print_status(struct remote_control_vehicle* vehicle) {
    printf("Speed: %d\n", vehicle->speed);
    printf("Direction: %c\n", vehicle->direction);
    printf("Reverse: %s\n", vehicle->reverse ? "On" : "Off");
}

void increase_speed(struct remote_control_vehicle* vehicle, int speed) {
    if (vehicle->speed + speed >= MAX_SPEED) {
        vehicle->speed = MAX_SPEED;
    } else {
        vehicle->speed += speed;
    }
}

void decrease_speed(struct remote_control_vehicle* vehicle, int speed) {
    if (vehicle->speed - speed <= MIN_SPEED) {
        vehicle->speed = MIN_SPEED;
    } else {
        vehicle->speed -= speed;
    }
}

void reverse_direction(struct remote_control_vehicle* vehicle) {
    vehicle->reverse = !vehicle->reverse;
    if (vehicle->reverse) {
        switch (vehicle->direction) {
            case 'N':
                vehicle->direction = 'S';
                break;
            case 'S':
                vehicle->direction = 'N';
                break;
            case 'E':
                vehicle->direction = 'W';
                break;
            case 'W':
                vehicle->direction = 'E';
                break;
            default:
                break;
        }
    } else {
        switch (vehicle->direction) {
            case 'N':
                vehicle->direction = 'N';
                break;
            case 'S':
                vehicle->direction = 'S';
                break;
            case 'E':
                vehicle->direction = 'E';
                break;
            case 'W':
                vehicle->direction = 'W';
                break;
            default:
                break;
        }
    }
}

void turn_left(struct remote_control_vehicle* vehicle) {
    if (!vehicle->reverse) {
        switch (vehicle->direction) {
            case 'N':
                vehicle->direction = 'W';
                break;
            case 'S':
                vehicle->direction = 'E';
                break;
            case 'E':
                vehicle->direction = 'N';
                break;
            case 'W':
                vehicle->direction = 'S';
                break;
            default:
                break;
        }
    } else {
        switch (vehicle->direction) {
            case 'N':
                vehicle->direction = 'E';
                break;
            case 'S':
                vehicle->direction = 'W';
                break;
            case 'E':
                vehicle->direction = 'S';
                break;
            case 'W':
                vehicle->direction = 'N';
                break;
            default:
                break;
        }
    }
}

void turn_right(struct remote_control_vehicle* vehicle) {
    if (!vehicle->reverse) {
        switch (vehicle->direction) {
            case 'N':
                vehicle->direction = 'E';
                break;
            case 'S':
                vehicle->direction = 'W';
                break;
            case 'E':
                vehicle->direction = 'S';
                break;
            case 'W':
                vehicle->direction = 'N';
                break;
            default:
                break;
        }
    } else {
        switch (vehicle->direction) {
            case 'N':
                vehicle->direction = 'W';
                break;
            case 'S':
                vehicle->direction = 'E';
                break;
            case 'E':
                vehicle->direction = 'N';
                break;
            case 'W':
                vehicle->direction = 'S';
                break;
            default:
                break;
        }
    }
}

int main() {
    struct remote_control_vehicle* vehicle = malloc(sizeof(struct remote_control_vehicle));
    vehicle->speed = 0;
    vehicle->direction = 'N';
    vehicle->reverse = false;

    printf("Starting the remote control vehicle simulation...\n\n");

    printf("Current status:\n");
    print_status(vehicle);
    printf("\n");

    printf("Setting vehicle speed to 50...\n");
    increase_speed(vehicle, 50);
    printf("Current status:\n");
    print_status(vehicle);
    printf("\n");

    printf("Turning right...\n");
    turn_right(vehicle);
    printf("Current status:\n");
    print_status(vehicle);
    printf("\n");

    printf("Turning left...\n");
    turn_left(vehicle);
    printf("Current status:\n");
    print_status(vehicle);
    printf("\n");

    printf("Reversing the vehicle direction...\n");
    reverse_direction(vehicle);
    printf("Current status:\n");
    print_status(vehicle);
    printf("\n");

    printf("Decreasing the vehicle speed by 30...\n");
    decrease_speed(vehicle, 30);
    printf("Current status:\n");
    print_status(vehicle);

    free(vehicle);
    return 0;
}