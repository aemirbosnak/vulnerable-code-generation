//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car
{
    int x, y, speed, direction, lane;
    struct Car* next;
} Car;

void create_car(Car** head)
{
    *head = malloc(sizeof(Car));
    (*head)->x = 0;
    (*head)->y = 0;
    (*head)->speed = 1;
    (*head)->direction = 0;
    (*head)->lane = 0;
    (*head)->next = NULL;
}

void move_car(Car* car)
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

    if (car->x > MAX_LANE - 1)
    {
        car->direction = 2;
    }
    if (car->x < 0)
    {
        car->direction = 0;
    }
    if (car->y > MAX_CARS - 1)
    {
        car->direction = 3;
    }
    if (car->y < 0)
    {
        car->direction = 1;
    }
}

int main()
{
    Car* head = NULL;
    create_car(&head);

    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        move_car(head);
    }

    return 0;
}