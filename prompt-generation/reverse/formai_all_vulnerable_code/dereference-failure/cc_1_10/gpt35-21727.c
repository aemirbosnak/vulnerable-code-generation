//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: intelligent
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/* Define the floor structure */
typedef struct Floor {
    int number;
    bool up_button;
    bool down_button;
} Floor;

/* Define the elevator structure */
typedef struct Elevator {
    int current_floor;
    int destination_floor;
    bool direction_up;
    bool doors_open;
} Elevator;

/* Define the building structure */
typedef struct Building {
    int num_floors;
    Floor *floors;
    Elevator elevator;
} Building;

/* Function to initialize the floors of the building */
void init_floors(Building *building) {
    for (int i = 0; i < building->num_floors; i++) {
        building->floors[i].number = i;
        building->floors[i].up_button = (i < building->num_floors - 1);
        building->floors[i].down_button = (i > 0);
    }
}

/* Function to move the elevator up or down one floor */
void move_elevator(Building *building) {
    if (building->elevator.direction_up) { // moving up
        building->elevator.current_floor++;
    } else { // moving down
        building->elevator.current_floor--;
    }

    // Check if elevator has reached destination floor
    if (building->elevator.current_floor == building->elevator.destination_floor) {
        building->elevator.doors_open = true;
        printf("Elevator doors opening on floor %d.\n", building->elevator.current_floor);
        // Reset the up/down buttons on the current floor
        building->floors[building->elevator.current_floor].up_button = false;
        building->floors[building->elevator.current_floor].down_button = false;
    }
}

/* Function to handle an elevator request from a floor */
void handle_request(Building *building, int requested_floor, bool direction_up) {
    printf("Request received from floor %d for elevator going ", requested_floor);
    if (direction_up) {
        printf("up.\n");
    } else {
        printf("down.\n");
    }
    // Set the appropriate up/down button on the requested floor
    if (direction_up) {
        building->floors[requested_floor].up_button = true;
    } else {
        building->floors[requested_floor].down_button = true;
    }

    // If the elevator is currently idle, go to the requested floor
    if (building->elevator.current_floor == requested_floor && building->elevator.doors_open) {
        building->elevator.doors_open = false;
        return;
    }

    // If the elevator is not currently idle, check if it should change direction to go to the requested floor
    if (building->elevator.current_floor > requested_floor && !building->elevator.direction_up) {
        building->elevator.direction_up = false;
        building->elevator.destination_floor = requested_floor;
    } else if (building->elevator.current_floor < requested_floor && building->elevator.direction_up) {
        building->elevator.direction_up = true;
        building->elevator.destination_floor = requested_floor;
    }
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the building
    Building building;
    building.num_floors = 10;
    building.floors = (Floor*) malloc(sizeof(Floor) * building.num_floors);
    building.elevator.current_floor = 0;
    building.elevator.destination_floor = 0;
    building.elevator.direction_up = true;
    building.elevator.doors_open = false;
    init_floors(&building);

    // Simulate elevator requests
    for (int i = 0; i < 100; i++) {
        int requested_floor = rand() % building.num_floors;
        bool direction_up = rand() % 2;
        handle_request(&building, requested_floor, direction_up);

        // Move the elevator if necessary
        if (!building.elevator.doors_open) {
            move_elevator(&building);
        }
    }

    // Free memory
    free(building.floors);

    return 0;
}