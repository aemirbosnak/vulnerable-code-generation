//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Declare the remote control vehicle struct
typedef struct car {
    int speed;
    int direction;
} car_t;

// Create a new remote control vehicle
car_t* create_car() {
    car_t* car = malloc(sizeof(car_t));
    car->speed = 0;
    car->direction = 0;
    return car;
}

// Destroy the remote control vehicle
void destroy_car(car_t* car) {
    free(car);
}

// Set the speed of the remote control vehicle
void set_speed(car_t* car, int speed) {
    car->speed = speed;
}

// Get the speed of the remote control vehicle
int get_speed(car_t* car) {
    return car->speed;
}

// Set the direction of the remote control vehicle
void set_direction(car_t* car, int direction) {
    car->direction = direction;
}

// Get the direction of the remote control vehicle
int get_direction(car_t* car) {
    return car->direction;
}

// Move the remote control vehicle forward
void move_forward(car_t* car) {
    if (car->speed > 0) {
        car->direction += car->speed;
    }
}

// Move the remote control vehicle backward
void move_backward(car_t* car) {
    if (car->speed > 0) {
        car->direction -= car->speed;
    }
}

// Turn the remote control vehicle left
void turn_left(car_t* car) {
    car->direction--;
}

// Turn the remote control vehicle right
void turn_right(car_t* car) {
    car->direction++;
}

// Print the current state of the remote control vehicle
void print_car_state(car_t* car) {
    printf("Speed: %d\n", car->speed);
    printf("Direction: %d\n", car->direction);
}

// Main function
int main() {
    // Create a new remote control vehicle
    car_t* car = create_car();

    // Set the speed of the remote control vehicle
    set_speed(car, 10);

    // Set the direction of the remote control vehicle
    set_direction(car, 90);

    // Move the remote control vehicle forward
    move_forward(car);

    // Turn the remote control vehicle left
    turn_left(car);

    // Move the remote control vehicle backward
    move_backward(car);

    // Turn the remote control vehicle right
    turn_right(car);

    // Print the current state of the remote control vehicle
    print_car_state(car);

    // Destroy the remote control vehicle
    destroy_car(car);

    return 0;
}