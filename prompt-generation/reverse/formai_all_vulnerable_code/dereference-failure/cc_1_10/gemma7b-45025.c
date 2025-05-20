//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define the number of floors
#define NUM_FLOORS 10

// Define the elevator floor structure
typedef struct Floor {
    int floor_number;
    struct Floor* next_floor;
} Floor;

// Create the elevator
Floor* elevator = NULL;

// Function to add a floor to the elevator
void add_floor(int floor_number) {
    Floor* new_floor = malloc(sizeof(Floor));
    new_floor->floor_number = floor_number;
    new_floor->next_floor = elevator;
    elevator = new_floor;
}

// Function to move the elevator to a floor
void move_elevator(int floor_number) {
    Floor* current_floor = elevator;
    while (current_floor->floor_number != floor_number) {
        current_floor = current_floor->next_floor;
    }
    elevator = current_floor;
}

// Main function
int main() {
    // Add floors to the elevator
    add_floor(1);
    add_floor(2);
    add_floor(3);
    add_floor(4);
    add_floor(5);
    add_floor(6);
    add_floor(7);
    add_floor(8);
    add_floor(9);
    add_floor(10);

    // Move the elevator to different floors
    move_elevator(3);
    move_elevator(8);
    move_elevator(1);

    // Print the current floor
    printf("The current floor is floor %d.\n", elevator->floor_number);

    return 0;
}