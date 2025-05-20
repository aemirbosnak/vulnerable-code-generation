//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
    int x, y, dir, speed;
    struct Car* next;
} Car;

Car* createCar() {
    Car* car = (Car*)malloc(sizeof(Car));
    car->x = rand() % 1000;
    car->y = rand() % 1000;
    car->dir = rand() % 4;
    car->speed = rand() % 5 + 1;
    car->next = NULL;
    return car;
}

void simulateTrafficFlow() {
    srand(time(NULL));

    Car* head = createCar();
    Car* tail = head;

    for (int i = 0; i < MAX_CARS; i++) {
        tail = createCar();
        tail->next = head;
        head = tail;
    }

    while (1) {
        for (Car* car = head; car; car = car->next) {
            switch (car->dir) {
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

            car->x = (car->x + car->speed) % 1000;
            car->y = (car->y + car->speed) % 1000;

            printf("Car at (%d, %d) traveling in direction %d with speed %d\n", car->x, car->y, car->dir, car->speed);
        }

        sleep(1);
    }
}

int main() {
    simulateTrafficFlow();

    return 0;
}