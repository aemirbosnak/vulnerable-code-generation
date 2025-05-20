//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
    int x, y, speed, direction;
    struct Car* next;
} Car;

void initialize_cars(Car** head) {
    *head = NULL;
    for (int i = 0; i < MAX_CARS; i++) {
        *head = malloc(sizeof(Car));
        ((*head)->x = rand() % MAX_LANE);
        ((*head)->y = rand() % MAX_LANE);
        ((*head)->speed = rand() % 5 + 1);
        ((*head)->direction = rand() % 4);
        (*head)->next = NULL;
        head = &((*head)->next);
    }
}

void simulate_traffic(Car* head) {
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < 10) {
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

            if (car->x >= MAX_LANE || car->x < 0) {
                car->direction = (car->direction + 1) % 4;
            }
            if (car->y >= MAX_LANE || car->y < 0) {
                car->direction = (car->direction + 1) % 4;
            }
        }

        sleep(1);
    }
}

int main() {
    Car* head = NULL;
    initialize_cars(&head);
    simulate_traffic(head);
    return 0;
}