//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_ROAD 10

typedef struct Car
{
    int x, y, direction, speed;
} Car;

void initialize_cars(Car **cars)
{
    for (int i = 0; i < MAX_CARS; i++)
    {
        cars[i] = malloc(sizeof(Car));
        cars[i]->x = rand() % MAX_ROAD;
        cars[i]->y = rand() % MAX_ROAD;
        cars[i]->direction = rand() % 2;
        cars[i]->speed = rand() % 5 + 1;
    }
}

void move_cars(Car **cars)
{
    for (int i = 0; i < MAX_CARS; i++)
    {
        switch (cars[i]->direction)
        {
            case 0:
                cars[i]->x++;
                break;
            case 1:
                cars[i]->x--;
                break;
            case 2:
                cars[i]->y++;
                break;
            case 3:
                cars[i]->y--;
                break;
        }

        cars[i]->speed--;

        if (cars[i]->speed == 0)
        {
            cars[i]->direction = rand() % 2;
            cars[i]->speed = rand() % 5 + 1;
        }
    }
}

int main()
{
    Car **cars = NULL;
    initialize_cars(&cars);
    move_cars(cars);

    return 0;
}