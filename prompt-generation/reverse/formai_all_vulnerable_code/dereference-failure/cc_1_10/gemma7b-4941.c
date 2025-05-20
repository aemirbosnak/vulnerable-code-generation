//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 20
#define MAX_LANE 3

typedef struct Car
{
    int lane;
    int position;
    int speed;
    struct Car* next;
} Car;

Car* createCar(int lane, int position, int speed)
{
    Car* car = malloc(sizeof(Car));
    car->lane = lane;
    car->position = position;
    car->speed = speed;
    car->next = NULL;

    return car;
}

void moveCar(Car* car, int direction)
{
    switch (direction)
    {
        case 0:
            car->position++;
            break;
        case 1:
            car->position--;
            break;
        default:
            break;
    }
}

void simulateTrafficFlow(int numCars)
{
    Car* head = NULL;

    for (int i = 0; i < numCars; i++)
    {
        Car* car = createCar(rand() % MAX_LANE, rand() % MAX_LANE, rand() % 10);
        moveCar(car, rand() % 2);
        head = car;
    }

    while (head)
    {
        printf("Car at lane %d, position %d, speed %d\n", head->lane, head->position, head->speed);
        moveCar(head, rand() % 2);
        head = head->next;
    }
}

int main()
{
    simulateTrafficFlow(10);

    return 0;
}