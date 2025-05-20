//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define ROAD_LENGTH 100

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

    car->speed--;
    if (car->speed == 0) {
        car->direction = (car->direction + 1) % 4;
    }
}

int main() {
    srand(time(NULL));

    Car* head = createCar(50, 50, 0, 5);
    Car* tail = head;

    for (int i = 0; i < MAX_CARS; i++) {
        tail = createCar(rand() % ROAD_LENGTH, rand() % ROAD_LENGTH, rand() % 4, rand() % 5);
        tail->next = head;
        head = tail;
    }

    for (int i = 0; i < 1000; i++) {
        moveCar(head);
    }

    return 0;
}