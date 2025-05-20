//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 5
#define MAX_LANE 3

typedef struct Car {
    int x, y, direction, speed;
    struct Car* next;
} Car;

void InitializeCars(Car** head) {
    *head = NULL;
    for (int i = 0; i < MAX_CARS; i++) {
        *head = malloc(sizeof(Car));
        (*head)->x = rand() % MAX_LANE;
        (*head)->y = rand() % MAX_LANE;
        (*head)->direction = rand() % 2;
        (*head)->speed = rand() % 5 + 1;
        (*head)->next = NULL;
        head = &((*head)->next);
    }
}

void SimulateTrafficFlow(Car* head) {
    time_t start = time(NULL);
    while (time(NULL) - start < 10) {
        for (Car* car = head; car; car = car->next) {
            switch (car->direction) {
                case 0:
                    car->x++;
                    break;
                case 1:
                    car->x--;
                    break;
            }

            car->y++;

            if (car->x >= MAX_LANE || car->x <= 0) {
                car->direction *= -1;
            }

            if (car->y >= MAX_LANE) {
                car->direction = 1 - car->direction;
            }
        }

        sleep(1);
    }
}

int main() {
    Car* head = NULL;
    InitializeCars(&head);
    SimulateTrafficFlow(head);

    return 0;
}