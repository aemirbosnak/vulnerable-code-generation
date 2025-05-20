//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50

typedef struct Car {
    int x, y, direction, speed;
} Car;

void simulateTrafficFlow(Car **cars, int numCars) {
    for (int i = 0; i < numCars; i++) {
        cars[i]->x++;
        switch (cars[i]->direction) {
            case 0:
                cars[i]->y++;
                break;
            case 1:
                cars[i]->y--;
                break;
            case 2:
                cars[i]->x++;
                break;
            case 3:
                cars[i]->x--;
                break;
        }
    }
}

int main() {
    srand(time(NULL));

    Car **cars = (Car **)malloc(MAX_CARS * sizeof(Car));

    for (int i = 0; i < MAX_CARS; i++) {
        cars[i] = (Car *)malloc(sizeof(Car));
        cars[i]->x = rand() % 10;
        cars[i]->y = rand() % 10;
        cars[i]->direction = rand() % 4;
        cars[i]->speed = rand() % 5 + 1;
    }

    simulateTrafficFlow(cars, MAX_CARS);

    for (int i = 0; i < MAX_CARS; i++) {
        printf("Car %d: (%d, %d)\n", i, cars[i]->x, cars[i]->y);
    }

    free(cars);

    return 0;
}