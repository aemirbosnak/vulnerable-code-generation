//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: complete
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_SPEED 5

typedef struct Car
{
    int x, y, speed, direction, lane;
    struct Car* next;
} Car;

Car* createCar(int x, int y, int speed, int direction, int lane)
{
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->x = x;
    newCar->y = y;
    newCar->speed = speed;
    newCar->direction = direction;
    newCar->lane = lane;
    newCar->next = NULL;

    return newCar;
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

    car->speed--;
}

void simulateTrafficFlow(int numCars)
{
    Car* head = NULL;
    for (int i = 0; i < numCars; i++)
    {
        Car* newCar = createCar(i + 1, i + 1, MAX_SPEED, 0, i);
        if (head == NULL)
        {
            head = newCar;
        }
        else
        {
            newCar->next = head;
            head = newCar;
        }
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