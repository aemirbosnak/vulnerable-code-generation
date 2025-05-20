//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program simulates a drone remote control.

// The drone's state.
enum drone_state {
    DRONE_STATE_IDLE,
    DRONE_STATE_TAKING_OFF,
    DRONE_STATE_FLYING,
    DRONE_STATE_LANDING,
    DRONE_STATE_CRASHED
};

// The drone's commands.
enum drone_command {
    DRONE_COMMAND_TAKE_OFF,
    DRONE_COMMAND_LAND,
    DRONE_COMMAND_MOVE_FORWARD,
    DRONE_COMMAND_MOVE_BACKWARD,
    DRONE_COMMAND_MOVE_LEFT,
    DRONE_COMMAND_MOVE_RIGHT,
    DRONE_COMMAND_ROTATE_LEFT,
    DRONE_COMMAND_ROTATE_RIGHT,
    DRONE_COMMAND_FLIP,
    DRONE_COMMAND_CRASH
};

// The drone's response to commands.
enum drone_response {
    DRONE_RESPONSE_OK,
    DRONE_RESPONSE_ERROR,
    DRONE_RESPONSE_CRASHED
};

// The drone's structure.
struct drone {
    enum drone_state state;
    enum drone_command command;
    enum drone_response response;
    int x;
    int y;
    int z;
    int roll;
    int pitch;
    int yaw;
};

// The drone's remote control.
struct remote_control {
    enum drone_command command;
};

// Create a new drone.
struct drone *drone_create() {
    struct drone *drone = malloc(sizeof(struct drone));
    drone->state = DRONE_STATE_IDLE;
    drone->command = DRONE_COMMAND_TAKE_OFF;
    drone->response = DRONE_RESPONSE_OK;
    drone->x = 0;
    drone->y = 0;
    drone->z = 0;
    drone->roll = 0;
    drone->pitch = 0;
    drone->yaw = 0;
    return drone;
}

// Destroy a drone.
void drone_destroy(struct drone *drone) {
    free(drone);
}

// Send a command to the drone.
void drone_send_command(struct drone *drone, enum drone_command command) {
    drone->command = command;
}

// Update the drone's state.
void drone_update(struct drone *drone) {
    switch (drone->state) {
        case DRONE_STATE_IDLE:
            if (drone->command == DRONE_COMMAND_TAKE_OFF) {
                drone->state = DRONE_STATE_TAKING_OFF;
            }
            break;
        case DRONE_STATE_TAKING_OFF:
            if (drone->z < 100) {
                drone->z++;
            } else {
                drone->state = DRONE_STATE_FLYING;
            }
            break;
        case DRONE_STATE_FLYING:
            switch (drone->command) {
                case DRONE_COMMAND_LAND:
                    drone->state = DRONE_STATE_LANDING;
                    break;
                case DRONE_COMMAND_MOVE_FORWARD:
                    drone->y++;
                    break;
                case DRONE_COMMAND_MOVE_BACKWARD:
                    drone->y--;
                    break;
                case DRONE_COMMAND_MOVE_LEFT:
                    drone->x--;
                    break;
                case DRONE_COMMAND_MOVE_RIGHT:
                    drone->x++;
                    break;
                case DRONE_COMMAND_ROTATE_LEFT:
                    drone->yaw--;
                    break;
                case DRONE_COMMAND_ROTATE_RIGHT:
                    drone->yaw++;
                    break;
                case DRONE_COMMAND_FLIP:
                    drone->roll = 360;
                    drone->pitch = 360;
                    drone->yaw = 360;
                    break;
                case DRONE_COMMAND_CRASH:
                    drone->state = DRONE_STATE_CRASHED;
                    break;
            }
            break;
        case DRONE_STATE_LANDING:
            if (drone->z > 0) {
                drone->z--;
            } else {
                drone->state = DRONE_STATE_IDLE;
            }
            break;
        case DRONE_STATE_CRASHED:
            drone->response = DRONE_RESPONSE_CRASHED;
            break;
    }
}

// Get the drone's response to the last command.
enum drone_response drone_get_response(struct drone *drone) {
    return drone->response;
}

// Print the drone's state.
void drone_print_state(struct drone *drone) {
    switch (drone->state) {
        case DRONE_STATE_IDLE:
            printf("Drone is idle.\n");
            break;
        case DRONE_STATE_TAKING_OFF:
            printf("Drone is taking off.\n");
            break;
        case DRONE_STATE_FLYING:
            printf("Drone is flying.\n");
            break;
        case DRONE_STATE_LANDING:
            printf("Drone is landing.\n");
            break;
        case DRONE_STATE_CRASHED:
            printf("Drone has crashed.\n");
            break;
    }
}

// Print the drone's response to the last command.
void drone_print_response(struct drone *drone) {
    switch (drone->response) {
        case DRONE_RESPONSE_OK:
            printf("Drone responded with OK.\n");
            break;
        case DRONE_RESPONSE_ERROR:
            printf("Drone responded with ERROR.\n");
            break;
        case DRONE_RESPONSE_CRASHED:
            printf("Drone responded with CRASHED.\n");
            break;
    }
}

// The main function.
int main() {
    // Create a new drone.
    struct drone *drone = drone_create();

    // Send a command to the drone.
    drone_send_command(drone, DRONE_COMMAND_TAKE_OFF);

    // Update the drone's state.
    drone_update(drone);

    // Get the drone's response to the last command.
    enum drone_response response = drone_get_response(drone);

    // Print the drone's state.
    drone_print_state(drone);

    // Print the drone's response to the last command.
    drone_print_response(drone);

    // Destroy the drone.
    drone_destroy(drone);

    return 0;
}