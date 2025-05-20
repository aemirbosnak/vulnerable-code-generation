//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: satisfied
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 5
#define MAX_ROAD_LENGTH 20

typedef struct Car
{
    int x, y, direction, speed;
    struct Car* next;
} Car;

Car* createCar()
{
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->x = rand() % MAX_ROAD_LENGTH;
    newCar->y = rand() % MAX_ROAD_LENGTH;
    newCar->direction = rand() % 4;
    newCar->speed = rand() % 3 + 1;
    newCar->next = NULL;
    return newCar;
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
        car->speed = rand() % 3 + 1;
    }
}

void printRoad(Car* car)
{
    for (int i = 0; i < MAX_ROAD_LENGTH; i++)
    {
        for (int j = 0; j < MAX_ROAD_LENGTH; j++)
        {
            if (car->x == i && car->y == j)
            {
                printf("C ");
            }
            else
            {
                printf("O ");
            }
        }

        printf("\n");
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

    while (1)
    {
        moveCars(head);
        printRoad(head);

        if (head->speed == 0)
        {
            break;
        }

        sleep(1);
    }

    return 0;
}