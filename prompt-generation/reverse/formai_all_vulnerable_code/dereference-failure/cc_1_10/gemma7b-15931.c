//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
    int x, y, direction, speed;
    struct Car* next;
} Car;

void createCar(Car** head) {
    *head = malloc(sizeof(Car));
    (*head)->x = 0;
    (*head)->y = 0;
    (*head)->direction = 0;
    (*head)->speed = 1;
    (*head)->next = NULL;
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
}

void collisionCheck(Car* car) {
    if (car->x < 0 || car->x >= 5) {
        car->direction = (car->direction + 1) % 4;
    }
    if (car->y < 0 || car->y >= 5) {
        car->direction = (car->direction + 1) % 4;
    }
}

void trafficFlowSimulation(int numCars) {
    Car** head = NULL;
    for (int i = 0; i < numCars; i++) {
        createCar(&head);
    }

    srand(time(NULL));
    for (int t = 0; t < 1000; t++) {
        for (Car* car = head; car; car = car->next) {
            moveCar(car);
            collisionCheck(car);
        }

        // Print the traffic flow
        for (Car* car = head; car; car = car->next) {
            printf("Car: (%d, %d), Direction: %d, Speed: %d\n", car->x, car->y, car->direction, car->speed);
        }
        printf("\n");
    }

    return;
}

int main() {
    trafficFlowSimulation(5);
    return 0;
}