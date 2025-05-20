//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car
{
    int x, y, direction, speed;
    struct Car* next;
} Car;

void initialize(Car** head)
{
    *head = NULL;
}

void insertCar(Car** head, int x, int y, int direction, int speed)
{
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->x = x;
    newCar->y = y;
    newCar->direction = direction;
    newCar->speed = speed;
    newCar->next = NULL;

    if (*head == NULL)
    {
        *head = newCar;
    }
    else
    {
        (*head)->next = newCar;
    }
}

void simulateTrafficFlow(Car* head)
{
    while (head)
    {
        switch (head->direction)
        {
            case 0:
                head->x++;
                break;
            case 1:
                head->y++;
                break;
            case 2:
                head->x--;
                break;
            case 3:
                head->y--;
                break;
        }

        head->speed--;

        if (head->speed <= 0)
        {
            insertCar(&head, head->x, head->y, head->direction, 5);
            head = head->next;
        }
    }
}

int main()
{
    Car* head = NULL;
    initialize(&head);

    insertCar(&head, 0, 0, 0, 5);
    insertCar(&head, 1, 0, 1, 5);
    insertCar(&head, 2, 0, 2, 5);
    insertCar(&head, 3, 0, 3, 5);

    simulateTrafficFlow(head);

    return 0;
}