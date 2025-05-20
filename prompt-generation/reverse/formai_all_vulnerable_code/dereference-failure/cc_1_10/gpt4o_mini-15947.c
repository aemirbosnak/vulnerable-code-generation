//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_CARS 10
#define GREEN_LIGHT_DURATION 5
#define RED_LIGHT_DURATION 5

typedef struct {
    int id;
    int waiting_time;
} Car;

Car* create_car(int id) {
    Car* car = (Car*)malloc(sizeof(Car));
    car->id = id;
    car->waiting_time = 0;
    return car;
}

void simulate_traffic_light(int *light_state) {
    if (*light_state == 0) { // Green
        sleep(GREEN_LIGHT_DURATION);
        *light_state = 1; // Change to red
    } else { // Red
        sleep(RED_LIGHT_DURATION);
        *light_state = 0; // Change to green
    }
}

void show_traffic_light(int light_state) {
    if (light_state == 0) {
        printf("Traffic Light: GREEN\n");
    } else {
        printf("Traffic Light: RED\n");
    }
}

void simulate_car_flow(Car *cars[], int num_cars, int light_state) {
    for (int i = 0; i < num_cars; i++) {
        if (light_state == 0) { // Green light
            if (cars[i] != NULL) {
                printf("Car %d is passing the intersection.\n", cars[i]->id);
                free(cars[i]);
                cars[i] = NULL; // Remove the car after passing
            }
        } else { // Red light
            if (cars[i] != NULL) {
                cars[i]->waiting_time++;
                printf("Car %d is waiting at the intersection for %d seconds.\n",
                       cars[i]->id, cars[i]->waiting_time);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    Car* cars[MAX_CARS] = { NULL };
    int light_state = 0; // 0 = Green, 1 = Red
    int total_cars = 0;

    // Create cars randomly
    for (int i = 0; i < MAX_CARS; i++) {
        if (rand() % 2 == 0 && total_cars < MAX_CARS) {
            cars[total_cars++] = create_car(i + 1);
        }
    }

    while (total_cars > 0) {
        show_traffic_light(light_state);
        simulate_car_flow(cars, total_cars, light_state);
        simulate_traffic_light(&light_state);
    }

    printf("All cars have passed through the intersection.\n");
    return 0;
}