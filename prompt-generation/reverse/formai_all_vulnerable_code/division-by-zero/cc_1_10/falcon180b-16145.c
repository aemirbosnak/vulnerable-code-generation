//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROADS 10
#define NUM_CARS 100
#define ROAD_LENGTH 100
#define MAX_SPEED 20
#define MIN_SPEED 5

typedef struct {
    int road_id;
    int length;
    int speed_limit;
    int num_cars;
} Road;

Road roads[NUM_ROADS];
int car_counts[NUM_ROADS];

void init_roads() {
    for (int i = 0; i < NUM_ROADS; i++) {
        roads[i].road_id = i;
        roads[i].length = ROAD_LENGTH;
        roads[i].speed_limit = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
        roads[i].num_cars = 0;
    }
}

void add_car(int road_id) {
    if (car_counts[road_id] < roads[road_id].length) {
        car_counts[road_id]++;
    }
}

void remove_car(int road_id) {
    if (car_counts[road_id] > 0) {
        car_counts[road_id]--;
    }
}

void move_cars() {
    for (int i = 0; i < NUM_ROADS; i++) {
        int speed = rand() % (roads[i].speed_limit - 5) + 5;
        int distance = speed * 2;
        for (int j = 0; j < car_counts[i]; j++) {
            if (roads[i].num_cars + car_counts[i] > roads[i].length) {
                printf("Traffic jam on road %d\n", i);
            } else {
                roads[i].num_cars++;
                printf("Car %d moving on road %d at %d km/h\n", j + 1, i, speed);
            }
            usleep(distance * 1000);
            roads[i].num_cars--;
        }
    }
}

int main() {
    srand(time(NULL));
    init_roads();

    while (1) {
        system("clear");
        for (int i = 0; i < NUM_ROADS; i++) {
            printf("Road %d: length %d m, speed limit %d km/h, cars %d\n", i, roads[i].length, roads[i].speed_limit, car_counts[i]);
        }
        move_cars();
        usleep(500000);
    }

    return 0;
}