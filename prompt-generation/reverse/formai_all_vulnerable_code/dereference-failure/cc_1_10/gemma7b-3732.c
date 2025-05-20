//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define the elevator floor structure
typedef struct Floor {
    int floor_number;
    struct Floor* next;
} Floor;

// Create a function to simulate the elevator movement
void simulate_elevator(Floor* floor_list) {
    // Get the current floor number
    int current_floor = floor_list->floor_number;

    // Get the destination floor number
    int destination_floor = rand() % 10 + 1;

    // Check if the destination floor is above the current floor
    if (destination_floor > current_floor) {
        // Move up one floor at a time until the destination floor is reached
        for (int i = current_floor; i < destination_floor; i++) {
            printf("Elevator moving up to floor %d...\n", i);
            sleep(1);
        }
    } else {
        // Move down one floor at a time until the destination floor is reached
        for (int i = current_floor; i > destination_floor; i--) {
            printf("Elevator moving down to floor %d...\n", i);
            sleep(1);
        }
    }

    // Reach the destination floor
    printf("Elevator arrived at floor %d.\n", destination_floor);
}

int main() {
    // Create a linked list of elevator floors
    Floor* floor_list = malloc(sizeof(Floor));
    floor_list->floor_number = 1;
    floor_list->next = malloc(sizeof(Floor));
    floor_list->next->floor_number = 2;
    floor_list->next->next = malloc(sizeof(Floor));
    floor_list->next->next->floor_number = 3;

    // Simulate the elevator movement
    simulate_elevator(floor_list);

    return 0;
}