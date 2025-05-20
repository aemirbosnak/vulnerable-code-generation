//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Define the drone's state
typedef enum {
    IDLE,
    TAKEOFF,
    LANDING,
    FLYING
} drone_state;

// Define the drone's commands
typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    FORWARD,
    BACKWARD,
    STOP
} drone_command;

// Define the drone's structure
typedef struct {
    drone_state state;
    int altitude;
    int speed;
    int direction;
} drone;

// Create a new drone
drone* drone_create() {
    drone* d = malloc(sizeof(drone));
    d->state = IDLE;
    d->altitude = 0;
    d->speed = 0;
    d->direction = 0;
    return d;
}

// Destroy a drone
void drone_destroy(drone* d) {
    free(d);
}

// Take off the drone
void drone_takeoff(drone* d) {
    if (d->state == IDLE) {
        d->state = TAKEOFF;
        d->altitude = 1;
        d->speed = 1;
        d->direction = 0;
    }
}

// Land the drone
void drone_land(drone* d) {
    if (d->state == FLYING) {
        d->state = LANDING;
        d->altitude = 0;
        d->speed = 0;
        d->direction = 0;
    }
}

// Fly the drone
void drone_fly(drone* d, drone_command command) {
    if (d->state == FLYING) {
        switch (command) {
            case UP:
                d->altitude++;
                break;
            case DOWN:
                d->altitude--;
                break;
            case LEFT:
                d->direction -= 10;
                break;
            case RIGHT:
                d->direction += 10;
                break;
            case FORWARD:
                d->speed += 1;
                break;
            case BACKWARD:
                d->speed -= 1;
                break;
            case STOP:
                d->speed = 0;
                break;
        }
    }
}

// Print the drone's state
void drone_print(drone* d) {
    printf("State: %s\n", d->state == IDLE ? "IDLE" : d->state == TAKEOFF ? "TAKEOFF" : d->state == LANDING ? "LANDING" : "FLYING");
    printf("Altitude: %d\n", d->altitude);
    printf("Speed: %d\n", d->speed);
    printf("Direction: %d\n", d->direction);
}

// Main function
int main() {
    // Create a new drone
    drone* d = drone_create();

    // Take off the drone
    drone_takeoff(d);

    // Fly the drone
    drone_fly(d, UP);
    drone_fly(d, FORWARD);
    drone_fly(d, RIGHT);
    drone_fly(d, DOWN);
    drone_fly(d, BACKWARD);
    drone_fly(d, LEFT);
    drone_fly(d, STOP);

    // Land the drone
    drone_land(d);

    // Print the drone's state
    drone_print(d);

    // Destroy the drone
    drone_destroy(d);

    return 0;
}