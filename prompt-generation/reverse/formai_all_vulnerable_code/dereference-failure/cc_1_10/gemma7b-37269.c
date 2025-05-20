//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARS 10

typedef struct Car {
    int x, y, direction, speed;
    struct Car* next;
} Car;

Car* createCar(int x, int y, int direction, int speed) {
    Car* car = (Car*)malloc(sizeof(Car));
    car->x = x;
    car->y = y;
    car->direction = direction;
    car->speed = speed;
    car->next = NULL;
    return car;
}

void moveCar(Car* car) {
    switch (car->direction) {
        case 0:
            car->x++;
            break;
        case 1:
            car->y++;
            break;
        case 2:
            car->x--;
            break;
        case 3:
            car->y--;
            break;
    }
    car->speed++;
}

void simulateTrafficFlow(int numCars) {
    Car* head = NULL;
    for (int i = 0; i < numCars; i++) {
        Car* car = createCar(i, 0, 0, 1);
        if (head) {
            car->next = head;
        }
        head = car;
    }

    for (int t = 0; t < 100; t++) {
        for (Car* car = head; car; car = car->next) {
            moveCar(car);
        }
    }

    for (Car* car = head; car; car = car->next) {
        free(car);
    }
}

int main() {
    simulateTrafficFlow(5);
    return 0;
}