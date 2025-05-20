//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_ROADS 4
#define NUM_CARS 10
#define DELAY 100

typedef struct {
    int road_index;
    int direction;
} Car;

void *car_thread(void *arg) {
    Car *car = (Car *) arg;
    int road = car->road_index;
    int direction = car->direction;

    while (1) {
        if (direction == 0) {
            printf("Car %d is waiting to cross road %d\n", road, road);
            sleep(DELAY);
        } else {
            printf("Car %d is crossing road %d\n", road, road);
            sleep(DELAY);
        }

        if (road == NUM_ROADS - 1) {
            break;
        }

        if (direction == 0) {
            direction = 1;
        } else {
            direction = 0;
        }

        road++;
    }

    return NULL;
}

int main() {
    int i;
    pthread_t threads[NUM_CARS];

    for (i = 0; i < NUM_CARS; i++) {
        Car car;
        car.road_index = 0;
        car.direction = 0;

        pthread_create(&threads[i], NULL, car_thread, &car);
    }

    for (i = 0; i < NUM_CARS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}