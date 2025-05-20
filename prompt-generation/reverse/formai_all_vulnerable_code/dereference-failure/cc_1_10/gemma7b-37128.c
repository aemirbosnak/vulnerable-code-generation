//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
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

Car* createCar(int lane, int position, int speed, int direction)
{
    Car* car = (Car*)malloc(sizeof(Car));
    car->lane = lane;
    car->position = position;
    car->speed = speed;
    car->direction = direction;
    car->next = NULL;

    return car;
}

void simulateTrafficFlow(Car* head)
{
    time_t start = time(NULL);
    int elapsedTime = 0;

    while (elapsedTime < 60)
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
                case 2:
                    car->lane++;
                    break;
                case 3:
                    car->lane--;
                    break;
            }

            if (car->position >= MAX_LANE)
            {
                car->direction = 1;
            }
            else if (car->position <= 0)
            {
                car->direction = 0;
            }

            if (car->lane >= MAX_LANE)
            {
                car->direction = 3;
            }
            else if (car->lane <= 0)
            {
                car->direction = 2;
            }
        }

        elapsedTime = time(NULL) - start;
    }

    printf("Traffic flow simulation complete.\n");
}

int main()
{
    Car* head = createCar(0, 0, 2, 0);
    Car* tail = head;

    for (int i = 1; i < MAX_CARS; i++)
    {
        tail = createCar(rand() % MAX_LANE, rand() % MAX_LANE, rand() % 5, rand() % 4);
        tail->next = head;
        head = tail;
    }

    simulateTrafficFlow(head);

    return 0;
}