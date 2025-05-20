//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
    int x, y, direction, speed;
    struct Car* next;
} Car;

Car* createCar() {
    Car* car = (Car*)malloc(sizeof(Car));
    car->x = rand() % 100;
    car->y = rand() % 100;
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
            car->x--;
            break;
        case 2:
            car->y++;
            break;
        case 3:
            car->y--;
            break;
    }
    car->speed--;
    if (car->speed == 0) {
        car->direction = rand() % 4;
        car->speed = rand() % 5;
    }
}

void displayCars(Car* car) {
    while (car) {
        printf("Car: (%d, %d), Direction: %d, Speed: %d\n", car->x, car->y, car->direction, car->speed);
        car = car->next;
    }
}

int main() {
    srand(time(NULL));

    Car* head = createCar();
    Car* tail = head;

    for (int i = 0; i < MAX_CARS - 1; i++) {
        tail->next = createCar();
        tail = tail->next;
    }

    displayCars(head);

    for (int i = 0; i < 10; i++) {
        moveCar(head);
        displayCars(head);
        sleep(1);
    }

    return 0;
}