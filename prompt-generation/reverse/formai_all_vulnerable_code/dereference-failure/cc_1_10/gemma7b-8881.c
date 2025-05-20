//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: immersive
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
    int x, y, direction, speed;
    struct Car* next;
} Car;

Car* createCar() {
    Car* car = malloc(sizeof(Car));
    car->x = rand() % 10;
    car->y = rand() % 10;
    car->direction = rand() % 4;
    car->speed = rand() % 3;
    car->next = NULL;
    return car;
}

void simulateTrafficFlow() {
    Car* head = createCar();
    Car* current = head;

    while (current) {
        switch (current->direction) {
            case 0:
                current->x++;
                break;
            case 1:
                current->y++;
                break;
            case 2:
                current->x--;
                break;
            case 3:
                current->y--;
                break;
        }

        current->speed--;

        if (current->speed == 0) {
            current->speed = rand() % 3;
            current->direction = rand() % 4;
        }

        current = current->next;
    }
}

int main() {
    simulateTrafficFlow();

    return 0;
}