//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10

struct Car {
    int x, y, direction, speed;
    struct Car* next;
};

void createCar(struct Car** head) {
    *head = malloc(sizeof(struct Car));
    (*head)->x = 0;
    (*head)->y = 0;
    (*head)->direction = 1;
    (*head)->speed = 1;
    (*head)->next = NULL;
}

void moveCar(struct Car* car) {
    switch (car->direction) {
        case 1:
            car->x++;
            break;
        case 2:
            car->y++;
            break;
        case 3:
            car->x--;
            break;
        case 4:
            car->y--;
            break;
    }
    car->speed++;
}

void simulateTrafficFlow(struct Car* head) {
    while (head) {
        moveCar(head);
        head = head->next;
    }
}

int main() {
    struct Car* head = NULL;
    createCar(&head);
    createCar(&head);
    createCar(&head);
    simulateTrafficFlow(head);
    return 0;
}