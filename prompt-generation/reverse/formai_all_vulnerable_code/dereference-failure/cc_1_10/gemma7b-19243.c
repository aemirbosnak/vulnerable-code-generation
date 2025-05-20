//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: thoughtful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 50

typedef struct Car {
    int x, y, direction, speed, lane;
    struct Car* next;
} Car;

Car* createCar(int x, int y, int direction, int speed, int lane) {
    Car* car = (Car*)malloc(sizeof(Car));
    car->x = x;
    car->y = y;
    car->direction = direction;
    car->speed = speed;
    car->lane = lane;
    car->next = NULL;
    return car;
}

void moveCar(Car* car, int dx, int dy) {
    car->x += dx;
    car->y += dy;
}

void changeDirection(Car* car, int newDirection) {
    car->direction = newDirection;
}

void changeLane(Car* car, int newLane) {
    car->lane = newLane;
}

void simulateTrafficFlow(int numCars) {
    Car* head = NULL;
    for (int i = 0; i < numCars; i++) {
        Car* car = createCar(i, 0, 1, 1, 1);
        head = car;
        head->next = head;
    }

    time_t start = time(NULL);
    while (time(NULL) - start < 10) {
        for (Car* car = head; car; car = car->next) {
            moveCar(car, 1, 0);
            changeDirection(car, rand() % 3);
            changeLane(car, rand() % 2);
        }
        sleep(1);
    }

    printf("Traffic flow simulation complete.\n");
}

int main() {
    simulateTrafficFlow(20);
    return 0;
}