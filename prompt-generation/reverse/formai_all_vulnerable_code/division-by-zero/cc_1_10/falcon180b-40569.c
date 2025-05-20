//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROADS 10
#define NUM_CARS 100
#define MAX_SPEED 10

int road_length[NUM_ROADS];
int car_speed[NUM_CARS];
int car_position[NUM_CARS];
int car_direction[NUM_CARS];
int car_waiting_time[NUM_CARS];

void init() {
    int i;
    for (i = 0; i < NUM_ROADS; i++) {
        road_length[i] = rand() % 100 + 1;
    }
    for (i = 0; i < NUM_CARS; i++) {
        car_speed[i] = rand() % MAX_SPEED + 1;
        car_position[i] = rand() % road_length[i];
        car_direction[i] = rand() % 2;
        car_waiting_time[i] = rand() % 10;
    }
}

void car_move(int car_id) {
    int road_id = rand() % NUM_ROADS;
    int speed = car_speed[car_id];
    int position = car_position[car_id];
    int direction = car_direction[car_id];
    int waiting_time = car_waiting_time[car_id];

    if (position == 0 && direction == 0) {
        printf("Car %d is waiting at the start of road %d\n", car_id, road_id);
        waiting_time--;
        if (waiting_time == 0) {
            direction = 1;
            waiting_time = rand() % 10;
        }
    } else if (position == road_length[road_id] - 1 && direction == 1) {
        printf("Car %d has reached the end of road %d\n", car_id, road_id);
        direction = 0;
    } else {
        printf("Car %d is moving on road %d at position %d\n", car_id, road_id, position);
        if (direction == 0) {
            position++;
        } else {
            position--;
        }
    }

    car_position[car_id] = position;
    car_direction[car_id] = direction;
}

int main() {
    srand(time(NULL));
    init();

    int i;
    for (i = 0; i < NUM_CARS; i++) {
        car_move(i);
    }

    return 0;
}