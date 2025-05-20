//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_CARS 10
#define NUM_LANES 4

typedef struct {
    int id;
    int lane;
    int position;  // Position on the lane
} Car;

typedef struct {
    Car *cars[MAX_CARS];
    int count;
} Lane;

Lane lanes[NUM_LANES];

void init_lanes() {
    for (int i = 0; i < NUM_LANES; i++) {
        lanes[i].count = 0;
    }
}

void add_car(int lane_id, int car_id) {
    if (lanes[lane_id].count < MAX_CARS) {
        Car *new_car = (Car *)malloc(sizeof(Car));
        new_car->id = car_id;
        new_car->lane = lane_id;
        new_car->position = 0;  // Start at position 0
        lanes[lane_id].cars[lanes[lane_id].count++] = new_car;
    }
}

void move_cars() {
    for (int i = 0; i < NUM_LANES; i++) {
        for (int j = 0; j < lanes[i].count; j++) {
            if (lanes[i].cars[j]) {
                lanes[i].cars[j]->position++;
                if (lanes[i].cars[j]->position > 20) {  // If the car goes out of bounds
                    free(lanes[i].cars[j]);
                    lanes[i].cars[j] = NULL;
                    lanes[i].count--;
                }
            }
        }
    }
}

void print_traffic() {
    printf("Current traffic status:\n");
    for (int i = 0; i < NUM_LANES; i++) {
        printf("Lane %d: ", i);
        for (int j = 0; j < lanes[i].count; j++) {
            if (lanes[i].cars[j] != NULL) {
                printf("[Car %d pos: %d] ", lanes[i].cars[j]->id, lanes[i].cars[j]->position);
            }
        }
        printf("\n");
    }
}

int main() {
    init_lanes();

    // Generate random cars
    for (int i = 0; i < MAX_CARS; i++) {
        int lane_id = rand() % NUM_LANES;
        add_car(lane_id, i);
    }

    // Simulate traffic flow
    for (int t = 0; t < 30; t++) {  // Simulate for 30 time units
        printf("\nTime unit %d:\n", t);
        print_traffic();
        move_cars();
        sleep(1);  // To simulate time passing
    }

    // Cleanup remaining vehicles
    for (int i = 0; i < NUM_LANES; i++) {
        for (int j = 0; j < lanes[i].count; j++) {
            free(lanes[i].cars[j]);
        }
    }
    
    return 0;
}