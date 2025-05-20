//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 3
#define MAX_CARS 20

typedef struct Car {
    int lane;
    int position;
    int speed;
    struct Car* next;
} Car;

Car* createCar() {
    Car* car = (Car*)malloc(sizeof(Car));
    car->lane = rand() % NUM_LANE;
    car->position = 0;
    car->speed = rand() % 5 + 1;
    car->next = NULL;
    return car;
}

void simulateTrafficFlow() {
    srand(time(NULL));

    Car* head = createCar();
    head->next = createCar();
    head->next->next = createCar();

    for (int i = 0; i < MAX_CARS; i++) {
        Car* car = createCar();
        car->next = head;
        head = car;
    }

    for (int i = 0; i < 1000; i++) {
        for (Car* car = head; car; car = car->next) {
            car->position++;
            if (car->position >= 10) {
                car->position = 0;
            }
            printf("Car at lane %d, position %d, speed %d\n", car->lane, car->position, car->speed);
        }
        printf("\n");
        sleep(1);
    }
}

int main() {
    simulateTrafficFlow();
    return 0;
}