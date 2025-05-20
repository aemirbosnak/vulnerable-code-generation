//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: medieval
#include <stdlib.h>
#include <stdio.h>

#define MAX_CARS 10

typedef struct Car {
    int x;
    int y;
    char direction;
    struct Car* next;
} Car;

Car* head = NULL;

void addCar(int x, int y, char direction) {
    Car* newCar = malloc(sizeof(Car));
    newCar->x = x;
    newCar->y = y;
    newCar->direction = direction;
    newCar->next = head;
    head = newCar;
}

void moveCars() {
    Car* currentCar = head;
    while (currentCar) {
        switch (currentCar->direction) {
            case 'N':
                currentCar->y--;
                break;
            case 'S':
                currentCar->y++;
                break;
            case 'E':
                currentCar->x++;
                break;
            case 'W':
                currentCar->x--;
                break;
        }
        currentCar = currentCar->next;
    }
}

void drawMap() {
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            Car* currentCar = head;
            while (currentCar) {
                if (currentCar->x == x && currentCar->y == y) {
                    printf("%c ", currentCar->direction);
                } else {
                    printf(". ");
                }
            }
            printf("\n");
        }
    }
}

int main() {
    addCar(2, 3, 'N');
    addCar(5, 5, 'E');
    addCar(7, 7, 'S');
    moveCars();
    drawMap();

    return 0;
}