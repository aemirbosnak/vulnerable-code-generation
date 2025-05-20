//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 20

typedef struct Car
{
    int x, y;
    int direction;
    int speed;
    struct Car* next;
} Car;

Car* createCar()
{
    Car* car = (Car*)malloc(sizeof(Car));
    car->x = rand() % 1000;
    car->y = rand() % 1000;
    car->direction = rand() % 4;
    car->speed = rand() % 5;
    car->next = NULL;
    return car;
}

void moveCars(Car* car)
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
    if (car->speed == 0)
    {
        car->direction = rand() % 4;
        car->speed = rand() % 5;
    }
}

void drawCars(Car* car)
{
    printf("Car at (%d, %d) facing %d, speed %d\n", car->x, car->y, car->direction, car->speed);
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

    while (1)
    {
        moveCars(head);
        drawCars(head);
        sleep(1);
    }

    return 0;
}