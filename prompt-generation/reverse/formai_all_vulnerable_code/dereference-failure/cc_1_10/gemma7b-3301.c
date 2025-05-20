//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: recursive
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

void simulateTrafficFlow(Car* head, int time) {
    time++;
    if (time % 50 == 0) {
        spawnCar(head);
    }

    for (Car* car = head; car; car = car->next) {
        switch (car->speed) {
            case 1:
                car->position++;
                break;
            case 2:
                car->position += 2;
                break;
            case 3:
                car->position += 3;
                break;
        }

        if (car->position >= MAX_LANE) {
            car->position = MAX_LANE - 1;
        }

        if (car->position <= 0) {
            car->position = 0;
        }
    }

    simulateTrafficFlow(head, time);
}

int spawnCar(Car* head) {
    Car* newCar = malloc(sizeof(Car));
    newCar->lane = rand() % MAX_LANE;
    newCar->position = 0;
    newCar->speed = rand() % 3 + 1;
    newCar->next = head;
    head = newCar;
    return 0;
}

int main() {
    Car* head = NULL;
    simulateTrafficFlow(head, 0);
    return 0;
}