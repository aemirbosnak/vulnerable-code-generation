//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ROADS 5
#define CAR_LIMIT 10
#define TIME_STEP 1

typedef struct {
    int car_id;
    int speed; // Speed in km/h
    int position; // Position on the road
} Car;

typedef struct {
    Car *cars[CAR_LIMIT];
    int car_count;
} Road;

void initialize_road(Road *road) {
    road->car_count = 0;
}

int add_car(Road *road, int car_id) {
    if (road->car_count < CAR_LIMIT) {
        Car *new_car = (Car *)malloc(sizeof(Car));
        new_car->car_id = car_id;
        new_car->speed = rand() % 21 + 40; // Speed between 40 and 60 km/h
        new_car->position = 0;
        road->cars[road->car_count++] = new_car;
        return 1;
    }
    return 0;
}

void move_cars(Road *road) {
    for (int i = 0; i < road->car_count; i++) {
        road->cars[i]->position += (road->cars[i]->speed / 3600.0) * TIME_STEP;
        // Check for position limit for a simple circular road simulation; reset if exceeds length
        if (road->cars[i]->position >= 100) {
            road->cars[i]->position = 0; // Reset position if exceeds 100 units
        }
    }
}

void display_traffic(Road *road) {
    printf("\nTraffic Flow Simulation:\n");
    for (int i = 0; i < road->car_count; i++) {
        printf("Car ID: %d | Speed: %d km/h | Position: %.2f units\n",
               road->cars[i]->car_id, road->cars[i]->speed, road->cars[i]->position);
    }
}

void free_road(Road *road) {
    for (int i = 0; i < road->car_count; i++) {
        free(road->cars[i]);
    }
}

int main() {
    srand(time(NULL));
    Road *road = (Road *)malloc(sizeof(Road));
    initialize_road(road);

    int simulation_time = 60; // total simulation time in seconds
    int add_car_interval = 5; // add a car every 5 seconds
    int next_car_time = 0;

    for (int t = 0; t < simulation_time; t += TIME_STEP) {
        if (t >= next_car_time) {
            if (add_car(road, road->car_count + 1)) {
                printf("Added Car ID: %d\n", road->car_count);
            }
            next_car_time += add_car_interval; // schedule next car addition
        }
        
        move_cars(road);
        display_traffic(road);
        
        sleep(TIME_STEP); // pause for a time step
    }

    free_road(road);
    free(road);
    
    return 0;
}