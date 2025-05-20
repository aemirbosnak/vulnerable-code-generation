//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARS 10

typedef struct car
{
    int x, y, direction, speed;
    struct car* next;
} car;

void simulateTrafficFlow(car* head)
{
    car* currentCar = head;
    while (currentCar)
    {
        switch (currentCar->direction)
        {
            case 0: // North
                currentCar->y++;
                break;
            case 1: // East
                currentCar->x++;
                break;
            case 2: // South
                currentCar->y--;
                break;
            case 3: // West
                currentCar->x--;
                break;
        }

        currentCar = currentCar->next;
    }
}

int main()
{
    car* head = NULL;
    for (int i = 0; i < MAX_CARS; i++)
    {
        head = malloc(sizeof(car));
        head->x = rand() % 10;
        head->y = rand() % 10;
        head->direction = rand() % 4;
        head->speed = rand() % 5;
        head->next = NULL;

        if (head)
        {
            if (head->next == NULL)
            {
                head = head;
            }
            else
            {
                head->next = head;
            }
        }
    }

    simulateTrafficFlow(head);

    return 0;
}