//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: systematic
#include <stdlib.h>
#include <stdio.h>

#define MAX_Cars 10
#define Road_Length 20

typedef struct Car
{
    int position;
    int direction;
    struct Car* next;
} Car;

Car* CreateCar(int position, int direction)
{
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->position = position;
    newCar->direction = direction;
    newCar->next = NULL;
    return newCar;
}

void SimulateTrafficFlow(Car* head)
{
    while (head)
    {
        switch (head->direction)
        {
            case 0:
                head->position++;
                break;
            case 1:
                head->position--;
                break;
            case 2:
                head->position++;
                break;
            case 3:
                head->position--;
                break;
        }

        head = head->next;
    }
}

int main()
{
    Car* head = CreateCar(0, 0);
    head->next = CreateCar(Road_Length - 1, 1);
    head->next->next = CreateCar(Road_Length - 1, 0);
    head->next->next->next = CreateCar(0, 3);

    SimulateTrafficFlow(head);

    return 0;
}