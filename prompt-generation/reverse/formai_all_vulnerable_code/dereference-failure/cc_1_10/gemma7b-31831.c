//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_LANE 3
#define MAX_CARS 20

typedef struct Car
{
    int lane;
    int position;
    int speed;
    struct Car* next;
} Car;

void simulateTrafficFlow(Car* head)
{
    Car* currentCar = head;
    while (currentCar)
    {
        // Update car position
        currentCar->position++;

        // Move to next lane if necessary
        if (currentCar->speed > MAX_LANE - 1)
        {
            currentCar->lane++;
        }

        // Check if car has reached its destination
        if (currentCar->position >= MAX_CARS)
        {
            // Free car memory
            free(currentCar);
            currentCar = NULL;
        }

        // Move to next car
        currentCar = currentCar->next;
    }
}

int main()
{
    // Create a linked list of cars
    Car* head = NULL;
    for (int i = 0; i < MAX_CARS; i++)
    {
        Car* newCar = (Car*)malloc(sizeof(Car));
        newCar->lane = rand() % MAX_LANE;
        newCar->position = 0;
        newCar->speed = rand() % 5 + 1;
        newCar->next = head;
        head = newCar;
    }

    // Simulate traffic flow
    simulateTrafficFlow(head);

    return 0;
}