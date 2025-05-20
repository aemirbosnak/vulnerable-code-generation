//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARS 10
#define MAX_LANE 3

// Define car structure
typedef struct Car
{
    int lane;
    int position;
    int speed;
    struct Car* next;
} Car;

// Function to simulate traffic flow
void simulateTrafficFlow(Car* head)
{
    // Iterate over cars and move them forward
    Car* currentCar = head;
    while (currentCar)
    {
        currentCar->position++;

        // If car reaches end of lane, move to next lane
        if (currentCar->position == MAX_LANE - 1)
        {
            currentCar->lane++;

            // If car reaches end of road, move to the beginning
            if (currentCar->lane == MAX_LANE - 1)
            {
                currentCar->position = 0;
            }
        }

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
        newCar->position = rand() % MAX_LANE;
        newCar->speed = rand() % 10;
        newCar->next = head;
        head = newCar;
    }

    // Simulate traffic flow
    simulateTrafficFlow(head);

    // Print final positions of cars
    Car* currentCar = head;
    while (currentCar)
    {
        printf("Car %d is at position %d in lane %d\n", currentCar->position, currentCar->lane);
        currentCar = currentCar->next;
    }

    return 0;
}