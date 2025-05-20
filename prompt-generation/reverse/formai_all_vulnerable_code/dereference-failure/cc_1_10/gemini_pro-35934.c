//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Remote control car struct
typedef struct {
    int speed;
    int direction;
} Car;

// Create a new remote control car
Car* create_car(int speed, int direction) {
    Car* car = malloc(sizeof(Car));
    car->speed = speed;
    car->direction = direction;
    return car;
}

// Destroy a remote control car
void destroy_car(Car* car) {
    free(car);
}

// Set the speed of a remote control car
void set_speed(Car* car, int speed) {
    car->speed = speed;
}

// Set the direction of a remote control car
void set_direction(Car* car, int direction) {
    car->direction = direction;
}

// Drive a remote control car
void drive_car(Car* car) {
    printf("Driving the car at speed %d in direction %d\n", car->speed, car->direction);
}

// Main function
int main() {
    // Create a new remote control car
    Car* car = create_car(0, 0);

    // Set the speed of the car
    set_speed(car, 10);

    // Set the direction of the car
    set_direction(car, 90);

    // Drive the car
    drive_car(car);

    // Destroy the car
    destroy_car(car);

    return 0;
}