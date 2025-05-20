//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
    int x, y, speed, direction;
    struct Car* next;
} Car;

Car* createCar() {
    Car* car = (Car*)malloc(sizeof(Car));
    car->x = rand() % MAX_LANE;
    car->y = rand() % MAX_LANE;
    car->speed = rand() % 3;
    car->direction = rand() % 4;
    car->next = NULL;
    return car;
}

void simulateTrafficFlow() {
    Car* head = createCar();
    Car* tail = head;

    for (int i = 0; i < MAX_CARS; i++) {
        tail = createCar();
        tail->next = head;
        head = tail;
    }

    time_t start = time(NULL);
    time_t end = start + 10;

    while (time(NULL) < end) {
        for (Car* car = head; car; car = car->next) {
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

            if (car->x == MAX_LANE || car->x == -1) {
                car->direction = (car->direction + 1) % 4;
            }

            if (car->y == MAX_LANE || car->y == -1) {
                car->direction = (car->direction + 1) % 4;
            }
        }

        sleep(1);
    }

    free(head);
}

int main() {
    simulateTrafficFlow();

    return 0;
}