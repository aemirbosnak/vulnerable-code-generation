//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define the number of floors in the elevator
#define NUM_FLOORS 10

// Define the elevator floor structure
typedef struct Floor {
    int floor_number;
    struct Floor* next;
} Floor;

// Create a linked list of elevator floors
Floor* create_floor_list() {
    Floor* head = NULL;
    for (int i = 0; i < NUM_FLOORS; i++) {
        Floor* new_floor = (Floor*)malloc(sizeof(Floor));
        new_floor->floor_number = i + 1;
        new_floor->next = head;
        head = new_floor;
    }
    return head;
}

// Simulate the elevator movement
void simulate_elevator(Floor* floor_list) {
    // Get the current floor
    int current_floor = floor_list->floor_number;

    // Get the destination floor
    int destination_floor = rand() % NUM_FLOORS + 1;

    // Move the elevator to the destination floor
    while (current_floor != destination_floor) {
        // Go up one floor
        if (current_floor < destination_floor) {
            current_floor++;
        }
        // Go down one floor
        else if (current_floor > destination_floor) {
            current_floor--;
        }
    }

    // Arrive at the destination floor
    printf("The elevator has arrived at floor %d.\n", destination_floor);
}

int main() {
    // Create the linked list of elevator floors
    Floor* floor_list = create_floor_list();

    // Simulate the elevator movement
    simulate_elevator(floor_list);

    return 0;
}