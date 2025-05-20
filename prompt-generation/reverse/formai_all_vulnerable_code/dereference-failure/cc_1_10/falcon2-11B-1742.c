//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARS 100
#define MAX_SPEED 60
#define MIN_SPEED 0

int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed random number generator with current time

    int num_cars = NUM_CARS;
    int num_blocks = 100;
    int num_seconds = 60;
    int num_cars_per_block = num_cars / num_blocks;
    int num_cars_per_second = num_cars / num_seconds;

    int *cars = malloc(sizeof(int) * num_cars);
    int *blocks = malloc(sizeof(int) * num_blocks);
    int *seconds = malloc(sizeof(int) * num_seconds);

    // Initialize cars with random speeds between 0 and MAX_SPEED
    for (int i = 0; i < num_cars; i++) {
        cars[i] = (rand() % (MAX_SPEED - MIN_SPEED + 1)) + MIN_SPEED;
    }

    // Initialize blocks with random speeds between 0 and MAX_SPEED
    for (int i = 0; i < num_blocks; i++) {
        blocks[i] = (rand() % (MAX_SPEED - MIN_SPEED + 1)) + MIN_SPEED;
    }

    // Initialize seconds with random speeds between 0 and MAX_SPEED
    for (int i = 0; i < num_seconds; i++) {
        seconds[i] = (rand() % (MAX_SPEED - MIN_SPEED + 1)) + MIN_SPEED;
    }

    // Simulate traffic flow
    for (int i = 0; i < num_seconds; i++) {
        for (int j = 0; j < num_cars; j++) {
            if (cars[j] < blocks[i] && cars[j] < seconds[i]) {
                cars[j] = seconds[i];
            }
        }
    }

    // Print final traffic flow
    for (int i = 0; i < num_cars; i++) {
        printf("Car %d is traveling at %d mph.\n", i + 1, cars[i]);
    }

    free(cars);
    free(blocks);
    free(seconds);

    return 0;
}