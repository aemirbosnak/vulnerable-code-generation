//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: ultraprecise
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
    int x, y, direction, speed;
    struct Car* next;
} Car;

Car* createCar() {
    Car* newCar = malloc(sizeof(Car));
    newCar->x = rand() % 1000;
    newCar->y = rand() % 1000;
    newCar->direction = rand() % 4;
    newCar->speed = rand() % 5 + 1;
    newCar->next = NULL;
    return newCar;
}

void moveCar(Car* car) {
    switch (car->direction) {
        case 0:
            car->x += car->speed;
            break;
        case 1:
            car->y += car->speed;
            break;
        case 2:
            car->x -= car->speed;
            break;
        case 3:
            car->y -= car->speed;
            break;
    }
}

void collide(Car* car1, Car* car2) {
    if (car1->x == car2->x && car1->y == car2->y) {
        printf("Collision!\n");
        car1->x = rand() % 1000;
        car1->y = rand() % 1000;
        car2->x = rand() % 1000;
        car2->y = rand() % 1000;
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

    for (int i = 0; i < 1000; i++) {
        moveCar(head);
        collide(head, tail);
    }

    return 0;
}