//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 20

typedef struct Car {
    int x;
    int y;
    int direction;
    int speed;
    struct Car* next;
} Car;

Car* createCar() {
    Car* car = (Car*)malloc(sizeof(Car));
    car->x = rand() % 1000;
    car->y = rand() % 1000;
    car->direction = rand() % 4;
    car->speed = rand() % 10;
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

    car->speed--;
    if (car->speed == 0) {
        car->direction = rand() % 4;
        car->speed = rand() % 10;
    }
}

void simulateTrafficFlow() {
    Car* head = createCar();
    Car* tail = head;

    for (int i = 0; i < MAX_CARS; i++) {
        tail = createCar();
        tail->next = head;
        head = tail;
    }

    time_t t = time(NULL);
    while (time(NULL) - t < 10) {
        for (Car* car = head; car; car = car->next) {
            moveCar(car);
        }
        sleep(1);
    }
}

int main() {
    simulateTrafficFlow();
    return 0;
}