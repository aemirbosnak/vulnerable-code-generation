//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LANE 3
#define MAX_CARS 10

typedef struct Car {
    int lane;
    int position;
    int speed;
    struct Car* next;
} Car;

Car* createCar() {
    Car* newCar = malloc(sizeof(Car));
    newCar->lane = rand() % MAX_LANE;
    newCar->position = rand() % 100;
    newCar->speed = rand() % 5 + 1;
    newCar->next = NULL;
    return newCar;
}

void simulateTrafficFlow() {
    Car* head = createCar();
    Car* tail = head;

    while (tail->next) {
        tail = tail->next;
    }

    printf("Traffic Flow Simulation:\n");

    for (int i = 0; i < 10; i++) {
        for (Car* car = head; car; car = car->next) {
            car->position += car->speed;
            printf("Car Lane: %d, Position: %d, Speed: %d\n", car->lane, car->position, car->speed);
        }

        printf("\n");
        sleep(1);
    }

    free(head);
}

int main() {
    simulateTrafficFlow();

    return 0;
}