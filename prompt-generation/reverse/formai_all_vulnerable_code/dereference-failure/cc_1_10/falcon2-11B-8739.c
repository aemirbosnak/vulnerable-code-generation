//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define constants for the maximum and minimum values for the X and Y coordinates
#define MAX_X 100
#define MAX_Y 100
#define MIN_X -MAX_X
#define MIN_Y -MAX_Y

// Define a structure to represent the vehicle
typedef struct {
    int x;
    int y;
    int speed;
} Vehicle;

// Define a function to initialize a new vehicle
Vehicle* init_vehicle(int x, int y, int speed) {
    Vehicle* v = (Vehicle*) malloc(sizeof(Vehicle));
    v->x = x;
    v->y = y;
    v->speed = speed;
    return v;
}

// Define a function to move the vehicle in the X direction
void move_x(Vehicle* v, int x_increment) {
    v->x += x_increment;
}

// Define a function to move the vehicle in the Y direction
void move_y(Vehicle* v, int y_increment) {
    v->y += y_increment;
}

// Define a function to change the speed of the vehicle
void set_speed(Vehicle* v, int new_speed) {
    v->speed = new_speed;
}

// Define a function to display the current position and speed of the vehicle
void print_vehicle(Vehicle* v) {
    printf("X: %d, Y: %d, Speed: %d\n", v->x, v->y, v->speed);
}

int main() {
    // Create a new vehicle
    Vehicle* v = init_vehicle(0, 0, 10);

    // Move the vehicle in the X direction
    move_x(v, 10);

    // Move the vehicle in the Y direction
    move_y(v, 10);

    // Change the speed of the vehicle
    set_speed(v, 20);

    // Print the current position and speed of the vehicle
    print_vehicle(v);

    // Clean up the memory allocated for the vehicle
    free(v);

    return 0;
}