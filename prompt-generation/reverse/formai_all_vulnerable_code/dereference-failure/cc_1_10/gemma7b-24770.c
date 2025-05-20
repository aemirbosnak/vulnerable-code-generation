//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct car
{
    int x, y, direction, speed;
    struct car* next;
} car;

car* createCar()
{
    car* newCar = (car*)malloc(sizeof(car));
    newCar->x = rand() % MAX_LANE;
    newCar->y = rand() % MAX_CARS;
    newCar->direction = rand() % 2;
    newCar->speed = rand() % 5 + 1;
    newCar->next = NULL;
    return newCar;
}

void moveCar(car* car)
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
        car->speed = rand() % 5 + 1;
        car->direction = rand() % 2;
    }
}

int main()
{
    srand(time(NULL));

    car* head = createCar();
    car* tail = head;

    while (tail->next)
    {
        moveCar(tail);
        tail = tail->next;
    }

    moveCar(head);

    return 0;
}