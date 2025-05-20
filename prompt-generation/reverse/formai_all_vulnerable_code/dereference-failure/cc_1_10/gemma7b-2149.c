//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
    int x, y, dir, speed;
    struct Car* next;
} Car;

Car* head = NULL;

void addCar() {
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->x = 0;
    newCar->y = 0;
    newCar->dir = 1;
    newCar->speed = 1;
    newCar->next = head;
    head = newCar;
}

void moveCars() {
    Car* currentCar = head;
    while (currentCar) {
        switch (currentCar->dir) {
            case 1:
                currentCar->x++;
                break;
            case 2:
                currentCar->x--;
                break;
            case 3:
                currentCar->y++;
                break;
            case 4:
                currentCar->y--;
                break;
        }
        currentCar = currentCar->next;
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < MAX_CARS; i++) {
        addCar();
    }

    for (int i = 0; i < 1000; i++) {
        moveCars();
    }

    return 0;
}