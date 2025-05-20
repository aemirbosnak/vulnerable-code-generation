//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#define MAX_CARS 100
#define MAX_LIGHT_TIME 60
#define DELTA_T 0.1

// Light state
int light_state = 0;

// Number of cars in the system
int num_cars = 0;

// Car data structure
typedef struct {
    int car_id;
    int start_time;
    int end_time;
} Car;

// Light data structure
typedef struct {
    int light_id;
    int start_time;
    int end_time;
    int state;
} Light;

// Function to initialize cars
void init_cars() {
    srand(time(NULL));
    Car* cars = (Car*)malloc(sizeof(Car) * MAX_CARS);
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].car_id = i;
        cars[i].start_time = rand() % (MAX_LIGHT_TIME + 1);
        cars[i].end_time = cars[i].start_time + rand() % (MAX_LIGHT_TIME + 1);
    }
    num_cars = MAX_CARS;
}

// Function to initialize lights
void init_lights() {
    Light* lights = (Light*)malloc(sizeof(Light) * MAX_LIGHT_TIME);
    for (int i = 0; i < MAX_LIGHT_TIME; i++) {
        lights[i].light_id = i;
        lights[i].start_time = i;
        lights[i].end_time = lights[i].start_time + MAX_LIGHT_TIME;
        lights[i].state = 0;
    }
}

// Function to print car data
void print_car(Car* car) {
    printf("Car %d: Start time: %d, End time: %d\n", car->car_id, car->start_time, car->end_time);
}

// Function to print light data
void print_light(Light* light) {
    printf("Light %d: Start time: %d, End time: %d, State: %d\n", light->light_id, light->start_time, light->end_time, light->state);
}

// Function to update car data
void update_cars(Car* cars, int num_cars, int delta_t) {
    // Calculate new start time for each car
    for (int i = 0; i < num_cars; i++) {
        cars[i].start_time += delta_t;
    }
}

// Function to update light data
void update_lights(Light* lights, int num_lights, int delta_t) {
    // Calculate new end time for each light
    for (int i = 0; i < num_lights; i++) {
        lights[i].end_time += delta_t;
    }
}

// Function to simulate traffic flow
void simulate_traffic() {
    srand(time(NULL));
    Car* cars = (Car*)malloc(sizeof(Car) * MAX_CARS);
    init_cars();
    Light* lights = (Light*)malloc(sizeof(Light) * MAX_LIGHT_TIME);
    init_lights();
    int delta_t = DELTA_T;

    // Main simulation loop
    while (1) {
        // Update car data
        update_cars(cars, num_cars, delta_t);

        // Update light data
        update_lights(lights, MAX_LIGHT_TIME, delta_t);

        // Check if car reaches end time
        for (int i = 0; i < num_cars; i++) {
            if (cars[i].end_time <= lights[light_state].start_time) {
                light_state = (light_state + 1) % MAX_LIGHT_TIME;
                printf("Green light for %d seconds\n", lights[light_state].end_time - lights[light_state].start_time);
                printf("Car %d reaches end time, exiting simulation\n", cars[i].car_id);
                break;
            }
        }

        // Check if car starts crossing
        for (int i = 0; i < num_cars; i++) {
            if (cars[i].start_time <= lights[light_state].end_time) {
                printf("Car %d starts crossing\n", cars[i].car_id);
                break;
            }
        }

        // Check if light changes
        if (light_state == MAX_LIGHT_TIME - 1) {
            light_state = 0;
            printf("Yellow light for %d seconds\n", lights[light_state].end_time - lights[light_state].start_time);
        } else {
            light_state++;
        }

        // Wait for delta_t seconds
        usleep(delta_t * 1000);
    }

    free(cars);
    free(lights);
}

int main() {
    simulate_traffic();
    return 0;
}