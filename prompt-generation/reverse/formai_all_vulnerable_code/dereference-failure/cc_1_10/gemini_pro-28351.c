//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <time.h>

#define ROAD_LENGTH 1000
#define ROAD_WIDTH 10
#define MAX_SPEED 100
#define MIN_SPEED 10
#define MAX_ACCELERATION 5
#define MAX_DECELERATION 5
#define SAFE_DISTANCE 50

typedef struct car {
    int x; // Position on the road
    int v; // Velocity
    int a; // Acceleration
} car;

typedef struct road {
    car *cars; // Array of cars on the road
    int num_cars; // Number of cars on the road
} road;

// Initialize the road with random cars
void init_road(road *r) {
    r->num_cars = rand() % 100;
    r->cars = malloc(sizeof(car) * r->num_cars);
    for (int i = 0; i < r->num_cars; i++) {
        r->cars[i].x = rand() % ROAD_LENGTH;
        r->cars[i].v = rand() % (MAX_SPEED - MIN_SPEED) + MIN_SPEED;
        r->cars[i].a = 0;
    }
}

// Update the state of the road
void update_road(road *r) {
    // Update the position of each car
    for (int i = 0; i < r->num_cars; i++) {
        r->cars[i].x += r->cars[i].v;
    }

    // Update the velocity of each car
    for (int i = 0; i < r->num_cars; i++) {
        // Accelerate or decelerate the car based on the distance to the car in front
        if (i > 0 && r->cars[i].x - r->cars[i - 1].x < SAFE_DISTANCE) {
            r->cars[i].a = -MAX_DECELERATION;
        } else {
            r->cars[i].a = MAX_ACCELERATION;
        }

        // Clamp the velocity to the maximum speed
        r->cars[i].v = fmin(r->cars[i].v + r->cars[i].a, MAX_SPEED);
    }
}

// Print the state of the road
void print_road(road *r) {
    for (int i = 0; i < ROAD_LENGTH; i++) {
        int num_cars_at_pos = 0;
        for (int j = 0; j < r->num_cars; j++) {
            if (r->cars[j].x == i) {
                num_cars_at_pos++;
            }
        }
        printf("%d ", num_cars_at_pos);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    road r;
    init_road(&r);

    for (int i = 0; i < 1000; i++) {
        update_road(&r);
        print_road(&r);
    }

    return 0;
}