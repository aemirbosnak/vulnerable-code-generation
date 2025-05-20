//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50
#define MAX_LANE 3

typedef struct Car
{
    int x, y, speed, direction, lane;
    struct Car* next;
} Car;

Car* createCar()
{
    Car* car = malloc(sizeof(Car));
    car->x = rand() % MAX_LANE;
    car->y = rand() % MAX_CARS;
    car->speed = rand() % 5 + 1;
    car->direction = rand() % 2;
    car->lane = rand() % MAX_LANE;
    car->next = NULL;
    return car;
}

void moveCar(Car* car)
{
    switch (car->direction)
    {
        case 0:
            car->x++;
            break;
        case 1:
            car->x--;
            break;
    }

    switch (car->lane)
    {
        case 0:
            car->y++;
            break;
        case 1:
            car->y--;
            break;
    }

    car->speed--;
    if (car->speed == 0)
    {
        car->direction = rand() % 2;
        car->speed = rand() % 5 + 1;
    }
}

void simulateTrafficFlow()
{
    Car* head = createCar();
    while (head)
    {
        moveCar(head);
        head = head->next;
    }
}

int main()
{
    simulateTrafficFlow();
    return 0;
}