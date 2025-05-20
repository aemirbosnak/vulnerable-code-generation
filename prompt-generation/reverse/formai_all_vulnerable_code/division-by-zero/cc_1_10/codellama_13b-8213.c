//Code Llama-13B DATASET v1.0 Category: Elevator Simulation ; Style: immersive
/*
 * Elevator Simulation
 *
 * This program simulates the operation of an elevator in a building. It allows the user to input the number of floors in the building, the number of elevators, and the number of passengers per elevator. It then simulates the elevator's movement and passenger load, and outputs the results.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 100
#define MAX_ELEVATORS 10
#define MAX_PASSENGERS 10

struct Elevator {
    int current_floor;
    int destination_floor;
    int passenger_count;
    int status; // 0 = idle, 1 = moving up, 2 = moving down
};

struct Passenger {
    int floor;
    int destination_floor;
};

void print_elevator_status(struct Elevator *elevator) {
    printf("Elevator %d: current floor = %d, destination floor = %d, passenger count = %d\n", elevator->status, elevator->current_floor, elevator->destination_floor, elevator->passenger_count);
}

void simulate_elevator_movement(struct Elevator *elevator, struct Passenger *passengers, int num_passengers) {
    int i, j;

    // Move the elevator to the destination floor
    elevator->current_floor = elevator->destination_floor;

    // Add passengers to the elevator
    for (i = 0; i < num_passengers; i++) {
        if (passengers[i].destination_floor == elevator->current_floor) {
            elevator->passenger_count++;
        }
    }

    // Remove passengers from the elevator
    for (i = 0; i < num_passengers; i++) {
        if (passengers[i].destination_floor != elevator->current_floor && passengers[i].floor == elevator->current_floor) {
            elevator->passenger_count--;
        }
    }
}

void simulate_elevator_operation(struct Elevator *elevators, struct Passenger *passengers, int num_elevators, int num_floors, int num_passengers) {
    int i, j;

    // Initialize the elevators
    for (i = 0; i < num_elevators; i++) {
        elevators[i].current_floor = 0;
        elevators[i].destination_floor = 0;
        elevators[i].passenger_count = 0;
        elevators[i].status = 0;
    }

    // Initialize the passengers
    for (i = 0; i < num_passengers; i++) {
        passengers[i].floor = rand() % num_floors;
        passengers[i].destination_floor = rand() % num_floors;
    }

    // Simulate the elevator operation
    for (i = 0; i < num_floors; i++) {
        for (j = 0; j < num_elevators; j++) {
            simulate_elevator_movement(&elevators[j], &passengers[i], num_passengers);
        }
    }
}

int main() {
    int num_floors, num_elevators, num_passengers;
    struct Elevator elevators[MAX_ELEVATORS];
    struct Passenger passengers[MAX_PASSENGERS];

    // Get user input
    printf("Enter the number of floors: ");
    scanf("%d", &num_floors);
    printf("Enter the number of elevators: ");
    scanf("%d", &num_elevators);
    printf("Enter the number of passengers: ");
    scanf("%d", &num_passengers);

    // Simulate the elevator operation
    simulate_elevator_operation(elevators, passengers, num_elevators, num_floors, num_passengers);

    // Print the results
    for (int i = 0; i < num_elevators; i++) {
        print_elevator_status(&elevators[i]);
    }

    return 0;
}