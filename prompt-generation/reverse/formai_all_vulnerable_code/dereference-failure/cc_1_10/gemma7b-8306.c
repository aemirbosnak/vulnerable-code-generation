//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car
{
    int x, y, direction, speed;
    struct Car* next;
} Car;

void simulateTrafficFlow(Car* head)
{
    time_t t = time(NULL);
    srand(t);

    while (head)
    {
        switch (head->direction)
        {
            case 0: // North
                head->y++;
                break;
            case 1: // South
                head->y--;
                break;
            case 2: // East
                head->x++;
                break;
            case 3: // West
                head->x--;
                break;
        }

        head->speed = rand() % 5 + 1;
        sleep(head->speed);
        head = head->next;
    }
}

int main()
{
    Car* head = NULL;

    // Create a few cars
    for (int i = 0; i < MAX_CARS; i++)
    {
        Car* car = (Car*)malloc(sizeof(Car));
        car->x = rand() % 10;
        car->y = rand() % 10;
        car->direction = rand() % 4;
        car->speed = rand() % 5 + 1;
        car->next = head;
        head = car;
    }

    // Simulate traffic flow
    simulateTrafficFlow(head);

    return 0;
}