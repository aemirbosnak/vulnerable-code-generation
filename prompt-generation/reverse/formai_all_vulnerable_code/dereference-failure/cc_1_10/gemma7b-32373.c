//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car
{
    int x, y, dir, speed;
    struct Car* next;
} Car;

Car* createCar()
{
    Car* car = (Car*)malloc(sizeof(Car));
    car->x = rand() % 1000;
    car->y = rand() % 1000;
    car->dir = rand() % 4;
    car->speed = rand() % 5;
    car->next = NULL;
    return car;
}

void moveCar(Car* car)
{
    switch (car->dir)
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
    if (car->speed > 10)
    {
        car->speed = 10;
    }
}

void displayCars(Car* car)
{
    while (car)
    {
        printf("Car: x=%d, y=%d, dir=%d, speed=%d\n", car->x, car->y, car->dir, car->speed);
        car = car->next;
    }
}

int main()
{
    srand(time(NULL));

    Car* head = createCar();
    Car* tail = head;

    for (int i = 0; i < MAX_CARS; i++)
    {
        tail->next = createCar();
        tail = tail->next;
    }

    displayCars(head);

    for (int i = 0; i < 10; i++)
    {
        moveCar(head);
        displayCars(head);
        sleep(1);
    }

    return 0;
}