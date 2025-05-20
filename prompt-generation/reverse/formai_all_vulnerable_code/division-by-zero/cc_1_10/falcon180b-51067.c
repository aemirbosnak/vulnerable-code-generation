//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_ROADS 100
#define MAX_CARS 1000
#define MIN_SPEED 10
#define MAX_SPEED 80
#define RANDOM_SEED 12345

struct Road {
    int length;
    int speed_limit;
    int num_cars;
};

struct Car {
    int pos;
    int speed;
    int dest;
};

void init_road(struct Road *road, int length, int speed_limit) {
    road->length = length;
    road->speed_limit = speed_limit;
    road->num_cars = 0;
}

void add_car(struct Road *road, struct Car *car) {
    road->num_cars++;
}

void remove_car(struct Road *road, struct Car *car) {
    road->num_cars--;
}

void move_car(struct Car *car, int speed, int dest) {
    car->pos += speed;
    if (car->pos >= dest) {
        car->pos = dest;
    }
}

int main() {
    srand(time(NULL));
    int num_roads, num_cars;
    printf("Enter the number of roads: ");
    scanf("%d", &num_roads);
    printf("Enter the number of cars: ");
    scanf("%d", &num_cars);

    struct Road roads[MAX_ROADS];
    for (int i = 0; i < num_roads; i++) {
        init_road(&roads[i], rand() % 1000 + 100, rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED);
    }

    struct Car cars[MAX_CARS];
    for (int i = 0; i < num_cars; i++) {
        cars[i].pos = 0;
        cars[i].speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
        cars[i].dest = rand() % num_roads;
    }

    int curr_time = 0;
    while (curr_time < 1000) {
        for (int i = 0; i < num_cars; i++) {
            int road_index = cars[i].dest;
            struct Road *road = &roads[road_index];
            move_car(&cars[i], cars[i].speed, road->length);

            if (cars[i].pos >= road->length) {
                cars[i].pos = 0;
                curr_time++;
            }
        }
    }

    return 0;
}