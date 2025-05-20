//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ROAD_LENGTH 50
#define NUM_CARS 5
#define MAX_VELOCITY 3

typedef struct {
    int position;
    int velocity;
} Car;

void initializeCars(Car cars[], int numCars) {
    for (int i = 0; i < numCars; i++) {
        cars[i].position = i * (ROAD_LENGTH / numCars);
        cars[i].velocity = 1 + rand() % MAX_VELOCITY; // Random speed between 1 and MAX_VELOCITY
    }
}

void updateCars(Car cars[], int numCars, int lightState) {
    for (int i = 0; i < numCars; i++) {
        if (lightState == 1 && cars[i].position < ROAD_LENGTH - 1) { // Green light
            cars[i].position += cars[i].velocity;
            if (cars[i].position >= ROAD_LENGTH) {
                cars[i].position = ROAD_LENGTH - 1; // Car can't go beyond the road
            }
        }
        // Simulating a stop if at a red light or if ahead car is too close
        if (lightState == 0 || (i > 0 && cars[i].position - cars[i - 1].position < 2)) {
            cars[i].velocity = 0; // Stop the car
        } else {
            cars[i].velocity = 1 + rand() % MAX_VELOCITY; // Random speed again
        }
    }
}

void printRoad(Car cars[], int numCars) {
    char road[ROAD_LENGTH + 1];
    for (int i = 0; i < ROAD_LENGTH; i++) {
        road[i] = '.';
    }
    road[ROAD_LENGTH] = '\0';
    
    for (int i = 0; i < numCars; i++) {
        if (cars[i].position < ROAD_LENGTH) {
            road[cars[i].position] = 'C'; // Mark car position
        }
    }
    
    printf("%s\n", road);
}

int main() {
    srand(time(0)); // Seed random number generator
    Car cars[NUM_CARS];
    int iterations = 20; // number of time steps

    initializeCars(cars, NUM_CARS);
    
    for (int step = 0; step < iterations; step++) {
        int trafficLight = rand() % 2; // Randomly choose red (0) or green (1)
        
        printf("Step %d: Traffic Light is %s\n", step + 1, trafficLight ? "Green" : "Red");
        updateCars(cars, NUM_CARS, trafficLight);
        printRoad(cars, NUM_CARS);
        
        usleep(500000); // Sleep for half a second to simulate time passing
    }

    return 0;
}