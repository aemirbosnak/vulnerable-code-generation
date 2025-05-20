//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 3
#define NUM_CARS 10

typedef struct Car
{
    int lane;
    int speed;
    int position;
    struct Car* next;
} Car;

void simulateTrafficFlow()
{
    Car* head = NULL;
    for (int i = 0; i < NUM_CARS; i++)
    {
        Car* newCar = (Car*)malloc(sizeof(Car));
        newCar->lane = rand() % NUM_LANE;
        newCar->speed = rand() % 10;
        newCar->position = rand() % 100;
        newCar->next = head;
        head = newCar;
    }

    time_t tStart = time(NULL);
    time_t tEnd = tStart + 10;

    while (time(NULL) < tEnd)
    {
        for (Car* car = head; car; car = car->next)
        {
            car->position += car->speed;
            if (car->position >= 100)
            {
                car->position = 0;
            }
        }

        sleep(1);
    }

    free(head);
}

int main()
{
    simulateTrafficFlow();

    return 0;
}