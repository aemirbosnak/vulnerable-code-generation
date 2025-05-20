//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: genius
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
    struct Car* next;
} Car;

void initialize_traffic_flow(Car** head)
{
    *head = NULL;
    for (int i = 0; i < MAX_CARS; i++)
    {
        Car* new_car = (Car*)malloc(sizeof(Car));
        new_car->lane = rand() % MAX_LANE;
        new_car->position = rand() % 100;
        new_car->speed = rand() % 5 + 1;
        new_car->next = *head;
        *head = new_car;
    }
}

void simulate_traffic_flow(Car* head)
{
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < 10)
    {
        for (Car* car = head; car; car = car->next)
        {
            car->position += car->speed;
            if (car->position >= 100)
            {
                car->position = 0;
            }
            printf("Car at lane %d, position %d, speed %d\n", car->lane, car->position, car->speed);
        }
        sleep(1);
    }
}

int main()
{
    Car* head = NULL;
    initialize_traffic_flow(&head);
    simulate_traffic_flow(head);

    return 0;
}