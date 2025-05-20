//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// data structure for elevator
typedef struct {
    int current_floor;
    int direction; // 1 for up, -1 for down, 0 for stationary
    int num_passengers;
    int max_passengers;
    int *passengers; // array of passenger destinations
} Elevator;

// initialize elevator
void init_elevator(Elevator *elevator, int max_passengers) {
    elevator->current_floor = 1;
    elevator->direction = 0;
    elevator->num_passengers = 0;
    elevator->max_passengers = max_passengers;
    elevator->passengers = (int*) malloc(sizeof(int) * max_passengers);
}

// move elevator
void move_elevator(Elevator *elevator) {
    if (elevator->direction == 1) { // going up
        elevator->current_floor++;
    } else if (elevator->direction == -1) { // going down
        elevator->current_floor--;
    }
    printf("Elevator is now at floor %d\n", elevator->current_floor);
}

// add passenger to elevator
void add_passenger(Elevator *elevator, int destination) {
    if (elevator->num_passengers < elevator->max_passengers) {
        elevator->passengers[elevator->num_passengers++] = destination;
        printf("Passenger added to elevator, going to floor %d\n", destination);
    } else {
        printf("Elevator is full, cannot add passenger\n");
    }
}

int main() {
    Elevator elevator;
    init_elevator(&elevator, 10); // initialize elevator with maximum capacity of 10 passengers

    // simulate elevator movement
    for (int i = 1; i <= 5; i++) { // go up 5 floors
        elevator.direction = 1;
        move_elevator(&elevator);
    }
    for (int i = 1; i <= 10; i++) { // add 10 passengers going to random floors
        add_passenger(&elevator, rand() % 10 + 1);
    }
    for (int i = 1; i <= 5; i++) { // go down 5 floors
        elevator.direction = -1;
        move_elevator(&elevator);
    }

    free(elevator.passengers); // free memory allocated for passengers array
    return 0;
}