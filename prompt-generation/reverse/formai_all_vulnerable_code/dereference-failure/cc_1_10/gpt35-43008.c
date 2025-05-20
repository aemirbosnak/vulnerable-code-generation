//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// struct defining the vehicle
typedef struct {
    int x;
    int y;
    char direction;
} Vehicle;

// function to create the vehicle
Vehicle* createVehicle() {
    srand(time(NULL));
    Vehicle* v = (Vehicle*) malloc(sizeof(Vehicle));
    v->x = rand() % COLS;
    v->y = rand() % ROWS;
    v->direction = 'N';
    return v;
}

// function to move the vehicle
void moveVehicle(Vehicle* v, char direction) {
    if(direction == 'N') {
        if(v->y > 0) {
            v->y--;
        } else {
            printf("Cannot move North any further.\n");
        }
    } else if(direction == 'S') {
        if(v->y < ROWS - 1) {
            v->y++;
        } else {
            printf("Cannot move South any further.\n");
        }
    } else if(direction == 'E') {
        if(v->x < COLS - 1) {
            v->x++;
        } else {
            printf("Cannot move East any further.\n");
        }
    } else if(direction == 'W') {
        if(v->x > 0) {
            v->x--;
        } else {
            printf("Cannot move West any further.\n");
        }
    } else {
        printf("Invalid direction.\n");
    }
    v->direction = direction;
}

// function to display the vehicle's current position and direction
void displayVehicle(Vehicle* v) {
    printf("Vehicle is currently at position (%d,%d) facing %c.\n", v->x, v->y, v->direction);
}

int main() {
    // create the vehicle
    Vehicle* v = createVehicle();

    // test moving the vehicle in different directions
    displayVehicle(v);
    moveVehicle(v, 'N');
    displayVehicle(v);
    moveVehicle(v, 'E');
    displayVehicle(v);
    moveVehicle(v, 'S');
    displayVehicle(v);
    moveVehicle(v, 'W');
    displayVehicle(v);

    // free the vehicle memory
    free(v);

    return 0;
}