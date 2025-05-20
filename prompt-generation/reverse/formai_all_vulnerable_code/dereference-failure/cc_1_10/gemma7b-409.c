//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define ROAD_LENGTH 100

typedef struct Car {
    int position;
    int direction;
    int speed;
    struct Car* next;
} Car;

Car* createCar() {
    Car* car = (Car*)malloc(sizeof(Car));
    car->position = 0;
    car->direction = 1;
    car->speed = 1;
    car->next = NULL;
    return car;
}

void moveCar(Car* car) {
    switch (car->direction) {
        case 1:
            car->position++;
            break;
        case -1:
            car->position--;
            break;
    }

    if (car->speed > 0) {
        car->position++;
    }
}

void simulateTrafficFlow() {
    srand(time(NULL));

    Car* head = createCar();
    Car* tail = head;

    for (int i = 0; i < MAX_CARS; i++) {
        tail->next = createCar();
        tail = tail->next;
    }

    for (int i = 0; i < ROAD_LENGTH; i++) {
        for (Car* car = head; car; car = car->next) {
            moveCar(car);
        }

        printf("Traffic flow at time %d:\n", i);
        for (Car* car = head; car; car = car->next) {
            printf("Car position: %d, speed: %d\n", car->position, car->speed);
        }

        printf("\n");
    }
}

int main() {
    simulateTrafficFlow();

    return 0;
}