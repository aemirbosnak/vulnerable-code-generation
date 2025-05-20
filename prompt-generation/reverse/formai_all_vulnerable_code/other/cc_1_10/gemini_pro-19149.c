//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_FLOORS 10
#define MAX_ELEVATORS 4

typedef struct {
    int floor;
    bool direction;  // true for up, false for down
    int num_passengers;
} elevator_t;

// Global variables
elevator_t elevators[MAX_ELEVATORS];
int num_floors;
int num_elevators;

// Function declarations
void init_elevators();
void print_elevators();
void move_elevators();
void handle_requests();

int main() {
    // Initialize the elevators
    init_elevators();

    // Print the initial state of the elevators
    print_elevators();

    while (true) {
        // Move the elevators
        move_elevators();

        // Handle any requests for elevator service
        handle_requests();

        // Print the current state of the elevators
        print_elevators();
    }

    return 0;
}

void init_elevators() {
    // Set the number of floors and elevators
    num_floors = 10;
    num_elevators = 4;

    // Initialize the elevators
    for (int i = 0; i < num_elevators; i++) {
        elevators[i].floor = 0;
        elevators[i].direction = true;  // all elevators start moving up initially
        elevators[i].num_passengers = 0;
    }
}

void print_elevators() {
    printf("Elevator Status:\n");
    for (int i = 0; i < num_elevators; i++) {
        printf("Elevator %d: floor %d, direction %s, passengers %d\n",
               i, elevators[i].floor, elevators[i].direction ? "up" : "down", elevators[i].num_passengers);
    }
}

void move_elevators() {
    // Move each elevator one floor in its current direction
    for (int i = 0; i < num_elevators; i++) {
        if (elevators[i].direction) {
            elevators[i].floor++;
        } else {
            elevators[i].floor--;
        }

        // If the elevator has reached the top or bottom floor, reverse its direction
        if (elevators[i].floor == num_floors - 1) {
            elevators[i].direction = false;
        } else if (elevators[i].floor == 0) {
            elevators[i].direction = true;
        }
    }
}

void handle_requests() {
    // Get the floor and direction of the requested elevator
    int floor, direction;
    printf("Enter floor and direction (up/down): ");
    scanf("%d %s", &floor, direction);

    // Find the nearest elevator that is moving in the requested direction
    int nearest_elevator = -1;
    int min_distance = num_floors;
    for (int i = 0; i < num_elevators; i++) {
        if (elevators[i].direction == direction) {
            int distance = abs(elevators[i].floor - floor);
            if (distance < min_distance) {
                nearest_elevator = i;
                min_distance = distance;
            }
        }
    }

    // If no elevator is moving in the requested direction, find the nearest elevator that is not moving
    if (nearest_elevator == -1) {
        for (int i = 0; i < num_elevators; i++) {
            if (elevators[i].direction == false) {
                int distance = abs(elevators[i].floor - floor);
                if (distance < min_distance) {
                    nearest_elevator = i;
                    min_distance = distance;
                }
            }
        }
    }

    assert(nearest_elevator != -1);  // There should always be at least one elevator available

    // Send the requested elevator to the requested floor
    elevators[nearest_elevator].floor = floor;
}