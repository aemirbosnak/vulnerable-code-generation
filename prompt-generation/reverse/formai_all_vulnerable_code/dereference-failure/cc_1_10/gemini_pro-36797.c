//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Elevator states
enum ElevatorState {
    ES_IDLE,
    ES_MOVING_UP,
    ES_MOVING_DOWN,
    ES_DOOR_OPEN
};

// Elevator directions
enum ElevatorDirection {
    ED_UP,
    ED_DOWN
};

// Floor states
enum FloorState {
    FS_IDLE,
    FS_WAITING_UP,
    FS_WAITING_DOWN
};

// Elevator
struct Elevator {
    int current_floor;
    enum ElevatorState state;
    enum ElevatorDirection direction;
    int destination_floor;
};

// Floor
struct Floor {
    int number;
    enum FloorState state;
};

// Create an elevator
struct Elevator* create_elevator() {
    struct Elevator* elevator = malloc(sizeof(struct Elevator));
    elevator->current_floor = 0;
    elevator->state = ES_IDLE;
    elevator->direction = ED_UP;
    elevator->destination_floor = -1;
    return elevator;
}

// Create a floor
struct Floor* create_floor(int number) {
    struct Floor* floor = malloc(sizeof(struct Floor));
    floor->number = number;
    floor->state = FS_IDLE;
    return floor;
}

// Add a passenger to the elevator
void add_passenger(struct Elevator* elevator, int destination_floor) {
    elevator->destination_floor = destination_floor;
    if (elevator->state == ES_IDLE) {
        elevator->state = ES_MOVING_UP;
    }
}

// Move the elevator
void move_elevator(struct Elevator* elevator) {
    if (elevator->state == ES_IDLE) {
        return;
    }
    if (elevator->state == ES_MOVING_UP) {
        elevator->current_floor++;
    } else if (elevator->state == ES_MOVING_DOWN) {
        elevator->current_floor--;
    }
    if (elevator->current_floor == elevator->destination_floor) {
        elevator->state = ES_DOOR_OPEN;
    }
}

// Print the elevator status
void print_elevator_status(struct Elevator* elevator) {
    printf("Elevator status:\n");
    printf("  Current floor: %d\n", elevator->current_floor);
    printf("  State: ");
    switch (elevator->state) {
        case ES_IDLE:
            printf("Idle\n");
            break;
        case ES_MOVING_UP:
            printf("Moving up\n");
            break;
        case ES_MOVING_DOWN:
            printf("Moving down\n");
            break;
        case ES_DOOR_OPEN:
            printf("Door open\n");
            break;
    }
    printf("  Destination floor: %d\n", elevator->destination_floor);
}

// Main function
int main() {
    // Create an elevator
    struct Elevator* elevator = create_elevator();

    // Add some passengers
    add_passenger(elevator, 3);
    add_passenger(elevator, 5);
    add_passenger(elevator, 1);

    // Move the elevator
    while (elevator->state != ES_IDLE) {
        move_elevator(elevator);
        print_elevator_status(elevator);
    }

    return 0;
}