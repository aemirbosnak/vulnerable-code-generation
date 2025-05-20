//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 100
#define MAX_CARS 1000
#define MAX_INTERSECTIONS 100
#define MAX_LANES 4
#define MAX_RED_TIME 60
#define MAX_GREEN_TIME 60

typedef struct {
    int id;
    int speed;
    int lane;
    int road;
    int position;
    int destination;
    int arrived;
} Car;

typedef struct {
    int id;
    int num_roads;
    int roads[MAX_ROADS];
    int lights[MAX_INTERSECTIONS];
} Road;

typedef struct {
    int id;
    int roads[MAX_ROADS];
} Intersection;

Road roads[MAX_ROADS];
Intersection intersections[MAX_INTERSECTIONS];
Car cars[MAX_CARS];
int num_roads = 0;
int num_intersections = 0;
int num_cars = 0;

void init() {
    srand(time(NULL));

    for (int i = 0; i < MAX_ROADS; i++) {
        roads[i].id = i;
        roads[i].num_roads = 0;
    }

    for (int i = 0; i < MAX_INTERSECTIONS; i++) {
        intersections[i].id = i;
    }
}

void add_road(int road_id) {
    roads[road_id].id = road_id;
    num_roads++;
}

void add_intersection(int intersection_id) {
    intersections[intersection_id].id = intersection_id;
    num_intersections++;
}

void add_car(int car_id, int speed, int lane, int road, int position, int destination, int arrived) {
    Car *car = &cars[num_cars];
    car->id = car_id;
    car->speed = speed;
    car->lane = lane;
    car->road = road;
    car->position = position;
    car->destination = destination;
    car->arrived = arrived;

    num_cars++;
}

int main() {
    init();

    int num_cars_to_add = rand() % 50 + 1;

    for (int i = 0; i < num_cars_to_add; i++) {
        int car_id = i + 1;
        int speed = rand() % 101;
        int lane = rand() % MAX_LANES;
        int road = rand() % num_roads;
        int position = rand() % 101;
        int destination = rand() % num_intersections;
        int arrived = 0;

        add_car(car_id, speed, lane, road, position, destination, arrived);
    }

    return 0;
}