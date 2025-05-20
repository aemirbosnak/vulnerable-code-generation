//MISTRAL-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 100
#define NUM_CARS 50
#define LANE_WIDTH 5
#define MIN_SPEED 1
#define MAX_SPEED 50

typedef struct {
    int pos;
    int speed;
} Car;

void initCars(Car *cars) {
    for (int i = 0; i < NUM_CARS; i++) {
        cars[i].pos = rand() % ROAD_LENGTH;
        cars[i].speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
    }
}

void printRoad(Car *cars) {
    for (int i = 0; i < ROAD_LENGTH; i++) {
        printf("-");
        for (int j = 0; j < LANE_WIDTH; j++) {
            int carIndex = i * LANE_WIDTH + j;
            if (carIndex >= 0 && carIndex < NUM_CARS) {
                printf(" C%d", carIndex);
                continue;
            }
            Car car = cars[i * LANE_WIDTH];
            if (car.pos == i) {
                printf("^");
                continue;
            }
            printf(" ");
        }
        printf("|\n");
    }
}

void simulateStep(Car *cars) {
    for (int i = 0; i < NUM_CARS; i++) {
        Car *car = &cars[i];
        car->pos += car->speed;
        if (car->pos >= ROAD_LENGTH) {
            car->pos -= ROAD_LENGTH;
        }
    }
}

int main() {
    Car cars[NUM_CARS];
    initCars(cars);
    srand(time(NULL));

    printf("INITIAL ROAD STATE:\n");
    printRoad(cars);

    for (int i = 0; i < 100; i++) {
        simulateStep(cars);
        printRoad(cars);
        sleep(1);
    }

    return 0;
}