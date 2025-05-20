//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: mind-bending
// A journey into the mind-bending world of traffic flow simulation

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid dimensions
#define WIDTH 100
#define HEIGHT 100

// Vehicle parameters
#define MAX_SPEED 10
#define MIN_SPEED 1
#define MAX_ROTATIONS 100

// Simulation parameters
#define NUM_VEHICLES 100
#define TIME_STEPS 1000

// Vehicle data structure
typedef struct vehicle {
    int x, y;       // Position
    int dx, dy;     // Velocity
    int rotations;  // Number of rotations since last lane change
} vehicle;

// Initialize the grid
void init_grid(vehicle *vehicles) {
    for (int i = 0; i < NUM_VEHICLES; i++) {
        vehicles[i].x = rand() % WIDTH;
        vehicles[i].y = rand() % HEIGHT;
        vehicles[i].dx = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
        vehicles[i].dy = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
        vehicles[i].rotations = 0;
    }
}

// Update the grid
void update_grid(vehicle *vehicles) {
    for (int i = 0; i < NUM_VEHICLES; i++) {
        // Update position
        vehicles[i].x += vehicles[i].dx;
        vehicles[i].y += vehicles[i].dy;

        // Handle edge cases
        if (vehicles[i].x < 0) {
            vehicles[i].x = WIDTH - 1;
        } else if (vehicles[i].x >= WIDTH) {
            vehicles[i].x = 0;
        }
        if (vehicles[i].y < 0) {
            vehicles[i].y = HEIGHT - 1;
        } else if (vehicles[i].y >= HEIGHT) {
            vehicles[i].y = 0;
        }

        // Lane change logic
        if (vehicles[i].rotations++ >= MAX_ROTATIONS) {
            // Choose a random direction to turn
            int turn = rand() % 4;
            switch (turn) {
                case 0: // Left
                    if (vehicles[i].dx > MIN_SPEED) {
                        vehicles[i].dx--;
                    }
                    break;
                case 1: // Right
                    if (vehicles[i].dx < MAX_SPEED) {
                        vehicles[i].dx++;
                    }
                    break;
                case 2: // Up
                    if (vehicles[i].dy > MIN_SPEED) {
                        vehicles[i].dy--;
                    }
                    break;
                case 3: // Down
                    if (vehicles[i].dy < MAX_SPEED) {
                        vehicles[i].dy++;
                    }
                    break;
            }

            // Reset rotation count
            vehicles[i].rotations = 0;
        }
    }
}

// Print the grid
void print_grid(vehicle *vehicles) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf(" ");
            for (int i = 0; i < NUM_VEHICLES; i++) {
                if (vehicles[i].x == x && vehicles[i].y == y) {
                    printf("X");
                    break;
                }
            }
        }
        printf("\n");
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Allocate memory for the vehicles
    vehicle *vehicles = malloc(sizeof(vehicle) * NUM_VEHICLES);

    // Initialize the grid
    init_grid(vehicles);

    // Run the simulation
    for (int i = 0; i < TIME_STEPS; i++) {
        // Update the grid
        update_grid(vehicles);

        // Print the grid
        print_grid(vehicles);
    }

    // Free the memory
    free(vehicles);

    return 0;
}