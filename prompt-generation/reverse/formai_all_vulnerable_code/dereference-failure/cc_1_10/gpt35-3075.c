//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define NUM_FLOORS 5
#define NUM_ELEVATORS 2

typedef struct {
    int current_floor;
    int direction;
    int passengers;
} elevator_t;

void print_state(elevator_t elevators[NUM_ELEVATORS], int total_passengers) {
    printf("Total passengers: %d\n", total_passengers);
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printf("Elevator %d: Floor %d, Direction %d, Passengers %d\n", i,
               elevators[i].current_floor, elevators[i].direction, elevators[i].passengers);
    }
    printf("\n");
}

void move_elevator(elevator_t *elevator) {
    if (elevator->direction == 1) {
        elevator->current_floor++;
        if (elevator->current_floor == NUM_FLOORS) {
            elevator->direction = -1;
        }
    } else {
        elevator->current_floor--;
        if (elevator->current_floor == 0) {
            elevator->direction = 1;
        }
    }
}

void load_elevator(elevator_t *elevator, int *floor_passengers, int max_passengers) {
    int available_space = max_passengers - elevator->passengers;
    int num_pickups = floor_passengers[elevator->current_floor];
    while (available_space > 0 && num_pickups > 0) {
        elevator->passengers++;
        floor_passengers[elevator->current_floor]--;
        num_pickups--;
        available_space--;
    }
}

void unload_elevator(elevator_t *elevator, int *floor_passengers) {
    int passengers_to_remove = 0;
    if (floor_passengers[elevator->current_floor] > 0) {
        passengers_to_remove = elevator->passengers;
        floor_passengers[elevator->current_floor] += passengers_to_remove;
        elevator->passengers = 0;
    }
}

int simulate(elevator_t elevators[NUM_ELEVATORS], int floor_passengers[NUM_FLOORS][2]) {
    int total_passengers = 0;
    for (int i = 0; i < NUM_FLOORS; i++) {
        total_passengers += floor_passengers[i][0] + floor_passengers[i][1];
    }

    if (total_passengers == 0) {
        return 0;
    }

    for (int i = 0; i < NUM_ELEVATORS; i++) {
        load_elevator(&elevators[i], floor_passengers[elevators[i].current_floor], 10);
        unload_elevator(&elevators[i], floor_passengers[elevators[i].current_floor]);
        move_elevator(&elevators[i]);
    }

    print_state(elevators, total_passengers);
    return simulate(elevators, floor_passengers);
}

int main() {
    int floor_passengers[NUM_FLOORS][2] = {{5, 0}, {0, 10}, {15, 5}, {3, 4}, {0, 7}};
    elevator_t elevators[NUM_ELEVATORS] = {{0, 1, 0}, {NUM_FLOORS - 1, -1, 0}};

    simulate(elevators, floor_passengers);

    return 0;
}