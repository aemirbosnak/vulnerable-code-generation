//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Vehicle struct
typedef struct Vehicle {
    char *name;
    int speed;
    int direction;
} Vehicle;

// Remote control struct
typedef struct RemoteControl {
    Vehicle *vehicle;
    int throttle;
    int steering;
} RemoteControl;

// Create a new vehicle
Vehicle *create_vehicle(char *name) {
    Vehicle *vehicle = malloc(sizeof(Vehicle));
    vehicle->name = strdup(name);
    vehicle->speed = 0;
    vehicle->direction = 0;
    return vehicle;
}

// Create a new remote control
RemoteControl *create_remote_control(Vehicle *vehicle) {
    RemoteControl *remote_control = malloc(sizeof(RemoteControl));
    remote_control->vehicle = vehicle;
    remote_control->throttle = 0;
    remote_control->steering = 0;
    return remote_control;
}

// Set the throttle of the remote control
void set_throttle(RemoteControl *remote_control, int throttle) {
    remote_control->throttle = throttle;
}

// Set the steering of the remote control
void set_steering(RemoteControl *remote_control, int steering) {
    remote_control->steering = steering;
}

// Update the state of the vehicle based on the remote control inputs
void update_vehicle(Vehicle *vehicle, RemoteControl *remote_control) {
    // Update the speed of the vehicle
    vehicle->speed += remote_control->throttle;
    if (vehicle->speed < 0) {
        vehicle->speed = 0;
    } else if (vehicle->speed > 100) {
        vehicle->speed = 100;
    }

    // Update the direction of the vehicle
    vehicle->direction += remote_control->steering;
    if (vehicle->direction < 0) {
        vehicle->direction += 360;
    } else if (vehicle->direction > 360) {
        vehicle->direction -= 360;
    }
}

// Print the state of the vehicle
void print_vehicle(Vehicle *vehicle) {
    printf("Name: %s\n", vehicle->name);
    printf("Speed: %d\n", vehicle->speed);
    printf("Direction: %d\n", vehicle->direction);
}

// Main function
int main() {
    // Create a new vehicle
    Vehicle *vehicle = create_vehicle("Car");

    // Create a new remote control
    RemoteControl *remote_control = create_remote_control(vehicle);

    // Set the throttle and steering of the remote control
    set_throttle(remote_control, 50);
    set_steering(remote_control, 10);

    // Update the state of the vehicle
    update_vehicle(vehicle, remote_control);

    // Print the state of the vehicle
    print_vehicle(vehicle);

    // Free the memory allocated for the vehicle and remote control
    free(vehicle->name);
    free(vehicle);
    free(remote_control);

    return 0;
}