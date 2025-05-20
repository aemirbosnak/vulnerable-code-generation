//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: modular
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10
#define ROAD_LENGTH 100

typedef struct Car {
    int position;
    int direction;
    int speed;
} Car;

void initializeCars(Car *cars, int numCars) {
    for (int i = 0; i < numCars; i++) {
        cars[i].position = rand() % ROAD_LENGTH;
        cars[i].direction = rand() % 2; // Left or right
        cars[i].speed = rand() % 5 + 1;
    }
}

void moveCars(Car *cars, int numCars) {
    for (int i = 0; i < numCars; i++) {
        switch (cars[i].direction) {
            case 0: // Left
                cars[i].position--;
                break;
            case 1: // Right
                cars[i].position++;
                break;
        }

        if (cars[i].position < 0) {
            cars[i].position = 0;
            cars[i].direction = 1;
        } else if (cars[i].position >= ROAD_LENGTH) {
            cars[i].position = ROAD_LENGTH - 1;
            cars[i].direction = 0;
        }
    }
}

void simulateTrafficFlow(int numCars) {
    Car *cars = malloc(numCars * sizeof(Car));
    initializeCars(cars, numCars);

    for (int t = 0; t < 1000; t++) {
        moveCars(cars, numCars);
    }

    free(cars);
}

int main() {
    simulateTrafficFlow(5);
    return 0;
}