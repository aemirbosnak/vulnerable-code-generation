//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Sherlock Holmes
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

void initialize_cars(Car** head)
{
    *head = NULL;
    for (int i = 0; i < MAX_CARS; i++)
    {
        Car* new_car = malloc(sizeof(Car));
        new_car->lane = rand() % MAX_LANE;
        new_car->position = rand() % 1000;
        new_car->speed = rand() % 10;
        new_car->direction = rand() % 2;
        new_car->next = *head;
        *head = new_car;
    }
}

void simulate_traffic_flow(Car* head)
{
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < 60)
    {
        for (Car* current_car = head; current_car; current_car = current_car->next)
        {
            switch (current_car->direction)
            {
                case 0:
                    current_car->position++;
                    break;
                case 1:
                    current_car->position--;
                    break;
            }

            if (current_car->position >= 1000)
            {
                current_car->position = 0;
            }
            if (current_car->position <= 0)
            {
                current_car->position = 1000;
            }
        }

        sleep(1);
    }
}

int main()
{
    Car* head = NULL;
    initialize_cars(&head);
    simulate_traffic_flow(head);
    return 0;
}