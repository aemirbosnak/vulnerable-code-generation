//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_VEHICLES 5
#define COMMAND_SIZE 20

// Structure to represent a vehicle
typedef struct {
    char name[20];
    int position_x;
    int position_y;
} Vehicle;

// Function to initialize vehicles
void initialize_vehicles(Vehicle vehicles[], int count) {
    for (int i = 0; i < count; i++) {
        snprintf(vehicles[i].name, sizeof(vehicles[i].name), "Vehicle-%d", i + 1);
        vehicles[i].position_x = 0;
        vehicles[i].position_y = 0;
    }
}

// Function to display the current position of the vehicles
void display_positions(Vehicle vehicles[], int count) {
    printf("\nCurrent Positions:\n");
    for (int i = 0; i < count; i++) {
        printf("%s -> Position: (%d, %d)\n", vehicles[i].name, vehicles[i].position_x, vehicles[i].position_y);
    }
    printf("\n");
}

// Function to move a vehicle based on input command
void move_vehicle(Vehicle *vehicle, const char *command) {
    if (strcmp(command, "UP") == 0) {
        vehicle->position_y += 1;
    } else if (strcmp(command, "DOWN") == 0) {
        vehicle->position_y -= 1;
    } else if (strcmp(command, "LEFT") == 0) {
        vehicle->position_x -= 1;
    } else if (strcmp(command, "RIGHT") == 0) {
        vehicle->position_x += 1;
    } else {
        printf("Invalid command: %s\n", command);
    }
    display_positions(&vehicle, 1);
}

int main() {
    Vehicle vehicles[MAX_VEHICLES];
    int vehicle_count = MAX_VEHICLES;
    char command[COMMAND_SIZE];

    // Initialize vehicles
    initialize_vehicles(vehicles, vehicle_count);

    printf("Welcome to the Remote Control Vehicle Simulator!\n");
    printf("Use commands: UP, DOWN, LEFT, RIGHT to move your vehicles.\n");
    printf("Type 'EXIT' to quit the simulation.\n");

    // Simulation loop
    while (1) {
        display_positions(vehicles, vehicle_count);
        printf("Enter command for Vehicle-1 (or type EXIT): ");
        scanf("%s", command);
        
        if (strcmp(command, "EXIT") == 0) {
            printf("Exiting the simulation. Goodbye!\n");
            break;
        }

        // Move the first vehicle for simplicity, extend as necessary
        move_vehicle(&vehicles[0], command);
    }

    return 0;
}