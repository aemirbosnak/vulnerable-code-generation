//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
    int position;
    int direction;
    int speed;
} Car;

void initialize_cars(Car *cars) {
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].position = rand() % 100;
        cars[i].direction = rand() % 2;
        cars[i].speed = rand() % 5;
    }
}

void update_cars(Car *cars) {
    for (int i = 0; i < MAX_CARS; i++) {
        switch (cars[i].direction) {
            case 0:
                cars[i].position++;
                break;
            case 1:
                cars[i].position--;
                break;
        }

        cars[i].position = (cars[i].position % 100) ? cars[i].position : 0;
    }
}

void print_cars(Car *cars) {
    for (int i = 0; i < MAX_CARS; i++) {
        printf("Car %d: position %d, direction %d, speed %d\n", i, cars[i].position, cars[i].direction, cars[i].speed);
    }
}

int main() {
    srand(time(NULL));

    Car *cars = (Car *)malloc(MAX_CARS * sizeof(Car));
    initialize_cars(cars);

    for (int t = 0; t < 10; t++) {
        update_cars(cars);
        print_cars(cars);
    }

    free(cars);

    return 0;
}