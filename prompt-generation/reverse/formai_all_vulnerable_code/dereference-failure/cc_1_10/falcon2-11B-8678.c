//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Point;

int main() {
    srand(time(NULL));

    int num_cars = 100;
    int num_lanes = 4;
    int car_speed = 60;
    int lane_width = 4;

    Point *cars = malloc(num_cars * sizeof(Point));

    for (int i = 0; i < num_cars; i++) {
        cars[i].x = rand() % num_lanes;
        cars[i].y = rand() % lane_width;
    }

    for (int i = 0; i < num_cars; i++) {
        printf("Car %d starts at position (%d, %d)\n", i+1, cars[i].x, cars[i].y);
    }

    for (int i = 0; i < num_cars; i++) {
        int next_lane = (cars[i].x + 1) % num_lanes;
        if (next_lane == cars[i].x) {
            printf("Car %d moves to the right lane.\n", i+1);
            cars[i].x = next_lane;
        } else {
            printf("Car %d moves to the left lane.\n", i+1);
            cars[i].x = (cars[i].x + num_lanes - 1) % num_lanes;
        }

        int next_position = (cars[i].y + 1) % lane_width;
        if (next_position == cars[i].y) {
            printf("Car %d moves forward.\n", i+1);
            cars[i].y = next_position;
        } else {
            printf("Car %d moves backward.\n", i+1);
            cars[i].y = (cars[i].y + lane_width - 1) % lane_width;
        }
    }

    free(cars);

    return 0;
}