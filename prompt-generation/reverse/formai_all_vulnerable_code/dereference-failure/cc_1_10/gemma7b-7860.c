//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

// Define traffic light status
enum TrafficLightStatus { RED, YELLOW, GREEN };

// Define car movement direction
enum Direction { LEFT, STRAIGHT, RIGHT };

// Define car structure
typedef struct Car {
    int x, y;
    enum Direction direction;
    enum TrafficLightStatus trafficLightStatus;
} Car;

// Function to simulate traffic flow
void simulateTrafficFlow(Car *cars) {
    // Randomly change traffic light status
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].trafficLightStatus = (enum TrafficLightStatus)rand() % 3;
    }

    // Move cars according to their direction and traffic light status
    for (int i = 0; i < MAX_CARS; i++) {
        switch (cars[i].direction) {
            case LEFT:
                cars[i].x--;
                break;
            case STRAIGHT:
                cars[i].y++;
                break;
            case RIGHT:
                cars[i].x++;
                break;
        }

        // If car reaches end of lane, change direction
        if (cars[i].x == MAX_LANE - 1 && cars[i].direction == LEFT) {
            cars[i].direction = RIGHT;
        } else if (cars[i].y == MAX_LANE - 1 && cars[i].direction == STRAIGHT) {
            cars[i].direction = LEFT;
        } else if (cars[i].x == 0 && cars[i].direction == RIGHT) {
            cars[i].direction = LEFT;
        }
    }
}

int main() {
    // Create an array of cars
    Car *cars = (Car *)malloc(MAX_CARS * sizeof(Car));

    // Initialize cars
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].x = rand() % MAX_LANE;
        cars[i].y = 0;
        cars[i].direction = STRAIGHT;
        cars[i].trafficLightStatus = RED;
    }

    // Simulate traffic flow
    simulateTrafficFlow(cars);

    // Print the final positions of the cars
    for (int i = 0; i < MAX_CARS; i++) {
        printf("Car %d: x = %d, y = %d\n", i, cars[i].x, cars[i].y);
    }

    // Free memory
    free(cars);

    return 0;
}