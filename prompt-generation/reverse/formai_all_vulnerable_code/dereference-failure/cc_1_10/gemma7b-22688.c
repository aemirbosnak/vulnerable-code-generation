//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50
#define MAX_ROAD 100

typedef struct Car {
    int position;
    int direction;
    int speed;
    struct Car* next;
} Car;

void createCar(Car** head) {
    *head = (Car*)malloc(sizeof(Car));
    (*head)->position = rand() % MAX_ROAD;
    (*head)->direction = rand() % 2;
    (*head)->speed = rand() % 5 + 1;
    (*head)->next = NULL;
}

void moveCar(Car* car) {
    switch (car->direction) {
        case 0:
            car->position++;
            break;
        case 1:
            car->position--;
            break;
    }

    car->speed--;

    if (car->speed == 0) {
        car->direction = rand() % 2;
        car->speed = rand() % 5 + 1;
    }
}

int main() {
    srand(time(NULL));

    Car* head = NULL;
    createCar(&head);

    for (int i = 0; i < MAX_CARS; i++) {
        createCar(&head);
    }

    for (int i = 0; i < MAX_CARS; i++) {
        moveCar(head);
    }

    return 0;
}