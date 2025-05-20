//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car
{
    int x, y, direction, speed, fuel;
    struct Car* next;
} Car;

Car* createCar()
{
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->x = rand() % 1000;
    newCar->y = rand() % 1000;
    newCar->direction = rand() % 4;
    newCar->speed = rand() % 5;
    newCar->fuel = 100;
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

    car->fuel--;
    if (car->fuel <= 0)
    {
        car->fuel = 100;
        car->x = rand() % 1000;
        car->y = rand() % 1000;
    }
}

void simulateTrafficFlow(int numCars)
{
    Car* head = NULL;
    for (int i = 0; i < numCars; i++)
    {
        Car* newCar = createCar();
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
    simulateTrafficFlow(MAX_CARS);
    return 0;
}