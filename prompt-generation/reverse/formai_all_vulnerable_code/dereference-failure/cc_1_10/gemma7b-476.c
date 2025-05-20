//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: introspective
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
    int x, y, direction, speed;
    struct Car* next;
} Car;

Car* createCar() {
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->x = rand() % 10;
    newCar->y = rand() % 10;
    newCar->direction = rand() % 4;
    newCar->speed = rand() % 3;
    newCar->next = NULL;
    return newCar;
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
        car->speed = rand() % 3;
    }
}

void printCars(Car* car) {
    printf("Car: (%d, %d), Direction: %d, Speed: %d\n", car->x, car->y, car->direction, car->speed);
}

int main() {
    srand(time(NULL));

    Car* head = createCar();
    Car* tail = head;

    for (int i = 0; i < MAX_CARS; i++) {
        tail->next = createCar();
        tail = tail->next;
    }

    for (int i = 0; i < 10; i++) {
        for (Car* car = head; car; car = car->next) {
            moveCar(car);
            printCars(car);
        }

        printf("\n");
    }

    return 0;
}