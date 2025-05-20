//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Define the number of floors
#define NUM_FLOORS 10

// Define the elevator floor structure
typedef struct Floor {
    int current_floor;
    int target_floor;
    struct Floor* next;
} Floor;

// Create the elevator
Floor* create_elevator() {
    Floor* elevator = malloc(sizeof(Floor));
    elevator->current_floor = 1;
    elevator->target_floor = 0;
    elevator->next = NULL;
    return elevator;
}

// Move the elevator to the target floor
void move_elevator(Floor* elevator) {
    int current_floor = elevator->current_floor;
    int target_floor = elevator->target_floor;

    // Check if the elevator is already on the target floor
    if (current_floor == target_floor) {
        return;
    }

    // Calculate the direction of movement
    int direction = target_floor - current_floor;

    // Move the elevator one floor at a time
    for (int i = 0; i < direction; i++) {
        elevator->current_floor++;
        printf("The elevator is on floor %d.\n", elevator->current_floor);
    }

    // The elevator has reached the target floor
    elevator->current_floor = target_floor;
}

int main() {
    // Create the elevator
    Floor* elevator = create_elevator();

    // Set the target floor
    elevator->target_floor = 5;

    // Move the elevator
    move_elevator(elevator);

    // Print the final floor
    printf("The elevator is on floor %d.\n", elevator->current_floor);

    return 0;
}