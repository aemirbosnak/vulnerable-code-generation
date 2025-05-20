//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car
{
    int x, y, speed, direction, lane;
    struct Car* next;
} Car;

Car* createCar(int x, int y, int speed, int direction, int lane)
{
    Car* car = (Car*)malloc(sizeof(Car));
    car->x = x;
    car->y = y;
    car->speed = speed;
    car->direction = direction;
    car->lane = lane;
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
        case 2:
            car->y++;
            break;
        case 3:
            car->y--;
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
        case 2:
            car->x++;
            break;
        case 3:
            car->x--;
            break;
    }
}

void simulateTrafficFlow(int numCars)
{
    Car* head = NULL;

    for (int i = 0; i < numCars; i++)
    {
        Car* car = createCar(i, 0, 1, 0, 0);
        moveCar(car);
        head = car;
    }

    while (head)
    {
        moveCar(head);
        head = head->next;
    }
}

int main()
{
    simulateTrafficFlow(5);

    return 0;
}