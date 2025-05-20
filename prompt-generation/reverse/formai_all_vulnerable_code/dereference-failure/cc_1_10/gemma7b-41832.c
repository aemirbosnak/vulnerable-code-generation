//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: rigorous
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
    int x, y, direction, speed, lane;
    struct Car* next;
} Car;

Car* createCar() {
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->x = rand() % MAX_LANE;
    newCar->y = rand() % MAX_CARS;
    newCar->direction = rand() % 2;
    newCar->speed = rand() % 5 + 1;
    newCar->lane = rand() % MAX_LANE;
    newCar->next = NULL;
    return newCar;
}

void moveCar(Car* car) {
    switch (car->direction) {
        case 0:
            car->x++;
            break;
        case 1:
            car->x--;
            break;
    }

    switch (car->lane) {
        case 0:
            car->y++;
            break;
        case 1:
            car->y--;
            break;
    }

    car->speed--;
}

void simulateTrafficFlow() {
    Car* head = createCar();
    while (head) {
        moveCar(head);
        head = head->next;
    }
}

int main() {
    simulateTrafficFlow();
    return 0;
}