//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of floors
#define NUM_FLOORS 10

// Define the elevator floor structure
typedef struct Floor {
    int current_floor;
    int target_floor;
    struct Floor* next_floor;
} Floor;

// Create a linked list of floors
Floor* create_floor_list() {
    Floor* head = malloc(sizeof(Floor));
    head->current_floor = 0;
    head->target_floor = -1;
    head->next_floor = NULL;

    return head;
}

// Move the elevator to the target floor
void move_elevator(Floor* floor_list) {
    Floor* current_floor = floor_list;

    while (current_floor->current_floor != current_floor->target_floor) {
        current_floor->current_floor++;

        // Simulate elevator movement
        printf("Elevator moving to floor %d...\n", current_floor->current_floor);

        sleep(1);
    }

    current_floor->current_floor = current_floor->target_floor;

    printf("Elevator stopped at floor %d.\n", current_floor->current_floor);
}

int main() {
    // Create a linked list of floors
    Floor* floor_list = create_floor_list();

    // Set the target floor
    floor_list->target_floor = 5;

    // Move the elevator
    move_elevator(floor_list);

    return 0;
}