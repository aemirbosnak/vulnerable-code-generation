//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: enthusiastic
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

void simulateTrafficFlow(Car* head)
{
    time_t start_time = time(NULL);
    time_t current_time = time(NULL);
    int elapsed_time = 0;

    while (elapsed_time < 10)
    {
        current_time = time(NULL);
        elapsed_time = current_time - start_time;

        head->speed = rand() % 5 + 1;
        head->direction = rand() % 2;

        switch (head->direction)
        {
            case 0:
                head->position++;
                break;
            case 1:
                head->position--;
                break;
        }

        if (head->position >= MAX_LANE || head->position <= 0)
        {
            head->direction = (head->direction + 1) % 2;
        }

        head = head->next;
    }
}

int main()
{
    Car* head = NULL;

    for (int i = 0; i < MAX_CARS; i++)
    {
        Car* new_car = malloc(sizeof(Car));
        new_car->lane = rand() % MAX_LANE;
        new_car->position = rand() % MAX_LANE;
        new_car->speed = rand() % 5 + 1;
        new_car->direction = rand() % 2;
        new_car->next = head;
        head = new_car;
    }

    simulateTrafficFlow(head);

    return 0;
}