//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct car {
    int x, y, direction, speed;
    struct car* next;
} car;

void simulateTrafficFlow(car* head) {
    time_t t = time(NULL);
    int i = 0;
    while (time(NULL) - t < 10) {
        for (car* current = head; current; current = current->next) {
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

            current->speed++;
            if (current->speed > 5) {
                current->speed = 5;
            }
        }

        t = time(NULL);
        i++;
    }

    for (car* current = head; current; current = current->next) {
        printf("Car position: (%d, %d)\n", current->x, current->y);
    }
}

int main() {
    car* head = NULL;

    // Create a few cars
    for (int i = 0; i < MAX_CARS; i++) {
        car* newCar = malloc(sizeof(car));
        newCar->x = i;
        newCar->y = i;
        newCar->direction = rand() % 4;
        newCar->speed = rand() % 5 + 1;
        newCar->next = head;
        head = newCar;
    }

    simulateTrafficFlow(head);

    return 0;
}