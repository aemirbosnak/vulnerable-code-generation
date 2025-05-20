//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define ROAD_LENGTH 100

typedef struct Car
{
    int x, y, speed, direction;
    struct Car* next;
} Car;

Car* createCar()
{
    Car* car = (Car*)malloc(sizeof(Car));
    car->x = rand() % ROAD_LENGTH;
    car->y = rand() % MAX_CARS;
    car->speed = rand() % 5 + 1;
    car->direction = rand() % 4;

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

    car->speed--;
    if (car->speed == 0)
    {
        car->direction = rand() % 4;
        car->speed = rand() % 5 + 1;
    }
}

int main()
{
    srand(time(NULL));

    Car* head = NULL;
    for (int i = 0; i < MAX_CARS; i++)
    {
        Car* car = createCar();
        car->next = head;
        head = car;
    }

    while (head)
    {
        moveCar(head);
        printf("%d, %d\n", head->x, head->y);
    }

    return 0;
}