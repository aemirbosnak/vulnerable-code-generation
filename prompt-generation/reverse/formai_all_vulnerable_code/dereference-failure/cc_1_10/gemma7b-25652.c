//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
    int x, y, direction, speed;
    struct Car* next;
} Car;

void createCar(Car** head) {
    *head = malloc(sizeof(Car));
    (*head)->x = 0;
    (*head)->y = 0;
    (*head)->direction = 1;
    (*head)->speed = 1;
    (*head)->next = NULL;
}

void moveCar(Car* car) {
    switch (car->direction) {
        case 1:
            car->x++;
            break;
        case 2:
            car->y++;
            break;
        case 3:
            car->x--;
            break;
        case 4:
            car->y--;
            break;
    }

    car->speed++;
}

void simulateTrafficFlow(Car** head) {
    time_t t = time(NULL);
    while (time(NULL) - t < 10) {
        for (Car* car = *head; car; car = car->next) {
            moveCar(car);
        }

        t = time(NULL);
    }
}

int main() {
    Car* head = NULL;
    createCar(&head);

    simulateTrafficFlow(&head);

    return 0;
}