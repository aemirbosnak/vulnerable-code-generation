//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the vehicle's state
typedef struct {
    int x;
    int y;
    int direction; // 0 = north, 1 = east, 2 = south, 3 = west
} VehicleState;

// Define the remote control commands
typedef enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
} Command;

// Create a new vehicle state
VehicleState* create_vehicle_state(int x, int y, int direction) {
    VehicleState* state = malloc(sizeof(VehicleState));
    state->x = x;
    state->y = y;
    state->direction = direction;
    return state;
}

// Destroy a vehicle state
void destroy_vehicle_state(VehicleState* state) {
    free(state);
}

// Execute a command on a vehicle state
void execute_command(VehicleState* state, Command command) {
    switch (command) {
        case FORWARD:
            switch (state->direction) {
                case 0: // North
                    state->y++;
                    break;
                case 1: // East
                    state->x++;
                    break;
                case 2: // South
                    state->y--;
                    break;
                case 3: // West
                    state->x--;
                    break;
            }
            break;
        case BACKWARD:
            switch (state->direction) {
                case 0: // North
                    state->y--;
                    break;
                case 1: // East
                    state->x--;
                    break;
                case 2: // South
                    state->y++;
                    break;
                case 3: // West
                    state->x++;
                    break;
            }
            break;
        case LEFT:
            state->direction = (state->direction - 1 + 4) % 4;
            break;
        case RIGHT:
            state->direction = (state->direction + 1) % 4;
            break;
    }
}

// Print the vehicle's state
void print_vehicle_state(VehicleState* state) {
    printf("Vehicle state: (%d, %d), direction: %d\n", state->x, state->y, state->direction);
}

// Main function
int main() {
    // Create a new vehicle state
    VehicleState* state = create_vehicle_state(0, 0, 0);

    // Get a random sequence of commands
    srand(time(NULL));
    int num_commands = rand() % 10 + 1;
    Command commands[num_commands];
    for (int i = 0; i < num_commands; i++) {
        commands[i] = rand() % 4;
    }

    // Execute the commands
    for (int i = 0; i < num_commands; i++) {
        execute_command(state, commands[i]);
    }

    // Print the final vehicle state
    print_vehicle_state(state);

    // Destroy the vehicle state
    destroy_vehicle_state(state);

    return 0;
}