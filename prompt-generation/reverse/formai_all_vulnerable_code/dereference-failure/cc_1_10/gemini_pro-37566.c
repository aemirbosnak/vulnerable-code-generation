//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of cars that can be simulated
#define MAX_CARS 100

// Define the maximum number of lanes in a road
#define MAX_LANES 3

// Define the maximum speed of a car
#define MAX_SPEED 100

// Define the minimum speed of a car
#define MIN_SPEED 10

// Define the probability of a car changing lanes
#define LANE_CHANGE_PROBABILITY 0.1

// Define the probability of a car braking
#define BRAKING_PROBABILITY 0.05

// Define the time step for the simulation
#define TIME_STEP 1

// Define the structure of a car
typedef struct car {
    int id;
    int lane;
    int speed;
    bool is_braking;
} car;

// Define the structure of a road
typedef struct road {
    int num_lanes;
    car cars[MAX_CARS];
} road;

// Create a new car
car *create_car(int id, int lane, int speed) {
    car *new_car = (car *)malloc(sizeof(car));
    new_car->id = id;
    new_car->lane = lane;
    new_car->speed = speed;
    new_car->is_braking = false;
    return new_car;
}

// Create a new road
road *create_road(int num_lanes) {
    road *new_road = (road *)malloc(sizeof(road));
    new_road->num_lanes = num_lanes;
    for (int i = 0; i < MAX_CARS; i++) {
        new_road->cars[i] = *create_car(i, 0, 0);
    }
    return new_road;
}

// Update the state of a car
void update_car(car *car, road *road) {
    // Check if the car is braking
    if (car->is_braking) {
        // Decelerate the car
        car->speed -= 10;
        // If the car's speed is below the minimum speed, stop the car
        if (car->speed < MIN_SPEED) {
            car->speed = 0;
        }
    } else {
        // Accelerate the car
        car->speed += 10;
        // If the car's speed is above the maximum speed, limit the car's speed
        if (car->speed > MAX_SPEED) {
            car->speed = MAX_SPEED;
        }
    }

    // Check if the car is changing lanes
    if (rand() < LANE_CHANGE_PROBABILITY) {
        // Choose a random lane to change to
        int new_lane = rand() % road->num_lanes;
        // If the new lane is not the current lane, move the car to the new lane
        if (new_lane != car->lane) {
            car->lane = new_lane;
        }
    }

    // Check if the car is braking in front of the current car
    if (car->lane > 0 && road->cars[car->lane - 1].is_braking) {
        // Decelerate the car
        car->speed -= 10;
        // If the car's speed is below the minimum speed, stop the car
        if (car->speed < MIN_SPEED) {
            car->speed = 0;
        }
    }

    // Move the car forward
    car->lane += car->speed;
}

// Update the state of a road
void update_road(road *road) {
    // Update the state of each car
    for (int i = 0; i < MAX_CARS; i++) {
        update_car(&road->cars[i], road);
    }
}

// Print the state of a road
void print_road(road *road) {
    // Print the number of lanes
    printf("Number of lanes: %d\n", road->num_lanes);
    // Print the state of each car
    for (int i = 0; i < MAX_CARS; i++) {
        printf("Car %d: lane %d, speed %d, is_braking %d\n", road->cars[i].id, road->cars[i].lane, road->cars[i].speed, road->cars[i].is_braking);
    }
}

// Run the simulation
int main() {
    // Create a new road
    road *road = create_road(3);
    // Run the simulation for 100 time steps
    for (int i = 0; i < 100; i++) {
        // Update the state of the road
        update_road(road);
        // Print the state of the road
        print_road(road);
    }
    return 0;
}