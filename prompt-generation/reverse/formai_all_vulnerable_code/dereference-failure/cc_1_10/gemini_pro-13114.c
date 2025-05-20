//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Initialize the traffic light
typedef struct {
    int state; // 0 for red, 1 for green
    int timer; // Time remaining in current state
} TrafficLight;

void initializeTrafficLight(TrafficLight *light) {
    light->state = 0;
    light->timer = 5;
}

// Initialize the cars
typedef struct {
    int position; // Position in the queue
    int speed; // Speed in km/h
    bool isHonking; // Honking or not
} Car;

void initializeCar(Car *car) {
    car->position = 0;
    car->speed = 0;
    car->isHonking = false;
}

// Simulate the traffic flow
void simulateTrafficFlow(TrafficLight *light, Car **cars, int numCars) {
    int time = 0;

    while (true) {
        // Update the traffic light
        if (light->timer > 0) {
            light->timer--;
        } else {
            light->state = !light->state;
            light->timer = 5;
        }

        // Update the cars
        for (int i = 0; i < numCars; i++) {
            Car *car = cars[i];

            // Move the car forward if it can
            if (car->position < 100 && (light->state || car->position == 0)) {
                car->position += car->speed;
            }

            // Honk if the car is stopped
            if (car->position == 0) {
                car->isHonking = true;
            } else {
                car->isHonking = false;
            }
        }

        // Print the current state of the traffic flow
        printf("Time: %d\n", time);
        printf("Traffic light: %s\n", light->state ? "Green" : "Red");
        for (int i = 0; i < numCars; i++) {
            Car *car = cars[i];
            printf("Car %d: %d km/h, %s\n", i, car->speed, car->isHonking ? "Honking" : "Not honking");
        }
        printf("\n");

        // Increment the time
        time++;
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the traffic light
    TrafficLight light;
    initializeTrafficLight(&light);

    // Initialize the cars
    int numCars = 10;
    Car *cars[numCars];
    for (int i = 0; i < numCars; i++) {
        cars[i] = malloc(sizeof(Car));
        initializeCar(cars[i]);
        cars[i]->speed = rand() % 10 + 1; // Speed between 1 and 10 km/h
    }

    // Simulate the traffic flow
    simulateTrafficFlow(&light, cars, numCars);

    // Free the memory
    for (int i = 0; i < numCars; i++) {
        free(cars[i]);
    }

    return 0;
}