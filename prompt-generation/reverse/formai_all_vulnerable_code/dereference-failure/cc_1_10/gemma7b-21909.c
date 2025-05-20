//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Cars 10

typedef struct Car
{
    int x, y, direction, speed;
    struct Car* next;
} Car;

Car* createCar(int x, int y, int direction, int speed)
{
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->x = x;
    newCar->y = y;
    newCar->direction = direction;
    newCar->speed = speed;
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
    car->speed++;
}

int main()
{
    srand(time(NULL));

    Car* head = createCar(0, 0, 0, 5);
    Car* tail = head;

    for (int i = 0; i < MAX_Cars; i++)
    {
        tail = createCar(rand() % 10, rand() % 10, rand() % 4, rand() % 5);
        tail->next = head;
        head = tail;
    }

    for (int t = 0; t < 10; t++)
    {
        for (Car* car = head; car; car = car->next)
        {
            moveCar(car);
        }

        printf("Time: %d\n", t);
        for (Car* car = head; car; car = car->next)
        {
            printf("Car: (%d, %d), Direction: %d, Speed: %d\n", car->x, car->y, car->direction, car->speed);
        }
        printf("\n");
    }

    return 0;
}