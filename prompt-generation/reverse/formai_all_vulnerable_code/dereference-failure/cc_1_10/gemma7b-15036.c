//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car
{
    int x, y, direction, speed;
    struct Car* next;
} Car;

void initializeCars(Car** head)
{
    *head = NULL;
    for (int i = 0; i < MAX_CARS; i++)
    {
        *head = malloc(sizeof(Car));
        (*head)->x = rand() % 10;
        (*head)->y = rand() % 10;
        (*head)->direction = rand() % 2;
        (*head)->speed = rand() % 3;
        (*head)->next = NULL;
        head = &((*head)->next);
    }
}

void simulateTrafficFlow(Car** head)
{
    time_t start = time(NULL);
    while (time(NULL) - start < 60)
    {
        for (Car* car = *head; car; car = car->next)
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

            car->speed++;
            if (car->speed > 5)
                car->speed = 5;
        }

        sleep(1);
    }
}

int main()
{
    Car** head = NULL;
    initializeCars(head);
    simulateTrafficFlow(head);

    return 0;
}