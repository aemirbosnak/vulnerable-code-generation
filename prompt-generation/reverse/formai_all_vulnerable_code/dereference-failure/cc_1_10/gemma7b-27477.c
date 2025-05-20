//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_ROAD 10

typedef struct Car
{
    int x, y, direction, speed;
    struct Car* next;
} Car;

Car* createCar()
{
    Car* car = (Car*)malloc(sizeof(Car));
    car->x = rand() % MAX_ROAD;
    car->y = rand() % MAX_ROAD;
    car->direction = rand() % 4;
    car->speed = rand() % 5 + 1;
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

    car->x = (car->x + MAX_ROAD) % MAX_ROAD;
    car->y = (car->y + MAX_ROAD) % MAX_ROAD;
}

int main()
{
    srand(time(NULL));

    Car* head = createCar();
    Car* tail = head;

    for (int i = 0; i < MAX_CARS; i++)
    {
        tail = createCar();
        tail->next = head;
        head = tail;
    }

    for (int i = 0; i < 1000; i++)
    {
        moveCar(head);
    }

    return 0;
}