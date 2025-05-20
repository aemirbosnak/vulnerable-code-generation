//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: lively
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car
{
    int lane;
    int position;
    int speed;
    int direction;
    struct Car* next;
} Car;

Car* createCar()
{
    Car* car = (Car*)malloc(sizeof(Car));
    car->lane = rand() % MAX_LANE;
    car->position = rand() % 100;
    car->speed = rand() % 5;
    car->direction = rand() % 2;
    car->next = NULL;
    return car;
}

void simulateTrafficFlow()
{
    Car* head = createCar();
    Car* tail = head;

    for (int i = 0; i < MAX_CARS; i++)
    {
        tail = createCar();
        tail->next = head;
        head = tail;
    }

    time_t start = time(NULL);
    while (time(NULL) - start < 10)
    {
        for (Car* car = head; car; car = car->next)
        {
            switch (car->direction)
            {
                case 0:
                    car->position++;
                    break;
                case 1:
                    car->position--;
                    break;
            }

            if (car->position >= 100)
            {
                car->direction = 1;
                car->position = 0;
            }
            if (car->position <= 0)
            {
                car->direction = 0;
                car->position = 100;
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