//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VEHICLES 100
#define MAX_SPEED 10
#define MIN_SPEED 1
#define MAX_ACCELERATION 2
#define MIN_ACCELERATION -1
#define MAX_DECELERATION -2
#define MIN_DECELERATION -1

typedef struct {
    int id;
    int speed;
    int acceleration;
    int deceleration;
    int position;
} vehicle;

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Create an array of vehicles
    vehicle vehicles[MAX_VEHICLES];

    // Initialize the vehicles
    for (int i = 0; i < MAX_VEHICLES; i++) {
        vehicles[i].id = i;
        vehicles[i].speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
        vehicles[i].acceleration = rand() % (MAX_ACCELERATION - MIN_ACCELERATION + 1) + MIN_ACCELERATION;
        vehicles[i].deceleration = rand() % (MAX_DECELERATION - MIN_DECELERATION + 1) + MIN_DECELERATION;
        vehicles[i].position = rand() % 100;
    }

    // Simulate the traffic flow
    for (int t = 0; t < 100; t++) {
        // Update the vehicles' positions
        for (int i = 0; i < MAX_VEHICLES; i++) {
            vehicles[i].position += vehicles[i].speed;
        }

        // Check for collisions
        for (int i = 0; i < MAX_VEHICLES; i++) {
            for (int j = i + 1; j < MAX_VEHICLES; j++) {
                if (vehicles[i].position == vehicles[j].position) {
                    // Collision occurred
                    printf("Collision between vehicles %d and %d at time %d\n", vehicles[i].id, vehicles[j].id, t);

                    // Update the vehicles' speeds and accelerations
                    vehicles[i].speed = 0;
                    vehicles[i].acceleration = 0;
                    vehicles[j].speed = 0;
                    vehicles[j].acceleration = 0;
                }
            }
        }

        // Update the vehicles' speeds and accelerations
        for (int i = 0; i < MAX_VEHICLES; i++) {
            // Check if the vehicle is approaching a slower vehicle
            int slow_vehicle = -1;
            for (int j = i + 1; j < MAX_VEHICLES; j++) {
                if (vehicles[j].position < vehicles[i].position && vehicles[j].speed < vehicles[i].speed) {
                    slow_vehicle = j;
                    break;
                }
            }

            // If there is a slower vehicle, decelerate
            if (slow_vehicle != -1) {
                vehicles[i].speed -= vehicles[i].deceleration;
            } else {
                // Accelerate if possible
                vehicles[i].speed += vehicles[i].acceleration;
            }

            // Ensure that the vehicle's speed does not exceed the maximum speed
            if (vehicles[i].speed > MAX_SPEED) {
                vehicles[i].speed = MAX_SPEED;
            }

            // Ensure that the vehicle's speed does not fall below the minimum speed
            if (vehicles[i].speed < MIN_SPEED) {
                vehicles[i].speed = MIN_SPEED;
            }
        }

        // Print the traffic flow
        printf("Time %d:\n", t);
        for (int i = 0; i < MAX_VEHICLES; i++) {
            printf("Vehicle %d: speed %d, position %d\n", vehicles[i].id, vehicles[i].speed, vehicles[i].position);
        }
    }

    return 0;
}