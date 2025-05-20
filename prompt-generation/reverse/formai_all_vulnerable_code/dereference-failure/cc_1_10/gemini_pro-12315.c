//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize the elevator's state
enum elevator_state { IDLE, UP, DOWN };
struct elevator {
    int current_floor;
    enum elevator_state state;
    int destination_floor;
};

// Initialize the passengers' states
enum passenger_state { WAITING, BOARDED, EXITING };
struct passenger {
    int start_floor;
    int destination_floor;
    enum passenger_state state;
};

// Initialize the building's state
struct building {
    int num_floors;
    struct elevator elevator;
    struct passenger* passengers;
};

// Create a new building
struct building* create_building(int num_floors) {
    struct building* building = malloc(sizeof(struct building));
    building->num_floors = num_floors;
    building->elevator.current_floor = 1;
    building->elevator.state = IDLE;
    building->elevator.destination_floor = 0;
    building->passengers = malloc(sizeof(struct passenger) * num_floors);
    for (int i = 0; i < num_floors; i++) {
        building->passengers[i].start_floor = i;
        building->passengers[i].destination_floor = rand() % num_floors;
        building->passengers[i].state = WAITING;
    }
    return building;
}

// Update the elevator's state
void update_elevator(struct building* building) {
    switch (building->elevator.state) {
        case IDLE:
            if (building->passengers[building->elevator.current_floor].state == WAITING) {
                building->elevator.state = UP;
                building->elevator.destination_floor = building->passengers[building->elevator.current_floor].destination_floor;
            }
            break;
        case UP:
            if (building->elevator.current_floor == building->elevator.destination_floor) {
                building->elevator.state = DOWN;
                building->elevator.destination_floor = 1;
            } else {
                building->elevator.current_floor++;
            }
            break;
        case DOWN:
            if (building->elevator.current_floor == building->elevator.destination_floor) {
                building->elevator.state = IDLE;
            } else {
                building->elevator.current_floor--;
            }
            break;
    }
}

// Update the passengers' states
void update_passengers(struct building* building) {
    for (int i = 0; i < building->num_floors; i++) {
        switch (building->passengers[i].state) {
            case WAITING:
                if (building->elevator.current_floor == building->passengers[i].start_floor) {
                    building->passengers[i].state = BOARDED;
                }
                break;
            case BOARDED:
                if (building->elevator.current_floor == building->passengers[i].destination_floor) {
                    building->passengers[i].state = EXITING;
                }
                break;
            case EXITING:
                if (building->elevator.current_floor == 1) {
                    building->passengers[i].state = WAITING;
                }
                break;
        }
    }
}

// Print the building's state
void print_building(struct building* building) {
    printf("Current floor: %d\n", building->elevator.current_floor);
    printf("Elevator state: %s\n", building->elevator.state == IDLE ? "IDLE" : building->elevator.state == UP ? "UP" : "DOWN");
    printf("Passengers:\n");
    for (int i = 0; i < building->num_floors; i++) {
        printf("  - Floor %d: %s\n", building->passengers[i].start_floor, building->passengers[i].state == WAITING ? "WAITING" : building->passengers[i].state == BOARDED ? "BOARDED" : "EXITING");
    }
}

// Run the elevator simulation
void run_simulation(struct building* building, int num_iterations) {
    for (int i = 0; i < num_iterations; i++) {
        update_elevator(building);
        update_passengers(building);
        print_building(building);
    }
}

// Free the memory allocated for the building
void free_building(struct building* building) {
    free(building->passengers);
    free(building);
}

// Main function
int main() {
    // Create a new building
    struct building* building = create_building(10);

    // Run the elevator simulation
    run_simulation(building, 100);

    // Free the memory allocated for the building
    free_building(building);

    return 0;
}