//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Define the states of the vehicle
#define STOPPED 0
#define FORWARD 1
#define BACKWARD 2
#define TURN_LEFT 3
#define TURN_RIGHT 4

// Define the structure of the vehicle
typedef struct {
    int state;
    int speed;
    int direction;
} Vehicle;

// Function to initialize the vehicle
Vehicle* init_vehicle() {
    Vehicle* v = (Vehicle*) malloc(sizeof(Vehicle));
    v->state = STOPPED;
    v->speed = 0;
    v->direction = 0;
    return v;
}

// Function to move the vehicle forward
void move_forward(Vehicle* v) {
    v->direction = 0;
    v->speed = 10;
    v->state = FORWARD;
}

// Function to move the vehicle backward
void move_backward(Vehicle* v) {
    v->direction = 180;
    v->speed = 10;
    v->state = BACKWARD;
}

// Function to turn the vehicle left
void turn_left(Vehicle* v) {
    v->direction = 90;
    v->speed = 10;
    v->state = TURN_LEFT;
}

// Function to turn the vehicle right
void turn_right(Vehicle* v) {
    v->direction = 270;
    v->speed = 10;
    v->state = TURN_RIGHT;
}

// Function to stop the vehicle
void stop_vehicle(Vehicle* v) {
    v->speed = 0;
    v->state = STOPPED;
}

// Function to update the position of the vehicle
void update_position(Vehicle* v) {
    if(v->state == FORWARD) {
        printf("Vehicle is moving forward.\n");
    }
    else if(v->state == BACKWARD) {
        printf("Vehicle is moving backward.\n");
    }
    else if(v->state == TURN_LEFT) {
        printf("Vehicle is turning left.\n");
    }
    else if(v->state == TURN_RIGHT) {
        printf("Vehicle is turning right.\n");
    }
    else {
        printf("Vehicle is stopped.\n");
    }
}

int main() {
    Vehicle* v = init_vehicle();

    move_forward(v);
    update_position(v);

    turn_left(v);
    update_position(v);

    move_backward(v);
    update_position(v);

    turn_right(v);
    update_position(v);

    stop_vehicle(v);
    update_position(v);

    return 0;
}