//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the vehicle's initial state
struct Vehicle {
    int x;
    int y;
    int angle;
};

// Create a new vehicle
struct Vehicle* create_vehicle(int x, int y, int angle) {
    struct Vehicle* vehicle = malloc(sizeof(struct Vehicle));
    vehicle->x = x;
    vehicle->y = y;
    vehicle->angle = angle;
    return vehicle;
}

// Destroy the vehicle
void destroy_vehicle(struct Vehicle* vehicle) {
    free(vehicle);
}

// Move the vehicle forward
void move_forward(struct Vehicle* vehicle, int distance) {
    vehicle->x += distance * cos(vehicle->angle);
    vehicle->y += distance * sin(vehicle->angle);
}

// Move the vehicle backward
void move_backward(struct Vehicle* vehicle, int distance) {
    vehicle->x -= distance * cos(vehicle->angle);
    vehicle->y -= distance * sin(vehicle->angle);
}

// Turn the vehicle left
void turn_left(struct Vehicle* vehicle, int angle) {
    vehicle->angle -= angle;
}

// Turn the vehicle right
void turn_right(struct Vehicle* vehicle, int angle) {
    vehicle->angle += angle;
}

// Print the vehicle's state
void print_vehicle(struct Vehicle* vehicle) {
    printf("Vehicle is at (%d, %d) facing %d degrees.\n", vehicle->x, vehicle->y, vehicle->angle);
}

// Main function
int main() {
    // Create a new vehicle
    struct Vehicle* vehicle = create_vehicle(0, 0, 0);

    // Print the vehicle's initial state
    print_vehicle(vehicle);

    // Move the vehicle forward
    move_forward(vehicle, 10);

    // Turn the vehicle left
    turn_left(vehicle, 90);

    // Move the vehicle forward again
    move_forward(vehicle, 10);

    // Print the vehicle's final state
    print_vehicle(vehicle);

    // Destroy the vehicle
    destroy_vehicle(vehicle);

    return 0;
}