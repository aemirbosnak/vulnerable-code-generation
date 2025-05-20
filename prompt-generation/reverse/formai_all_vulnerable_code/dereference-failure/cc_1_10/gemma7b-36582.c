//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: safe
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_ROAD_LENGTH 100

typedef struct Car {
    int position;
    int direction;
    int speed;
    struct Car* next;
} Car;

Car* createCar(int position, int direction, int speed) {
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->position = position;
    newCar->direction = direction;
    newCar->speed = speed;
    newCar->next = NULL;
    return newCar;
}

void moveCar(Car* car) {
    switch (car->direction) {
        case 0:
            car->position++;
            break;
        case 1:
            car->position--;
            break;
        case 2:
            car->position++;
            break;
        case 3:
            car->position--;
            break;
    }

    car->speed++;
}

void simulateTrafficFlow(int numCars) {
    Car* head = NULL;
    for (int i = 0; i < numCars; i++) {
        Car* newCar = createCar(rand() % MAX_ROAD_LENGTH, rand() % 4, rand() % 10);
        if (head == NULL) {
            head = newCar;
        } else {
            newCar->next = head;
            head = newCar;
        }
    }

    for (int t = 0; t < 1000; t++) {
        for (Car* car = head; car; car = car->next) {
            moveCar(car);
        }
    }

    printf("Traffic flow simulation complete.\n");
}

int main() {
    simulateTrafficFlow(5);
    return 0;
}