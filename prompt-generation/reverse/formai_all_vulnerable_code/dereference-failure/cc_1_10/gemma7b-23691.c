//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARS 10

typedef struct Car
{
    int x, y, direction, speed;
    struct Car* next;
} Car;

void createCar(Car** head)
{
    *head = malloc(sizeof(Car));
    (*head)->x = 0;
    (*head)->y = 0;
    (*head)->direction = 0;
    (*head)->speed = 1;
    (*head)->next = NULL;
}

void moveCar(Car* car)
{
    switch (car->direction)
    {
        case 0:
            car->x++;
            break;
        case 1:
            car->y++;
            break;
        case 2:
            car->x--;
            break;
        case 3:
            car->y--;
            break;
    }

    car->speed++;
}

int main()
{
    Car* head = NULL;
    createCar(&head);

    for (int i = 0; i < MAX_CARS; i++)
    {
        moveCar(head);
    }

    return 0;
}