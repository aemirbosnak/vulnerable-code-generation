//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Elevator states
enum elevator_state {
    IDLE,
    MOVING_UP,
    MOVING_DOWN,
    DOOR_OPEN
};

// Elevator directions
enum elevator_direction {
    UP,
    DOWN
};

// Elevator structure
struct elevator {
    int current_floor;
    int destination_floor;
    enum elevator_state state;
    enum elevator_direction direction;
};

// Create a new elevator
struct elevator* create_elevator() {
    struct elevator* elevator = malloc(sizeof(struct elevator));
    elevator->current_floor = 0;
    elevator->destination_floor = 0;
    elevator->state = IDLE;
    elevator->direction = UP;
    return elevator;
}

// Destroy an elevator
void destroy_elevator(struct elevator* elevator) {
    free(elevator);
}

// Move the elevator up one floor
void move_elevator_up(struct elevator* elevator) {
    if (elevator->state == IDLE) {
        elevator->state = MOVING_UP;
        elevator->current_floor++;
    }
}

// Move the elevator down one floor
void move_elevator_down(struct elevator* elevator) {
    if (elevator->state == IDLE) {
        elevator->state = MOVING_DOWN;
        elevator->current_floor--;
    }
}

// Open the elevator doors
void open_elevator_doors(struct elevator* elevator) {
    if (elevator->state == IDLE) {
        elevator->state = DOOR_OPEN;
    }
}

// Close the elevator doors
void close_elevator_doors(struct elevator* elevator) {
    if (elevator->state == DOOR_OPEN) {
        elevator->state = IDLE;
    }
}

// Print the elevator's status
void print_elevator_status(struct elevator* elevator) {
    printf("Current floor: %d\n", elevator->current_floor);
    printf("Destination floor: %d\n", elevator->destination_floor);
    printf("State: ");
    switch (elevator->state) {
        case IDLE:
            printf("Idle\n");
            break;
        case MOVING_UP:
            printf("Moving up\n");
            break;
        case MOVING_DOWN:
            printf("Moving down\n");
            break;
        case DOOR_OPEN:
            printf("Door open\n");
            break;
    }
    printf("Direction: ");
    switch (elevator->direction) {
        case UP:
            printf("Up\n");
            break;
        case DOWN:
            printf("Down\n");
            break;
    }
}

// Simulate the elevator
void simulate_elevator(struct elevator* elevator) {
    while (1) {
        // Check if the elevator is at its destination floor
        if (elevator->current_floor == elevator->destination_floor) {
            // Open the elevator doors
            open_elevator_doors(elevator);
            // Wait for a few seconds
            sleep(1);
            // Close the elevator doors
            close_elevator_doors(elevator);
            // Set the elevator's state to IDLE
            elevator->state = IDLE;
        } else {
            // Move the elevator in the appropriate direction
            if (elevator->direction == UP) {
                move_elevator_up(elevator);
            } else {
                move_elevator_down(elevator);
            }
        }
        // Print the elevator's status
        print_elevator_status(elevator);
    }
}

int main() {
    // Create a new elevator
    struct elevator* elevator = create_elevator();
    // Simulate the elevator
    simulate_elevator(elevator);
    // Destroy the elevator
    destroy_elevator(elevator);
    return 0;
}