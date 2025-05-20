//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
    int x, y, direction, speed;
    struct Car* next;
} Car;

void initializeCars(Car** head) {
    *head = NULL;
    for (int i = 0; i < MAX_CARS; i++) {
        Car* newCar = malloc(sizeof(Car));
        newCar->x = rand() % MAX_LANE;
        newCar->y = rand() % MAX_LANE;
        newCar->direction = rand() % 2;
        newCar->speed = rand() % 5 + 1;
        newCar->next = *head;
        *head = newCar;
    }
}

void simulateTrafficFlow(Car* head) {
    time_t t = time(NULL);
    int elapsedTime = 0;
    while (elapsedTime < 1000) {
        for (Car* currentCar = head; currentCar; currentCar = currentCar->next) {
            switch (currentCar->direction) {
                case 0:
                    currentCar->x++;
                    break;
                case 1:
                    currentCar->x--;
                    break;
            }
            currentCar->y++;
            elapsedTime++;
            if (time(NULL) - t >= currentCar->speed) {
                t = time(NULL);
                currentCar->speed = rand() % 5 + 1;
            }
        }
    }
}

int main() {
    Car* head = NULL;
    initializeCars(&head);
    simulateTrafficFlow(head);
    return 0;
}