//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 5
#define MAX_LANE 3

typedef struct car
{
    int lane;
    int position;
    int direction;
    struct car* next;
} car;

void initialize_cars(car** head)
{
    *head = NULL;
    for (int i = 0; i < MAX_CARS; i++)
    {
        car* new_car = malloc(sizeof(car));
        new_car->lane = rand() % MAX_LANE;
        new_car->position = rand() % MAX_LANE;
        new_car->direction = rand() % 2;
        new_car->next = *head;
        *head = new_car;
    }
}

void simulate_traffic(car* head)
{
    time_t start_time = time(NULL);
    time_t end_time = start_time + 10;

    while (time(NULL) < end_time)
    {
        for (car* current_car = head; current_car; current_car = current_car->next)
        {
            switch (current_car->direction)
            {
                case 0:
                    current_car->position++;
                    if (current_car->position == MAX_LANE)
                    {
                        current_car->direction = 1;
                        current_car->position = 0;
                    }
                    break;
                case 1:
                    current_car->position--;
                    if (current_car->position == 0)
                    {
                        current_car->direction = 0;
                        current_car->position = MAX_LANE - 1;
                    }
                    break;
            }
        }

        sleep(1);
    }
}

int main()
{
    car* head = NULL;
    initialize_cars(&head);
    simulate_traffic(head);

    return 0;
}