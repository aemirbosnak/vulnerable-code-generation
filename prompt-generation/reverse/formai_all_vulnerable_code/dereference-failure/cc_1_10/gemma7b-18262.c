//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: visionary
#include <stdlib.h>
#include <time.h>

typedef struct Car {
    int x, y, direction, speed;
    struct Car* next;
} Car;

Car* head = NULL;

void createCar() {
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->x = rand() % 1000;
    newCar->y = rand() % 1000;
    newCar->direction = rand() % 4;
    newCar->speed = rand() % 10;
    newCar->next = head;
    head = newCar;
}

void moveCars() {
    Car* currentCar = head;
    while (currentCar) {
        switch (currentCar->direction) {
            case 0:
                currentCar->x++;
                break;
            case 1:
                currentCar->y++;
                break;
            case 2:
                currentCar->x--;
                break;
            case 3:
                currentCar->y--;
                break;
        }
        currentCar = currentCar->next;
    }
}

void drawCars() {
    Car* currentCar = head;
    while (currentCar) {
        // Draw car at (currentCar->x, currentCar->y)
        printf("Car at (%d, %d)\n", currentCar->x, currentCar->y);
        currentCar = currentCar->next;
    }
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        createCar();
    }
    moveCars();
    drawCars();

    return 0;
}