//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 3
#define MAX_CARS 10

typedef struct car {
    int position;
    int lane;
    int speed;
    int direction;
} car;

void initialize_cars(car *cars) {
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].position = 0;
        cars[i].lane = rand() % NUM_LANE;
        cars[i].speed = rand() % 5 + 1;
        cars[i].direction = rand() % 2;
    }
}

void simulate_traffic(car *cars) {
    time_t start_time = time(NULL);
    time_t current_time = start_time;
    int elapsed_time = 0;

    while (elapsed_time < 10) {
        current_time = time(NULL);
        elapsed_time = current_time - start_time;

        for (int i = 0; i < MAX_CARS; i++) {
            cars[i].position += cars[i].speed * elapsed_time;

            if (cars[i].direction == 0) {
                if (cars[i].position >= 100) {
                    cars[i].direction = 1;
                }
            } else if (cars[i].direction == 1) {
                if (cars[i].position <= 0) {
                    cars[i].direction = 0;
                }
            }

            switch (cars[i].lane) {
                case 0:
                    printf("Car %d is on lane 0, position %d, speed %d\n", i, cars[i].position, cars[i].speed);
                    break;
                case 1:
                    printf("Car %d is on lane 1, position %d, speed %d\n", i, cars[i].position, cars[i].speed);
                    break;
                case 2:
                    printf("Car %d is on lane 2, position %d, speed %d\n", i, cars[i].position, cars[i].speed);
                    break;
            }
        }

        sleep(1);
    }
}

int main() {
    car *cars = (car *)malloc(MAX_CARS * sizeof(car));
    initialize_cars(cars);
    simulate_traffic(cars);
    free(cars);

    return 0;
}