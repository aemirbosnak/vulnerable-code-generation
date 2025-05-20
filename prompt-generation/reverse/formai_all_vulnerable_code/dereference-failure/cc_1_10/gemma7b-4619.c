//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Claude Shannon
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
    int x;
    int y;
    int direction;
    int speed;
    struct Car* next;
} Car;

Car* createCar() {
    Car* car = malloc(sizeof(Car));
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

int main() {
    srand(time(NULL));

    Car* head = createCar();
    Car* tail = head;

    for (int i = 0; i < MAX_CARS; i++) {
        tail->next = createCar();
        tail = tail->next;
    }

    while (1) {
        for (Car* car = head; car; car = car->next) {
            moveCar(car);
        }

        printf("Traffic flow simulation:\n");
        for (Car* car = head; car; car = car->next) {
            printf("Car at (%d, %d) moving in direction %d at speed %d\n", car->x, car->y, car->direction, car->speed);
        }

        sleep(1);
    }

    return 0;
}