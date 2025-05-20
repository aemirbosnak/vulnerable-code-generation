//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50
#define MAX_LANE 3

typedef struct Car {
    int lane;
    int position;
    int speed;
    struct Car* next;
} Car;

Car* createCar() {
    Car* car = (Car*)malloc(sizeof(Car));
    car->lane = rand() % MAX_LANE;
    car->position = rand() % 1000;
    car->speed = rand() % 10;
    car->next = NULL;
    return car;
}

void simulateTrafficFlow() {
    Car* head = createCar();
    Car* tail = head;

    for (int i = 0; i < MAX_CARS; i++) {
        tail->next = createCar();
        tail = tail->next;
    }

    time_t start = time(NULL);
    time_t end = start + 10;

    while (time(NULL) < end) {
        for (Car* car = head; car; car = car->next) {
            car->position += car->speed;

            if (car->position >= 1000) {
                car->position = 0;
            }

            printf("%d, %d, %d\n", car->lane, car->position, car->speed);
        }

        sleep(1);
    }
}

int main() {
    simulateTrafficFlow();

    return 0;
}