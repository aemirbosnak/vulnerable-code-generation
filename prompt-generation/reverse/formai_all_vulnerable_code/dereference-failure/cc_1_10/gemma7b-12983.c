//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define NUM_FLOORS 5

// Define a structure to represent a floor
typedef struct Floor {
    int floor_number;
    struct Floor* next_floor;
} Floor;

// Create a linked list of floors
Floor* create_floor_list() {
    Floor* head = (Floor*)malloc(sizeof(Floor));
    head->floor_number = 1;
    head->next_floor = NULL;

    Floor* current = head;
    for (int i = 2; i <= NUM_FLOORS; i++) {
        current->next_floor = (Floor*)malloc(sizeof(Floor));
        current = current->next_floor;
        current->floor_number = i;
        current->next_floor = NULL;
    }

    return head;
}

// Simulate the elevator movement
void simulate_elevator(Floor* floor_list) {
    int current_floor = 1;
    int target_floor = 0;

    // Get the target floor from the user
    printf("Enter the target floor: ");
    scanf("%d", &target_floor);

    // Move the elevator to the target floor
    while (current_floor != target_floor) {
        // Check if the elevator is going up or down
        if (current_floor < target_floor) {
            current_floor++;
            printf("Going up to floor %d...\n", current_floor);
        } else if (current_floor > target_floor) {
            current_floor--;
            printf("Going down to floor %d...\n", current_floor);
        }
    }

    // Reach the target floor
    printf("Reached floor %d!\n", target_floor);
}

int main() {
    Floor* floor_list = create_floor_list();
    simulate_elevator(floor_list);

    return 0;
}