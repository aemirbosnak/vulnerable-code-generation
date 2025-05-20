//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: interoperable
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_CARS 50
#define MAX_LANE 3

typedef struct Car
{
    int x, y, speed, lane;
    struct Car* next;
} Car;

void simulateTrafficFlow(Car* head)
{
    while (head)
    {
        // Update car position
        head->x += head->speed * sin(head->lane * M_PI / MAX_LANE);
        head->y += head->speed * cos(head->lane * M_PI / MAX_LANE);

        // Change lane if necessary
        if (head->speed > 0)
        {
            if (head->lane > 0 && head->x >= MAX_LANE - 1)
            {
                head->lane--;
            }
            else if (head->lane < MAX_LANE - 1 && head->x <= 0)
            {
                head->lane++;
            }
        }

        // Move to next car
        head = head->next;
    }
}

int main()
{
    Car* head = NULL;

    // Create some cars
    for (int i = 0; i < MAX_CARS; i++)
    {
        Car* car = (Car*)malloc(sizeof(Car));
        car->x = i;
        car->y = 0;
        car->speed = rand() % 5 + 1;
        car->lane = rand() % MAX_LANE;
        car->next = head;
        head = car;
    }

    // Simulate traffic flow
    simulateTrafficFlow(head);

    // Print car positions
    for (head = head; head; head = head->next)
    {
        printf("Car %d: x = %d, y = %d, lane = %d\n", head->x, head->y, head->lane);
    }

    return 0;
}