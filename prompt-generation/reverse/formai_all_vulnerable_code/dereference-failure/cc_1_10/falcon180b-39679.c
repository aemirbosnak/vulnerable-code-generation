//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 4

// Define the structure of an elevator
typedef struct {
    int current_floor;
    int destination_floor;
    int direction;
    int passengers;
} Elevator;

// Function to initialize the elevator
Elevator* initialize_elevator(int start_floor) {
    Elevator* elevator = (Elevator*) malloc(sizeof(Elevator));
    elevator->current_floor = start_floor;
    elevator->destination_floor = start_floor;
    elevator->direction = 1;
    elevator->passengers = 0;

    return elevator;
}

// Function to move the elevator
void move_elevator(Elevator* elevator) {
    if (elevator->direction == 1) {
        elevator->current_floor++;
    } else {
        elevator->current_floor--;
    }
}

// Function to add passengers to the elevator
void add_passengers(Elevator* elevator, int num_passengers) {
    if (elevator->passengers + num_passengers <= MAX_PASSENGERS) {
        elevator->passengers += num_passengers;
    }
}

// Function to remove passengers from the elevator
void remove_passengers(Elevator* elevator, int num_passengers) {
    if (elevator->passengers >= num_passengers) {
        elevator->passengers -= num_passengers;
    }
}

// Function to print the current state of the elevator
void print_elevator(Elevator* elevator) {
    printf("Elevator: ");
    printf("Current floor: %d\n", elevator->current_floor);
    printf("Destination floor: %d\n", elevator->destination_floor);
    printf("Direction: %s\n", elevator->direction == 1? "Up" : "Down");
    printf("Passengers: %d\n", elevator->passengers);
}

// Function to simulate the elevator for a given number of floors
void simulate_elevator(Elevator* elevator, int num_floors) {
    int i;
    for (i = 0; i < num_floors; i++) {
        move_elevator(elevator);
        printf("Floor %d reached.\n", elevator->current_floor);
        if (elevator->destination_floor == elevator->current_floor) {
            printf("Elevator has reached its destination.\n");
            break;
        }
    }
}

int main() {
    srand(time(NULL));

    Elevator* elevator = initialize_elevator(rand() % MAX_FLOORS + 1);

    int num_passengers = rand() % MAX_PASSENGERS + 1;
    add_passengers(elevator, num_passengers);

    int num_floors = rand() % MAX_FLOORS + 1;
    int destination_floor = rand() % MAX_FLOORS + 1;
    elevator->destination_floor = destination_floor;

    printf("Simulating elevator with %d passengers and %d floors...\n", num_passengers, num_floors);
    simulate_elevator(elevator, num_floors);

    remove_passengers(elevator, num_passengers);
    free(elevator);

    return 0;
}