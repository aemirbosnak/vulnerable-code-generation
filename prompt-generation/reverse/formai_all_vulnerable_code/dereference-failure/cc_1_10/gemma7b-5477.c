//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: invasive
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
    int x, y, direction, speed;
    struct Car* next;
} Car;

Car* createCar() {
    Car* car = (Car*)malloc(sizeof(Car));
    car->x = rand() % 10;
    car->y = rand() % 10;
    car->direction = rand() % 4;
    car->speed = rand() % 5;
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

void simulateTrafficFlow() {
    Car* head = createCar();
    head->next = createCar();
    head->next->next = createCar();

    for (int i = 0; i < 100; i++) {
        moveCar(head);
        printf("Car position: (%d, %d)\n", head->x, head->y);
    }
}

int main() {
    simulateTrafficFlow();
    return 0;
}