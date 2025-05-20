//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Declare the vehicle struct
typedef struct {
    int x;
    int y;
    int angle;
} Vehicle;

// Declare the remote control struct
typedef struct {
    int up;
    int down;
    int left;
    int right;
} RemoteControl;

// Declare the function to create a new vehicle
Vehicle* create_vehicle() {
    Vehicle* vehicle = malloc(sizeof(Vehicle));
    vehicle->x = 0;
    vehicle->y = 0;
    vehicle->angle = 0;
    return vehicle;
}

// Declare the function to create a new remote control
RemoteControl* create_remote_control() {
    RemoteControl* remote_control = malloc(sizeof(RemoteControl));
    remote_control->up = 0;
    remote_control->down = 0;
    remote_control->left = 0;
    remote_control->right = 0;
    return remote_control;
}

// Declare the function to move the vehicle
void move_vehicle(Vehicle* vehicle, RemoteControl* remote_control) {
    if (remote_control->up) {
        vehicle->y += 1;
    } else if (remote_control->down) {
        vehicle->y -= 1;
    }
    if (remote_control->left) {
        vehicle->x -= 1;
    } else if (remote_control->right) {
        vehicle->x += 1;
    }
}

// Declare the function to turn the vehicle
void turn_vehicle(Vehicle* vehicle, RemoteControl* remote_control) {
    if (remote_control->left) {
        vehicle->angle -= 1;
    } else if (remote_control->right) {
        vehicle->angle += 1;
    }
}

// Declare the function to print the vehicle's status
void print_vehicle_status(Vehicle* vehicle) {
    printf("Vehicle status:\n");
    printf("x: %d\n", vehicle->x);
    printf("y: %d\n", vehicle->y);
    printf("angle: %d\n", vehicle->angle);
}

// Declare the main function
int main() {
    // Create a new vehicle and remote control
    Vehicle* vehicle = create_vehicle();
    RemoteControl* remote_control = create_remote_control();

    // Read the input from the user
    char input[10];
    while (1) {
        scanf("%s", input);

        // Check if the user wants to quit
        if (strcmp(input, "quit") == 0) {
            break;
        }

        // Check if the user wants to move the vehicle
        if (strcmp(input, "up") == 0) {
            remote_control->up = 1;
        } else if (strcmp(input, "down") == 0) {
            remote_control->down = 1;
        } else if (strcmp(input, "left") == 0) {
            remote_control->left = 1;
        } else if (strcmp(input, "right") == 0) {
            remote_control->right = 1;
        }

        // Check if the user wants to turn the vehicle
        if (strcmp(input, "turn left") == 0) {
            remote_control->left = 1;
        } else if (strcmp(input, "turn right") == 0) {
            remote_control->right = 1;
        }

        // Move the vehicle
        move_vehicle(vehicle, remote_control);

        // Turn the vehicle
        turn_vehicle(vehicle, remote_control);

        // Print the vehicle's status
        print_vehicle_status(vehicle);
    }

    // Free the memory allocated for the vehicle and remote control
    free(vehicle);
    free(remote_control);

    return 0;
}