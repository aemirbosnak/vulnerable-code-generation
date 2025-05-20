//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARS 20

typedef struct Car
{
    int position;
    int direction;
    struct Car* next;
} Car;

void createCar(int position, int direction, Car** head)
{
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->position = position;
    newCar->direction = direction;
    newCar->next = NULL;

    if (*head == NULL)
    {
        *head = newCar;
    }
    else
    {
        (*head)->next = newCar;
    }
}

void moveCar(Car* car)
{
    switch (car->direction)
    {
        case 0:
            car->position++;
            break;
        case 1:
            car->position--;
            break;
        case 2:
            car->position++;
            break;
        case 3:
            car->position--;
            break;
    }
}

void simulateTrafficFlow(int numCars)
{
    Car* head = NULL;

    for (int i = 0; i < numCars; i++)
    {
        createCar(i, rand() % 4, &head);
    }

    for (int t = 0; t < 1000; t++)
    {
        for (Car* car = head; car; car = car->next)
        {
            moveCar(car);
        }

        printf("Time: %d, Cars: %d\n", t, numCars);
    }
}

int main()
{
    simulateTrafficFlow(10);

    return 0;
}