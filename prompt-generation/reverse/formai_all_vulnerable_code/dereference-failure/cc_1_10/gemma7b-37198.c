//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: shocked
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 3
#define NUM_CARS 20

typedef struct Car
{
    int lane;
    int position;
    int speed;
    struct Car* next;
} Car;

Car* head = NULL;

void createCar()
{
    Car* newCar = malloc(sizeof(Car));
    newCar->lane = rand() % NUM_LANE;
    newCar->position = rand() % 1000;
    newCar->speed = rand() % 10;

    newCar->next = head;
    head = newCar;
}

void simulateTrafficFlow()
{
    time_t tStart = time(NULL);
    time_t tEnd = tStart + 5;

    while (time(NULL) < tEnd)
    {
        for (Car* car = head; car; car = car->next)
        {
            car->position += car->speed * time(NULL) - tStart;

            if (car->position > 1000)
            {
                createCar();
                car->position = 0;
            }
        }

        sleep(1);
    }
}

int main()
{
    for (int i = 0; i < NUM_CARS; i++)
    {
        createCar();
    }

    simulateTrafficFlow();

    return 0;
}