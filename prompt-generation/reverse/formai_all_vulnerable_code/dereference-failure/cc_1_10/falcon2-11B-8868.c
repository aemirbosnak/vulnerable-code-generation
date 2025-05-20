//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CAR 1000
#define MAX_SPEED 100
#define MAX_DISTANCE 1000
#define MIN_DISTANCE 0

typedef struct Car {
    int id;
    int speed;
    int distance;
} Car;

int main(void) {
    srand(time(NULL));
    int num_cars = (rand() % (MAX_CAR + 1)) + 1;
    Car *cars = (Car*) malloc(num_cars * sizeof(Car));

    for (int i = 0; i < num_cars; i++) {
        cars[i].id = i + 1;
        cars[i].speed = rand() % MAX_SPEED + 1;
        cars[i].distance = MIN_DISTANCE + (rand() % MAX_DISTANCE);
    }

    while (1) {
        for (int i = 0; i < num_cars; i++) {
            if (cars[i].distance <= 0) {
                printf("Car %d is now at the end of the road\n", cars[i].id);
                cars[i].distance = MAX_DISTANCE;
            }
            else if (cars[i].speed > 0) {
                cars[i].distance -= cars[i].speed;
            }
            else {
                cars[i].speed = rand() % MAX_SPEED + 1;
                cars[i].distance = MIN_DISTANCE + (rand() % MAX_DISTANCE);
            }
            printf("Car %d is now at distance %d\n", cars[i].id, cars[i].distance);
        }
        usleep(1000000);
    }

    for (int i = 0; i < num_cars; i++) {
        free(cars[i].id);
        free(cars[i].speed);
        free(cars[i].distance);
    }
    free(cars);

    return 0;
}