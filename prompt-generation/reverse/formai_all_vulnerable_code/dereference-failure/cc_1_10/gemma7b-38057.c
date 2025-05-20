//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARS 10

typedef struct Car
{
    int position;
    int direction;
    int speed;
    struct Car* next;
} Car;

void simulateTrafficFlow(Car* head)
{
    Car* currentCar = head;
    while (currentCar)
    {
        switch (currentCar->direction)
        {
            case 1:
                currentCar->position++;
                if (currentCar->position >= MAX_CARS - 1)
                {
                    currentCar->direction = -1;
                }
                break;
            case -1:
                currentCar->position--;
                if (currentCar->position <= 0)
                {
                    currentCar->direction = 1;
                }
                break;
        }

        currentCar = currentCar->next;
    }
}

int main()
{
    Car* head = NULL;
    for (int i = 0; i < MAX_CARS; i++)
    {
        Car* newCar = malloc(sizeof(Car));
        newCar->position = i;
        newCar->direction = 1;
        newCar->speed = rand() % 5 + 1;
        newCar->next = head;
        head = newCar;
    }

    simulateTrafficFlow(head);

    return 0;
}