//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car
{
    int lane;
    int position;
    int speed;
    struct Car* next;
} Car;

Car* createCar()
{
    Car* car = (Car*)malloc(sizeof(Car));
    car->lane = rand() % MAX_LANE;
    car->position = rand() % MAX_LANE;
    car->speed = rand() % 5;
    car->next = NULL;
    return car;
}

void moveCar(Car* car)
{
    int direction = rand() % 2;
    switch (direction)
    {
        case 0:
            car->position++;
            break;
        case 1:
            car->position--;
            break;
    }
    car->speed = rand() % 5;
}

void simulateTrafficFlow(int numCars)
{
    Car* head = NULL;
    for (int i = 0; i < numCars; i++)
    {
        Car* car = createCar();
        if (head == NULL)
        {
            head = car;
        }
        else
        {
            car->next = head;
            head = car;
        }
    }

    for (int t = 0; t < 1000; t++)
    {
        for (Car* car = head; car != NULL; car = car->next)
        {
            moveCar(car);
        }
    }

    printf("Traffic flow simulation complete.\n");
}

int main()
{
    simulateTrafficFlow(5);
    return 0;
}