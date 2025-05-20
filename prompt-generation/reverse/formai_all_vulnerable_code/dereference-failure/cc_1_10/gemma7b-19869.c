//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: genius
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
    int x, y, direction, speed;
    struct Car* next;
} Car;

void simulateTrafficFlow(Car* head) {
    time_t t = time(NULL);
    while (time(NULL) - t < 10) {
        for (Car* car = head; car; car = car->next) {
            switch (car->direction) {
                case 0:
                    car->x++;
                    break;
                case 1:
                    car->x--;
                    break;
                case 2:
                    car->y++;
                    break;
                case 3:
                    car->y--;
                    break;
            }

            if (car->x >= MAX_LANE - 1) {
                car->direction = 1;
            } else if (car->x <= 0) {
                car->direction = 0;
            }

            if (car->y >= MAX_CARS - 1) {
                car->direction = 3;
            } else if (car->y <= 0) {
                car->direction = 2;
            }
        }

        sleep(1);
    }
}

int main() {
    Car* head = NULL;

    for (int i = 0; i < MAX_CARS; i++) {
        Car* car = malloc(sizeof(Car));
        car->x = rand() % MAX_LANE;
        car->y = rand() % MAX_CARS;
        car->direction = rand() % 4;
        car->speed = rand() % 5 + 1;
        car->next = head;
        head = car;
    }

    simulateTrafficFlow(head);

    return 0;
}