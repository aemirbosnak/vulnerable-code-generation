//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_SPEED 60

typedef struct {
    int x;
    int speed;
} Car;

typedef struct {
    Car cars[MAX_CARS];
    int num_cars;
    int speed_limit;
} Lane;

void print_lane(Lane lane) {
    for (int i = 0; i < lane.num_cars; i++) {
        printf("%d ", lane.cars[i].x);
    }
    printf("\n");
}

void accelerate(Car* car, int speed_limit) {
    // accelerate up to speed limit
    if (car->speed < speed_limit) {
        car->speed++;
    }
}

void decelerate(Car* car, int dist) {
    // calculate how much to slow down based on distance to car in front
    if (dist <= car->speed) {
        car->speed = dist - 1;
    }
}

void update_car_positions(Lane* lane) {
    for (int i = 0; i < lane->num_cars; i++) {
        if (i == 0) {
            // lead car
            accelerate(&lane->cars[i], lane->speed_limit);
            lane->cars[i].x += lane->cars[i].speed;
        }
        else {
            // following cars
            int dist = lane->cars[i].x - lane->cars[i-1].x;
            decelerate(&lane->cars[i], dist);
            lane->cars[i].x = lane->cars[i-1].x - 1;
        }
    }
}

void add_car(Lane* lane, int x, int speed) {
    Car new_car = {x, speed};
    lane->cars[lane->num_cars++] = new_car;
}

void remove_car(Lane* lane) {
    lane->num_cars--;
}

void simulate_traffic(int time_steps) {
    srand(time(0));
    Lane lane = {.num_cars = 0, .speed_limit = MAX_SPEED};
    add_car(&lane, 0, MAX_SPEED);
    for (int t = 0; t < time_steps; t++) {
        if (rand() % 10 == 0) {
            add_car(&lane, 0, 0);
        }
        if (rand() % 20 == 0) {
            remove_car(&lane);
        }
        update_car_positions(&lane);
        print_lane(lane);
    }
}

int main() {
    simulate_traffic(50);
    return 0;
}