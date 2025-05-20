//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: complex
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
    car->speed = rand() % 3;
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
        car->speed = rand() % 3;
    }
}

void displayCars(Car* car) {
    while (car) {
        printf("Car: x=%d, y=%d, direction=%d, speed=%d\n", car->x, car->y, car->direction, car->speed);
        car = car->next;
    }
}

int main() {
    srand(time(NULL));

    Car* head = createCar();
    head->next = createCar();
    head->next->next = createCar();

    int i = 0;
    while (i < 10) {
        moveCar(head);
        displayCars(head);
        i++;
    }

    return 0;
}