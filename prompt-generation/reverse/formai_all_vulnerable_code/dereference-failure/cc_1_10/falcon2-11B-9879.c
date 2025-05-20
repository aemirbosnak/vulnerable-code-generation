//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    int speed;
} Car;

typedef struct {
    Car *cars;
    int num_cars;
    int num_lanes;
    int lane_width;
    int num_intersections;
    int num_roads;
    int max_speed;
} TrafficSimulation;

void simulate(TrafficSimulation *sim) {
    srand(time(NULL));
    for (int i = 0; i < sim->num_cars; i++) {
        Car *car = &sim->cars[i];
        car->x = rand() % sim->lane_width;
        car->y = rand() % sim->lane_width;
        car->speed = rand() % (sim->max_speed + 1);
    }
    for (int i = 0; i < sim->num_intersections; i++) {
        for (int j = 0; j < sim->num_roads; j++) {
            int road_speed = (sim->max_speed / sim->num_roads) * j;
            int num_cars_on_road = rand() % sim->num_cars;
            for (int k = 0; k < num_cars_on_road; k++) {
                Car *car = &sim->cars[k];
                car->speed = road_speed;
            }
        }
    }
    for (int i = 0; i < sim->num_cars; i++) {
        Car *car = &sim->cars[i];
        car->x += car->speed;
        car->y += car->speed;
        if (car->x < 0 || car->x > sim->lane_width || car->y < 0 || car->y > sim->lane_width) {
            car->speed = 0;
        }
    }
    for (int i = 0; i < sim->num_intersections; i++) {
        for (int j = 0; j < sim->num_roads; j++) {
            int road_speed = (sim->max_speed / sim->num_roads) * j;
            for (int k = 0; k < sim->num_cars; k++) {
                Car *car = &sim->cars[k];
                if (car->x > sim->lane_width / 2 + (j * sim->lane_width) && car->y > sim->lane_width / 2 + (i * sim->lane_width) && car->x < sim->lane_width / 2 + ((j + 1) * sim->lane_width) && car->y < sim->lane_width / 2 + ((i + 1) * sim->lane_width)) {
                    car->speed = road_speed;
                }
            }
        }
    }
    for (int i = 0; i < sim->num_cars; i++) {
        Car *car = &sim->cars[i];
        printf("(%d, %d) with speed %d\n", car->x, car->y, car->speed);
    }
}

int main() {
    TrafficSimulation sim = {
       .cars = NULL,
       .num_cars = 0,
       .num_lanes = 1,
       .lane_width = 10,
       .num_intersections = 3,
       .num_roads = 2,
       .max_speed = 5,
    };
    for (int i = 0; i < sim.num_lanes; i++) {
        Car *car = malloc(sizeof(Car));
        car->x = i;
        car->y = rand() % sim.lane_width;
        car->speed = rand() % (sim.max_speed + 1);
        sim.cars = realloc(sim.cars, (sim.num_cars + 1) * sizeof(Car));
        sim.cars[sim.num_cars] = *car;
        sim.num_cars++;
    }
    simulate(&sim);
    free(sim.cars);
    return 0;
}