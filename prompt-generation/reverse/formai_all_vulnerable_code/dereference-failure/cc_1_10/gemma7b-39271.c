//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10

typedef struct elevator_floor {
    int floor_number;
    struct elevator_floor* next_floor;
} elevator_floor;

void simulate_elevator(elevator_floor* current_floor) {
    int target_floor;

    // Get the target floor from the user
    printf("Enter the target floor (1-10): ");
    scanf("%d", &target_floor);

    // Check if the target floor is within the range
    if (target_floor < 1 || target_floor > MAX_FLOORS) {
        printf("Error: Target floor out of range.\n");
        return;
    }

    // Move the elevator to the target floor
    while (current_floor->floor_number != target_floor) {
        // Go to the next floor
        current_floor = current_floor->next_floor;

        // Print the current floor number
        printf("Current floor: %d\n", current_floor->floor_number);
    }

    // Reach the target floor
    printf("Door opening on floor %d.\n", target_floor);
}

int main() {
    // Create the first floor
    elevator_floor* first_floor = malloc(sizeof(elevator_floor));
    first_floor->floor_number = 1;
    first_floor->next_floor = NULL;

    // Create the remaining floors
    elevator_floor* current_floor = first_floor;
    for (int i = 2; i <= MAX_FLOORS; i++) {
        current_floor->next_floor = malloc(sizeof(elevator_floor));
        current_floor = current_floor->next_floor;
        current_floor->floor_number = i;
        current_floor->next_floor = NULL;
    }

    // Simulate the elevator
    simulate_elevator(first_floor);

    return 0;
}