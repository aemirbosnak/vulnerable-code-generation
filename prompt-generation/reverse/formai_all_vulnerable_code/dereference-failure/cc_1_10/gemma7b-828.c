//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
    int x, y, direction, speed;
    char name[20];
} Car;

void move_cars(Car *cars) {
    for (int i = 0; i < MAX_CARS; i++) {
        switch (cars[i].direction) {
            case 0: // North
                cars[i].y++;
                break;
            case 1: // East
                cars[i].x++;
                break;
            case 2: // South
                cars[i].y--;
                break;
            case 3: // West
                cars[i].x--;
                break;
        }
    }
}

int main() {
    Car cars[MAX_CARS];
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].x = rand() % 10;
        cars[i].y = rand() % 10;
        cars[i].direction = rand() % 4;
        cars[i].speed = rand() % 5;
        strcpy(cars[i].name, "Car " + i);
    }

    time_t start_time = time(NULL);
    while (time(NULL) - start_time < 60) {
        move_cars(cars);
        for (int i = 0; i < MAX_CARS; i++) {
            printf("%s is at (%d, %d)\n", cars[i].name, cars[i].x, cars[i].y);
        }
        printf("\n");
        sleep(1);
    }

    return 0;
}