//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_CARS 10
#define INTERSECTION_WIDTH 10
#define INTERSECTION_HEIGHT 10

typedef struct {
    int id;
    char direction; // 'N' for North, 'S' for South, 'E' for East, 'W' for West
} Car;

Car *createCar(int id, char direction) {
    Car *newCar = (Car *)malloc(sizeof(Car));
    newCar->id = id;
    newCar->direction = direction;
    return newCar;
}

void displayIntersection(Car *cars[], int carCount) {
    char grid[INTERSECTION_HEIGHT][INTERSECTION_WIDTH] = {{' '}};

    for (int i = 0; i < carCount; i++) {
        if (cars[i]) {
            int x = 0, y = 0;
            switch (cars[i]->direction) {
                case 'N': y = INTERSECTION_HEIGHT - 1; break;
                case 'S': y = 0; break;
                case 'E': x = INTERSECTION_WIDTH - 1; break;
                case 'W': x = 0; break;
            }
            grid[y][x] = (char)(cars[i]->id + '0'); // Place the car's id on the grid
        }
    }

    printf("\nCurrent Intersection State:\n");
    for (int row = 0; row < INTERSECTION_HEIGHT; row++) {
        for (int col = 0; col < INTERSECTION_WIDTH; col++) {
            printf("| %c ", grid[row][col]);
        }
        printf("|\n");
    }
    printf("\n");
}

void simulateTrafficFlow() {
    Car *cars[MAX_CARS];
    int carCount = 0;

    // Initialize random seed for car generation
    srand(time(NULL));

    // Generate cars approaching the intersection
    while (carCount < MAX_CARS) {
        char directions[] = {'N', 'S', 'E', 'W'};
        int randomDirection = rand() % 4;

        cars[carCount] = createCar(carCount + 1, directions[randomDirection]);
        printf("Car %d is approaching from %c!\n", cars[carCount]->id, cars[carCount]->direction);
        carCount++;

        displayIntersection(cars, carCount);
        sleep(1); // Simulate time passing
    }

    // Traffic light sequence
    for (int light = 0; light < 4; light++) {
        switch (light) {
            case 0: printf("Traffic Light: NORTH-SOUTH GREEN\n"); break;
            case 1: printf("Traffic Light: EAST-WEST GREEN\n"); break;
            case 2: printf("Traffic Light: NORTH-SOUTH RED\n"); break;
            case 3: printf("Traffic Light: EAST-WEST RED\n"); break;
            default: break;
        }
        sleep(2);
        displayIntersection(cars, carCount);
    }

    // Clean up memory
    for (int i = 0; i < carCount; i++) {
        free(cars[i]);
    }
}

int main() {
    printf("Welcome to the Traffic Flow Simulation!\n");
    simulateTrafficFlow();
    printf("Simulation completed. Safe travels!\n");
    return 0;
}