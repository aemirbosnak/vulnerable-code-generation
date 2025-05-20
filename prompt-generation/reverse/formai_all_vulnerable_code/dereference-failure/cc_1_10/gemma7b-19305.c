//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 10

typedef struct Car {
    int x, y, facing, speed;
    struct Car* next;
} Car;

void moveCar(Car* car) {
    switch (car->facing) {
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

    if (car->speed > 0) {
        switch (car->speed) {
            case 1:
                sleep(1);
                break;
            case 2:
                sleep(0.5);
                break;
            case 3:
                sleep(0.25);
                break;
        }
    }

    moveCar(car->next);
}

int main() {
    Car* head = malloc(sizeof(Car));
    head->x = 0;
    head->y = 0;
    head->facing = 0;
    head->speed = MAX_SPEED;
    head->next = NULL;

    moveCar(head);

    return 0;
}