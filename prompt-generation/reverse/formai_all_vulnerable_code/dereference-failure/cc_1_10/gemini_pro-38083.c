//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the road length
#define ROAD_LENGTH 100

// Define the number of cars
#define NUM_CARS 10

// Define the maximum speed of cars
#define MAX_SPEED 10

// Define the probability of a car changing lanes
#define LANE_CHANGE_PROBABILITY 0.1

// Define the structure of a car
typedef struct car {
    int position;
    int speed;
    int lane;
} car;

// Initialize the cars
void init_cars(car *cars) {
    for (int i = 0; i < NUM_CARS; i++) {
        cars[i].position = rand() % ROAD_LENGTH;
        cars[i].speed = rand() % MAX_SPEED;
        cars[i].lane = rand() % 3;
    }
}

// Update the position of the cars
void update_cars(car *cars) {
    for (int i = 0; i < NUM_CARS; i++) {
        cars[i].position += cars[i].speed;

        // Check if the car has reached the end of the road
        if (cars[i].position >= ROAD_LENGTH) {
            cars[i].position = 0;
        }

        // Check if the car is too close to the car in front of it
        if (i > 0 && cars[i].position - cars[i - 1].position < cars[i].speed) {
            cars[i].speed = cars[i - 1].position - cars[i].position;
        }

        // Check if the car is changing lanes
        if (rand() < LANE_CHANGE_PROBABILITY) {
            int new_lane = rand() % 3;
            if (new_lane != cars[i].lane) {
                cars[i].lane = new_lane;
            }
        }
    }
}

// Print the state of the traffic
void print_traffic(car *cars) {
    for (int i = 0; i < ROAD_LENGTH; i++) {
        for (int j = 0; j < 3; j++) {
            int car_found = 0;
            for (int k = 0; k < NUM_CARS; k++) {
                if (cars[k].position == i && cars[k].lane == j) {
                    printf("C");
                    car_found = 1;
                    break;
                }
            }
            if (!car_found) {
                printf(" ");
            }
        }
    }
    printf("\n");
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the cars
    car cars[NUM_CARS];
    init_cars(cars);

    // Update the cars and print the state of the traffic
    while (1) {
        update_cars(cars);
        print_traffic(cars);
    }

    return 0;
}