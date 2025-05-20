//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: irregular
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 5

typedef struct Car {
    int x, y, dir, speed;
    struct Car* next;
} Car;

Car* head = NULL;

void addCar() {
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->x = rand() % 1000;
    newCar->y = rand() % 1000;
    newCar->dir = rand() % 4;
    newCar->speed = rand() % 5;
    newCar->next = head;
    head = newCar;
}

void moveCars() {
    Car* currentCar = head;
    while (currentCar) {
        switch (currentCar->dir) {
            case 0:
                currentCar->x++;
                break;
            case 1:
                currentCar->x--;
                break;
            case 2:
                currentCar->y++;
                break;
            case 3:
                currentCar->y--;
                break;
        }
        currentCar->speed++;
        currentCar = currentCar->next;
    }
}

void drawCars() {
    Car* currentCar = head;
    while (currentCar) {
        printf("(");
        printf("%d, %d)", currentCar->x, currentCar->y);
        printf(") ");
        currentCar = currentCar->next;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < MAX_CARS; i++) {
        addCar();
    }
    moveCars();
    drawCars();
    return 0;
}