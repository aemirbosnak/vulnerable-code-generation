//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of floors
#define MAX_FLOORS 10

// Define the elevator floor structure
typedef struct Floor {
    int floor_number;
    struct Floor* next;
} Floor;

// Create a linked list of elevator floors
Floor* create_floor_list() {
    Floor* head = malloc(sizeof(Floor));
    head->floor_number = 1;
    head->next = NULL;

    Floor* tail = head;
    for (int i = 2; i <= MAX_FLOORS; i++) {
        tail->next = malloc(sizeof(Floor));
        tail = tail->next;
        tail->floor_number = i;
        tail->next = NULL;
    }

    return head;
}

// Simulate the elevator moving to a floor
void simulate_elevator(Floor* floor_list, int target_floor) {
    Floor* current_floor = floor_list;

    // Move the elevator to the target floor
    while (current_floor->floor_number != target_floor) {
        if (current_floor->next != NULL) {
            current_floor = current_floor->next;
        } else {
            printf("Error: The elevator has reached the top floor.\n");
            return;
        }
    }

    // Stop the elevator at the target floor
    printf("The elevator has stopped at floor %d.\n", target_floor);
}

int main() {
    // Create a linked list of elevator floors
    Floor* floor_list = create_floor_list();

    // Simulate the elevator moving to floor 5
    simulate_elevator(floor_list, 5);

    return 0;
}