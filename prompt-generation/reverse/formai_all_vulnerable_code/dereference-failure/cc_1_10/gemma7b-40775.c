//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: inquisitive
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
    int position;
    int direction;
    int speed;
    struct Car* next;
} Car;

Car* createCar() {
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->position = 0;
    newCar->direction = 1;
    newCar->speed = 1;
    newCar->next = NULL;
    return newCar;
}

void moveCar(Car* car) {
    switch (car->direction) {
        case 1:
            car->position++;
            break;
        case -1:
            car->position--;
            break;
    }

    if (car->speed > 0) {
        car->position++;
    } else if (car->speed < 0) {
        car->position--;
    }
}

void simulateTrafficFlow(int numCars) {
    Car* head = createCar();
    for (int i = 1; i < numCars; i++) {
        Car* newCar = createCar();
        newCar->position = i;
        newCar->direction = head->direction;
        newCar->speed = 1;
        newCar->next = head;
        head = newCar;
    }

    time_t start = time(NULL);
    while (time(NULL) - start < 10) {
        for (Car* car = head; car; car = car->next) {
            moveCar(car);
        }

        sleep(0.1);
    }

    printf("Traffic flow simulation complete.\n");
}

int main() {
    simulateTrafficFlow(5);
    return 0;
}