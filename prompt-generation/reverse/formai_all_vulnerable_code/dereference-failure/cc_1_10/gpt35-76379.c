//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct car {
    int id;
    int speed;
    struct car *next_car;
};

int main() {
    srand(time(NULL));
    int traffic_volume = 20; // number of cars on the road
    int iterations = 100; // number of iterations
    int sensor_distance = 100; // distance between two sensors
    int sensor_count = 5; // number of sensors on the road
    int total_cars_passed = 0;
    struct car *car_list = NULL; // initialize empty car list
    int car_id = 1; // initialize car id to 1
    
    // generate traffic
    for (int i = 1; i <= traffic_volume; i++) {
        struct car *new_car = malloc(sizeof(struct car));
        new_car->id = car_id;
        new_car->speed = rand() % 60 + 20; // generate random speed between 20-80km/h
        new_car->next_car = car_list;
        car_list = new_car; // add new car to the beginning of the list
        car_id++; // increment car id
    }
    
    // simulate traffic flow
    for (int i = 1; i <= iterations; i++) {
        int sensor_position = 0;
        int cars_passed = 0;
        printf("Iteration %d:\n", i);
        struct car *current_car = car_list;
        while (current_car != NULL) {
            printf("Car %d is travelling at %dkm/h.\n", current_car->id, current_car->speed);
            current_car->speed += rand() % 10 - 5; // add random variation (+/- 5) to speed
            if (current_car->speed < 20) {
                current_car->speed = 20; // minimum speed limit
            } else if (current_car->speed > 80) {
                current_car->speed = 80; // maximum speed limit
            }
            current_car = current_car->next_car;
        }
        // check if cars pass the sensors
        current_car = car_list;
        while (current_car != NULL) {
            sensor_position += current_car->speed;
            if (sensor_position >= sensor_distance) {
                cars_passed++;
                total_cars_passed++;
                sensor_position -= sensor_distance; // reset sensor position
            }
            current_car = current_car->next_car;
        }
        printf("%d cars passed sensor %d.\n", cars_passed, sensor_count);
    }
    printf("%d cars passed all sensors.\n", total_cars_passed);
    return 0;
}