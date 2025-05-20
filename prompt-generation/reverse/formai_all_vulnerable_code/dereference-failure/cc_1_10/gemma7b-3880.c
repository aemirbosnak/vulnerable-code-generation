//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
    int lane;
    int position;
    int speed;
    struct Car* next;
} Car;

Car* createCar() {
    Car* car = malloc(sizeof(Car));
    car->lane = rand() % MAX_LANE;
    car->position = rand() % 100;
    car->speed = rand() % 5;
    car->next = NULL;
    return car;
}

void moveCar(Car* car) {
    switch (car->speed) {
        case 0:
            car->position++;
            break;
        case 1:
            car->position += 2;
            break;
        case 2:
            car->position += 3;
            break;
        case 3:
            car->position += 4;
            break;
        case 4:
            car->position += 5;
            break;
    }

    if (car->position >= 100) {
        car->position = 0;
    }
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

    for (int i = 0; i < MAX_CARS; i++) {
        moveCar(head);
        head = head->next;
    }

    printf("Traffic flow simulation complete.\n");
}

int main() {
    simulateTrafficFlow();

    return 0;
}