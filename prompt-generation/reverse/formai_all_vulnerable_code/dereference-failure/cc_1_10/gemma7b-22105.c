//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Define the number of floors
#define NUM_FLOORS 5

// Define the elevator floor structure
typedef struct Floor {
    int current_floor;
    int target_floor;
    struct Floor* next;
} Floor;

// Create the elevator
Floor* create_elevator() {
    Floor* elevator = (Floor*)malloc(sizeof(Floor));
    elevator->current_floor = 1;
    elevator->target_floor = 0;
    elevator->next = NULL;
    return elevator;
}

// Move the elevator to the target floor
void move_elevator(Floor* elevator) {
    int target_floor = elevator->target_floor;
    while (elevator->current_floor != target_floor) {
        if (elevator->current_floor < target_floor) {
            elevator->current_floor++;
        } else if (elevator->current_floor > target_floor) {
            elevator->current_floor--;
        }
    }
}

// Simulate the elevator
int main() {
    // Create the elevator
    Floor* elevator = create_elevator();

    // Set the target floor
    elevator->target_floor = 3;

    // Move the elevator
    move_elevator(elevator);

    // Print the current floor
    printf("The elevator is on floor %d.\n", elevator->current_floor);

    return 0;
}