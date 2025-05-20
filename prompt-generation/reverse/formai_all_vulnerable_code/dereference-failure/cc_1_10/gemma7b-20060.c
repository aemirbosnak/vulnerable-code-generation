//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 20

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
    car->speed++;
}

void simulateTrafficFlow(int numCars) {
    Car* head = NULL;
    for (int i = 0; i < numCars; i++) {
        Car* car = createCar(rand() % 10, rand() % 10, rand() % 4, rand() % 5);
        if (head) {
            car->next = head;
        }
        head = car;
    }

    time_t start = time(NULL);
    while (time(NULL) - start < 60) {
        moveCar(head);
        printf("%d, %d, %d, %d\n", head->x, head->y, head->direction, head->speed);
    }
}

int main() {
    simulateTrafficFlow(10);
    return 0;
}