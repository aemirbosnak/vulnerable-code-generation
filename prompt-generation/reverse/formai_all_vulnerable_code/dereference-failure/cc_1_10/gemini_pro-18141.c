//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the elevator's state
#define UP 1
#define DOWN -1
#define IDLE 0

// Define the maximum number of floors
#define MAX_FLOORS 10

// Define the maximum number of passengers
#define MAX_PASSENGERS 10

// Define the structure of a passenger
typedef struct {
    int floor;
    int direction;
} passenger_t;

// Define the structure of the elevator
typedef struct {
    int floor;
    int state;
    int num_passengers;
    passenger_t passengers[MAX_PASSENGERS];
} elevator_t;

// Create a new elevator
elevator_t *elevator_new() {
    elevator_t *elevator = malloc(sizeof(elevator_t));
    elevator->floor = 1;
    elevator->state = IDLE;
    elevator->num_passengers = 0;
    return elevator;
}

// Free the elevator
void elevator_free(elevator_t *elevator) {
    free(elevator);
}

// Add a passenger to the elevator
void elevator_add_passenger(elevator_t *elevator, passenger_t passenger) {
    elevator->passengers[elevator->num_passengers] = passenger;
    elevator->num_passengers++;
}

// Remove a passenger from the elevator
void elevator_remove_passenger(elevator_t *elevator, int passenger_index) {
    for (int i = passenger_index; i < elevator->num_passengers - 1; i++) {
        elevator->passengers[i] = elevator->passengers[i + 1];
    }
    elevator->num_passengers--;
}

// Update the elevator's state
void elevator_update(elevator_t *elevator) {
    // If the elevator is idle, then it should move to the next floor with a waiting passenger.
    if (elevator->state == IDLE) {
        for (int i = 0; i < MAX_FLOORS; i++) {
            if (elevator->passengers[i].floor != 0) {
                elevator->floor = i;
                elevator->state = elevator->passengers[i].direction;
                break;
            }
        }
    }

    // If the elevator is moving, then it should stop at the next floor with a waiting passenger.
    else if (elevator->state == UP || elevator->state == DOWN) {
        for (int i = elevator->floor + elevator->state; i >= 1 && i <= MAX_FLOORS; i += elevator->state) {
            if (elevator->passengers[i].floor != 0) {
                elevator->floor = i;
                elevator->state = IDLE;
                break;
            }
        }
    }
}

// Print the elevator's state
void elevator_print(elevator_t *elevator) {
    printf("Floor: %d\n", elevator->floor);
    printf("State: %s\n", elevator->state == UP ? "Up" : elevator->state == DOWN ? "Down" : "Idle");
    printf("Passengers: %d\n", elevator->num_passengers);
    for (int i = 0; i < elevator->num_passengers; i++) {
        printf("  - Floor: %d, Direction: %s\n", elevator->passengers[i].floor, elevator->passengers[i].direction == UP ? "Up" : "Down");
    }
}

// Main function
int main() {
    // Create a new elevator
    elevator_t *elevator = elevator_new();

    // Add some passengers to the elevator
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        passenger_t passenger;
        passenger.floor = rand() % MAX_FLOORS + 1;
        passenger.direction = rand() % 2 == 0 ? UP : DOWN;
        elevator_add_passenger(elevator, passenger);
    }

    // Print the initial state of the elevator
    elevator_print(elevator);

    // Update the elevator's state 10 times
    for (int i = 0; i < 10; i++) {
        elevator_update(elevator);

        // Print the elevator's state
        printf("\n");
        elevator_print(elevator);
    }

    // Free the elevator
    elevator_free(elevator);

    return 0;
}