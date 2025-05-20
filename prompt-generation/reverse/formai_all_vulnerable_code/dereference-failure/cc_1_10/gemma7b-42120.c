//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 5

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
        (*head)->x = rand() % 1000;
        (*head)->y = rand() % 1000;
        (*head)->direction = rand() % 4;
        (*head)->speed = rand() % 5;
        (*head)->next = NULL;
        head = &((*head)->next);
    }
}

void simulateTrafficFlow(Car* head)
{
    time_t start = time(NULL);
    while (time(NULL) - start < 10)
    {
        for (Car* car = head; car; car = car->next)
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
            if (car->speed > 10)
                car->speed = 10;
        }

        sleep(1);
    }
}

int main()
{
    Car* head = NULL;
    initializeCars(&head);
    simulateTrafficFlow(head);

    return 0;
}