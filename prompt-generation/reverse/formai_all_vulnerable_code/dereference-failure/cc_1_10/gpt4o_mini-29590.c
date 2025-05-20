//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10

typedef struct Passenger {
    int from_floor;
    int to_floor;
    struct Passenger* next;
} Passenger;

typedef struct Elevator {
    int current_floor;
    Passenger* passenger_list;
} Elevator;

void initialize_elevator(Elevator* elevator) {
    elevator->current_floor = 0; // Starting at ground floor
    elevator->passenger_list = NULL;
}

void add_passenger(Elevator* elevator, int from_floor, int to_floor) {
    Passenger* new_passenger = (Passenger*)malloc(sizeof(Passenger));
    new_passenger->from_floor = from_floor;
    new_passenger->to_floor = to_floor;
    new_passenger->next = elevator->passenger_list;
    elevator->passenger_list = new_passenger;
}

void serve_passenger(Elevator* elevator, Passenger* passenger) {
    printf("Current Floor: %d\n", elevator->current_floor);
    printf("Serving passenger from floor %d to floor %d\n", passenger->from_floor, passenger->to_floor);
    
    // Simulate moving up to the passenger's floor
    while (elevator->current_floor < passenger->from_floor) {
        elevator->current_floor++;
        printf("Moving up: Currently at floor %d\n", elevator->current_floor);
    }
    
    // Simulate picking up the passenger
    printf("Picked up a passenger at floor %d\n", elevator->current_floor);
    
    // Now move to the destination floor
    while (elevator->current_floor < passenger->to_floor) {
        elevator->current_floor++;
        printf("Moving up: Currently at floor %d\n", elevator->current_floor);
    }
    
    printf("Dropped off passenger at floor %d\n", elevator->current_floor);
}

void operate_elevator(Elevator* elevator, Passenger* passenger) {
    if (passenger == NULL) return; // Base case: no more passengers

    serve_passenger(elevator, passenger);
    operate_elevator(elevator, passenger->next); // Recursive call
}

void cleanup_passengers(Passenger* passenger) {
    if (passenger == NULL) return; // Base case: no passengers to clean up
    cleanup_passengers(passenger->next);
    free(passenger);
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);
    
    // Simulation: adding passengers
    add_passenger(&elevator, 2, 5);
    add_passenger(&elevator, 0, 3);
    add_passenger(&elevator, 4, 7);
    add_passenger(&elevator, 1, 6);
    
    printf("Elevator Simulation Started:\n");
    operate_elevator(&elevator, elevator.passenger_list);
    
    // Cleanup passengers after serving
    cleanup_passengers(elevator.passenger_list);
    
    return 0;
}