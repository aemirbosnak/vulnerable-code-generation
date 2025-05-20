//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Elevator states
enum elevator_state {
    IDLE,
    MOVING_UP,
    MOVING_DOWN
};

// Elevator data structure
typedef struct elevator {
    int current_floor;
    enum elevator_state state;
    int destination_floor;
    int num_passengers;
    int max_passengers;
} elevator_t;

// Building data structure
typedef struct building {
    int num_floors;
    elevator_t* elevators;
    int num_elevators;
} building_t;

// Initialize elevator
void elevator_init(elevator_t* elevator, int current_floor, int max_passengers) {
    elevator->current_floor = current_floor;
    elevator->state = IDLE;
    elevator->destination_floor = -1;
    elevator->num_passengers = 0;
    elevator->max_passengers = max_passengers;
}

// Initialize building
void building_init(building_t* building, int num_floors, int num_elevators, int max_passengers) {
    building->num_floors = num_floors;
    building->num_elevators = num_elevators;
    building->elevators = malloc(sizeof(elevator_t) * num_elevators);
    for (int i = 0; i < num_elevators; i++) {
        elevator_init(&building->elevators[i], 0, max_passengers);
    }
}

// Request elevator
void request_elevator(building_t* building, int floor) {
    // Find the closest idle elevator
    int closest_elevator = -1;
    int min_distance = building->num_floors;
    for (int i = 0; i < building->num_elevators; i++) {
        elevator_t* elevator = &building->elevators[i];
        if (elevator->state == IDLE) {
            int distance = abs(elevator->current_floor - floor);
            if (distance < min_distance) {
                closest_elevator = i;
                min_distance = distance;
            }
        }
    }

    // If no idle elevator found, choose the one with the fewest passengers
    if (closest_elevator == -1) {
        closest_elevator = 0;
        int min_passengers = building->elevators[0].num_passengers;
        for (int i = 1; i < building->num_elevators; i++) {
            elevator_t* elevator = &building->elevators[i];
            if (elevator->num_passengers < min_passengers) {
                closest_elevator = i;
                min_passengers = elevator->num_passengers;
            }
        }
    }

    // Send the elevator to the requested floor
    elevator_t* elevator = &building->elevators[closest_elevator];
    elevator->destination_floor = floor;
    elevator->state = MOVING_UP;
}

// Update elevator
void update_elevator(elevator_t* elevator) {
    // Move elevator to the next floor
    if (elevator->state == MOVING_UP) {
        elevator->current_floor++;
        if (elevator->current_floor == elevator->destination_floor) {
            elevator->state = IDLE;
        }
    } else if (elevator->state == MOVING_DOWN) {
        elevator->current_floor--;
        if (elevator->current_floor == elevator->destination_floor) {
            elevator->state = IDLE;
        }
    }
}

// Update building
void update_building(building_t* building) {
    // Update each elevator
    for (int i = 0; i < building->num_elevators; i++) {
        elevator_t* elevator = &building->elevators[i];
        update_elevator(elevator);
    }
}

// Print building status
void print_building_status(building_t* building) {
    printf("Building status:\n");
    for (int i = building->num_floors - 1; i >= 0; i--) {
        printf("Floor %d: ", i);
        for (int j = 0; j < building->num_elevators; j++) {
            elevator_t* elevator = &building->elevators[j];
            if (elevator->current_floor == i) {
                printf("E%d (%d)", j, elevator->num_passengers);
            }
        }
        printf("\n");
    }
}

int main() {
    // Initialize building
    building_t building;
    building_init(&building, 10, 3, 5);

    // Request elevators
    request_elevator(&building, 5);
    request_elevator(&building, 2);
    request_elevator(&building, 7);

    // Update building
    for (int i = 0; i < 10; i++) {
        update_building(&building);
        print_building_status(&building);
    }

    return 0;
}