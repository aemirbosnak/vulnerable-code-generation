//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent an elevator
typedef struct {
    int current_floor;  // Current floor the elevator is on
    int destination_floor;  // Floor the elevator is going to
    bool is_moving;  // True if the elevator is moving, false otherwise
    int num_passengers;  // Number of passengers in the elevator
} Elevator;

// Structure to represent a passenger
typedef struct {
    int start_floor;  // Floor the passenger starts on
    int destination_floor;  // Floor the passenger wants to go to
} Passenger;

// Function to initialize an elevator
Elevator* init_elevator() {
    Elevator* elevator = (Elevator*)malloc(sizeof(Elevator));
    elevator->current_floor = 1;
    elevator->destination_floor = 1;
    elevator->is_moving = false;
    elevator->num_passengers = 0;
    return elevator;
}

// Function to add a passenger to an elevator
void add_passenger(Elevator* elevator, Passenger* passenger) {
    elevator->num_passengers++;
    // Update the elevator's destination floor if necessary
    if (passenger->destination_floor > elevator->destination_floor) {
        elevator->destination_floor = passenger->destination_floor;
    }
}

// Function to move the elevator one floor up
void move_elevator_up(Elevator* elevator) {
    if (elevator->current_floor < elevator->destination_floor) {
        elevator->current_floor++;
        elevator->is_moving = true;
    } else {
        elevator->is_moving = false;
    }
}

// Function to move the elevator one floor down
void move_elevator_down(Elevator* elevator) {
    if (elevator->current_floor > elevator->destination_floor) {
        elevator->current_floor--;
        elevator->is_moving = true;
    } else {
        elevator->is_moving = false;
    }
}

// Function to simulate the elevator moving
void simulate_elevator(Elevator* elevator) {
    while (elevator->is_moving) {
        if (elevator->current_floor < elevator->destination_floor) {
            move_elevator_up(elevator);
        } else if (elevator->current_floor > elevator->destination_floor) {
            move_elevator_down(elevator);
        } else {
            elevator->is_moving = false;
        }
    }
}

// Function to print the status of the elevator
void print_elevator_status(Elevator* elevator) {
    printf("Current floor: %d\n", elevator->current_floor);
    printf("Destination floor: %d\n", elevator->destination_floor);
    printf("Is moving: %s\n", elevator->is_moving ? "true" : "false");
    printf("Number of passengers: %d\n", elevator->num_passengers);
}

// Main function
int main() {
    // Initialize the elevator
    Elevator* elevator = init_elevator();

    // Add some passengers to the elevator
    Passenger* passenger1 = (Passenger*)malloc(sizeof(Passenger));
    passenger1->start_floor = 1;
    passenger1->destination_floor = 5;
    add_passenger(elevator, passenger1);

    Passenger* passenger2 = (Passenger*)malloc(sizeof(Passenger));
    passenger2->start_floor = 3;
    passenger2->destination_floor = 7;
    add_passenger(elevator, passenger2);

    // Simulate the elevator moving
    simulate_elevator(elevator);

    // Print the status of the elevator
    print_elevator_status(elevator);

    return 0;
}