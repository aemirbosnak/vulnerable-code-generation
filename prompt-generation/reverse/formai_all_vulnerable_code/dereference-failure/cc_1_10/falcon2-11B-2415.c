//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[20];
    int floor;
    int direction;
} elevator;

typedef struct {
    int floor;
    elevator* elevator_array;
} elevator_simulation;

int main() {
    elevator_simulation elevator_sim;

    // Initialize elevator_simulation
    elevator_sim.floor = 0;
    elevator_sim.elevator_array = (elevator*)malloc(10 * sizeof(elevator));

    // Populate elevator_array with dummy elevators
    for (int i = 0; i < 10; i++) {
        elevator_sim.elevator_array[i].id = i;
        elevator_sim.elevator_array[i].name[0] = 'E';
        elevator_sim.elevator_array[i].name[1] = 'L';
        elevator_sim.elevator_array[i].name[2] = 'V';
        elevator_sim.elevator_array[i].floor = i;
        elevator_sim.elevator_array[i].direction = 0;
    }

    // Simulation loop
    while (1) {
        // Get user input
        printf("Enter your floor (0-9): ");
        int user_input = scanf("%d", &elevator_sim.floor);

        // Check if input is valid
        if (user_input!= 0) {
            printf("Invalid input, please try again.\n");
            continue;
        }

        // Find elevator to serve user
        int elevator_id = -1;
        for (int i = 0; i < 10; i++) {
            if (elevator_sim.elevator_array[i].floor == elevator_sim.floor) {
                elevator_id = i;
                break;
            }
        }

        // Check if elevator exists
        if (elevator_id == -1) {
            printf("No elevator available on this floor.\n");
            continue;
        }

        // Update elevator direction
        elevator_sim.elevator_array[elevator_id].direction = 1;

        // Move elevator
        if (elevator_sim.floor > elevator_sim.elevator_array[elevator_id].floor) {
            elevator_sim.floor--;
            elevator_sim.elevator_array[elevator_id].floor++;
        } else if (elevator_sim.floor < elevator_sim.elevator_array[elevator_id].floor) {
            elevator_sim.floor++;
            elevator_sim.elevator_array[elevator_id].floor--;
        }

        // Update elevator direction
        elevator_sim.elevator_array[elevator_id].direction = 0;

        // Print elevator status
        printf("Elevator %s is moving to floor %d\n", elevator_sim.elevator_array[elevator_id].name, elevator_sim.floor);
    }

    return 0;
}