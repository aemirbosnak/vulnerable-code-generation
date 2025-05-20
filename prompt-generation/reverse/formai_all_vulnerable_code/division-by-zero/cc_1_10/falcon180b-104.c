//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3
#define ELEVATOR_SPEED 2
#define PASSENGER_WAIT_TIME 5
#define ELEVATOR_WAIT_TIME 10
#define MAX_PASSENGERS 8

typedef struct {
    int floor;
    int destination;
    int elevator;
} Passenger;

typedef struct {
    int floor;
    int direction;
    int elevator;
} Elevator;

void initialize_elevators(Elevator* elevators) {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].floor = rand() % NUM_FLOORS;
        elevators[i].direction = rand() % 2;
        elevators[i].elevator = i;
    }
}

void simulate(Passenger* passengers, Elevator* elevators, int num_passengers, int num_elevators) {
    int passenger_count = 0;
    int elevator_count = 0;
    int elevator_request_count = 0;

    while (passenger_count < num_passengers) {
        int passenger_floor = rand() % NUM_FLOORS;
        int passenger_elevator = rand() % num_elevators;

        if (passenger_floor == elevators[passenger_elevator].floor) {
            passenger_count++;
            elevators[passenger_elevator].floor = rand() % NUM_FLOORS;
        }
    }

    while (elevator_count < num_elevators) {
        int elevator_floor = rand() % NUM_FLOORS;
        int elevator_direction = rand() % 2;
        int elevator_passengers = 0;

        for (int i = 0; i < num_passengers; i++) {
            if (passengers[i].floor == elevator_floor && passengers[i].destination == elevator_floor) {
                elevator_passengers++;
            }
        }

        if (elevator_passengers > 0) {
            elevator_request_count++;
            elevators[elevator_count].floor = elevator_floor;
            elevators[elevator_count].direction = elevator_direction;
            elevators[elevator_count].elevator = elevator_count;
            elevator_count++;
        }
    }

    printf("Elevator requests: %d\n", elevator_request_count);
}

int main() {
    srand(time(NULL));

    Passenger passengers[MAX_PASSENGERS];
    Elevator elevators[NUM_ELEVATORS];

    int num_passengers = rand() % MAX_PASSENGERS;
    int num_elevators = rand() % NUM_ELEVATORS;

    for (int i = 0; i < num_passengers; i++) {
        passengers[i].floor = rand() % NUM_FLOORS;
        passengers[i].destination = rand() % NUM_FLOORS;
    }

    initialize_elevators(elevators);

    simulate(passengers, elevators, num_passengers, num_elevators);

    return 0;
}