//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 3
#define MAX_CARS 10

typedef struct Car {
    int lane;
    int position;
    int speed;
    struct Car* next;
} Car;

Car* createCar(int lane, int position, int speed) {
    Car* car = (Car*)malloc(sizeof(Car));
    car->lane = lane;
    car->position = position;
    car->speed = speed;
    car->next = NULL;
    return car;
}

void simulateTrafficFlow(Car* head) {
    time_t t = time(NULL);
    while (time(NULL) - t < 10) {
        for (Car* car = head; car; car = car->next) {
            switch (car->lane) {
                case 0:
                    car->position++;
                    if (car->position >= MAX_CARS) {
                        car->position = 0;
                    }
                    break;
                case 1:
                    car->position--;
                    if (car->position < 0) {
                        car->position = MAX_CARS - 1;
                    }
                    break;
                case 2:
                    car->position += 2;
                    if (car->position >= MAX_CARS) {
                        car->position = 0;
                    }
                    break;
            }
        }
        t = time(NULL);
    }
}

int main() {
    Car* head = createCar(0, 0, 2);
    head = createCar(1, MAX_CARS - 1, 2);
    head = createCar(2, MAX_CARS - 1, 2);

    simulateTrafficFlow(head);

    return 0;
}