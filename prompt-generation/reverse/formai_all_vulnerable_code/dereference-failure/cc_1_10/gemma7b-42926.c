//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARS 10

typedef struct Car
{
    int position;
    int direction;
    struct Car* next;
} Car;

void simulateTrafficFlow(Car* head)
{
    Car* current = head;
    while (current)
    {
        switch (current->direction)
        {
            case 1:
                current->position++;
                if (current->position >= MAX_CARS - 1)
                {
                    current->direction = 0;
                }
                break;
            case 0:
                current->position--;
                if (current->position <= 0)
                {
                    current->direction = 1;
                }
                break;
        }

        current = current->next;
    }
}

int main()
{
    Car* head = NULL;
    for (int i = 0; i < MAX_CARS; i++)
    {
        Car* newCar = malloc(sizeof(Car));
        newCar->position = i;
        newCar->direction = rand() % 2;
        newCar->next = head;
        head = newCar;
    }

    simulateTrafficFlow(head);

    return 0;
}