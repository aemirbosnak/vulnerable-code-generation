//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car
{
    int lane;
    int position;
    int speed;
    struct Car* next;
} Car;

Car* createCar(int lane, int position, int speed)
{
    Car* car = (Car*)malloc(sizeof(Car));
    car->lane = lane;
    car->position = position;
    car->speed = speed;
    car->next = NULL;
    return car;
}

void simulateTrafficFlow(Car* head)
{
    while (head)
    {
        // Move car forward
        head->position++;

        // Change lane if necessary
        if (head->speed > 0)
        {
            if (head->position % MAX_LANE == 0)
            {
                head->lane++;
            }
        }

        // Check if car has reached its destination
        if (head->position >= MAX_LANE * MAX_CARS)
        {
            // Free car
            free(head);
            head = NULL;
        }

        head = head->next;
    }
}

int main()
{
    Car* head = createCar(1, 0, 5);
    head = createCar(2, 0, 3);
    head = createCar(2, MAX_LANE - 1, 2);

    simulateTrafficFlow(head);

    return 0;
}