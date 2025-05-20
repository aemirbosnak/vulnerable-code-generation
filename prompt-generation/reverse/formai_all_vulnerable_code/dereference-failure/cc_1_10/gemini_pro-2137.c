//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CARS 100
#define MAX_LANES 4
#define MAX_ROAD_LENGTH 100

// The "car" struct represents a single car in the simulation.
struct car {
    // The position of the car on the road, in cells.
    int position;

    // The lane the car is in.
    int lane;

    // The speed of the car, in cells per tick.
    int speed;

    // The desired speed of the car, in cells per tick.
    int desired_speed;

    // Whether the car is braking.
    bool braking;
};

// The "road" struct represents the road in the simulation.
struct road {
    // The length of the road, in cells.
    int length;

    // The number of lanes on the road.
    int lanes;

    // The array of cars on the road.
    struct car *cars[MAX_CARS];
};

// The "simulation" struct represents the entire simulation.
struct simulation {
    // The road in the simulation.
    struct road road;

    // The current tick of the simulation.
    int tick;

    // Whether the simulation is running.
    bool running;
};

// Create a new simulation.
struct simulation *create_simulation(int length, int lanes) {
    // Allocate memory for the simulation.
    struct simulation *sim = malloc(sizeof(struct simulation));

    // Set the length and lanes of the road.
    sim->road.length = length;
    sim->road.lanes = lanes;

    // Initialize the road to be empty.
    for (int i = 0; i < MAX_CARS; i++) {
        sim->road.cars[i] = NULL;
    }

    // Set the current tick to 0.
    sim->tick = 0;

    // Set the simulation to be running.
    sim->running = true;

    // Return the simulation.
    return sim;
}

// Destroy a simulation.
void destroy_simulation(struct simulation *sim) {
    // Free the memory allocated for the simulation.
    free(sim);
}

// Add a car to the simulation.
void add_car(struct simulation *sim, int lane, int position, int speed) {
    // Find the first empty slot in the road.
    int i = 0;
    while (i < MAX_CARS && sim->road.cars[i] != NULL) {
        i++;
    }

    // If there is no empty slot, return.
    if (i == MAX_CARS) {
        return;
    }

    // Create a new car.
    struct car *car = malloc(sizeof(struct car));

    // Set the car's lane, position, and speed.
    car->lane = lane;
    car->position = position;
    car->speed = speed;
    car->desired_speed = speed;
    car->braking = false;

    // Add the car to the road.
    sim->road.cars[i] = car;
}

// Update the simulation.
void update_simulation(struct simulation *sim) {
    // For each car on the road...
    for (int i = 0; i < MAX_CARS; i++) {
        struct car *car = sim->road.cars[i];
        if (car == NULL) {
            continue;
        }

        // Calculate the car's desired speed.
        int desired_speed = car->desired_speed;

        // If the car is in the leftmost lane and there is a car in front of it...
        if (car->lane == 0 && sim->road.cars[i - 1] != NULL) {
            // Calculate the distance to the car in front.
            int distance = sim->road.cars[i - 1]->position - car->position;

            // If the distance is less than the car's desired speed, slow down.
            if (distance < desired_speed) {
                desired_speed = distance;
            }
        }

        // If the car is not in the leftmost lane and there is a car in the lane to the left...
        if (car->lane > 0 && sim->road.cars[i - sim->road.lanes] != NULL) {
            // Calculate the distance to the car in the lane to the left.
            int distance = sim->road.cars[i - sim->road.lanes]->position - car->position;

            // If the distance is less than the car's desired speed, slow down.
            if (distance < desired_speed) {
                desired_speed = distance;
            }
        }

        // If the car is braking, slow down.
        if (car->braking) {
            desired_speed = desired_speed / 2;
        }

        // Set the car's speed to the desired speed.
        car->speed = desired_speed;

        // Move the car forward.
        car->position += car->speed;

        // If the car has reached the end of the road, remove it from the simulation.
        if (car->position >= sim->road.length) {
            sim->road.cars[i] = NULL;
            free(car);
        }
    }

    // Increment the tick.
    sim->tick++;
}

// Draw the simulation.
void draw_simulation(struct simulation *sim) {
    // For each lane on the road...
    for (int lane = 0; lane < sim->road.lanes; lane++) {
        // Print the lane number.
        printf("Lane %d: ", lane);

        // For each car in the lane...
        for (int i = 0; i < MAX_CARS; i++) {
            struct car *car = sim->road.cars[i];
            if (car == NULL) {
                continue;
            }

            // If the car is in the lane...
            if (car->lane == lane) {
                // Print the car's position.
                printf("%d ", car->position);
            }
        }

        // Print a newline.
        printf("\n");
    }
}

// Main function.
int main() {
    // Create a new simulation.
    struct simulation *sim = create_simulation(MAX_ROAD_LENGTH, MAX_LANES);

    // Add some cars to the simulation.
    add_car(sim, 0, 0, 10);
    add_car(sim, 1, 20, 5);
    add_car(sim, 2, 40, 15);
    add_car(sim, 3, 60, 10);

    // Run the simulation.
    while (sim->running) {
        // Update the simulation.
        update_simulation(sim);

        // Draw the simulation.
        draw_simulation(sim);

        // Sleep for 100 milliseconds.
        sleep(100);
    }

    // Destroy the simulation.
    destroy_simulation(sim);

    return 0;
}