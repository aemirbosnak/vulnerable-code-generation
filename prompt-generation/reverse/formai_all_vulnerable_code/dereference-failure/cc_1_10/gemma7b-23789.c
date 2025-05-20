//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car
{
    int x, y, direction, speed;
    struct Car* next;
} Car;

void initialize_cars(Car** head)
{
    *head = NULL;
    for (int i = 0; i < MAX_CARS; i++)
    {
        Car* new_car = malloc(sizeof(Car));
        new_car->x = i;
        new_car->y = 0;
        new_car->direction = 1;
        new_car->speed = 1;
        new_car->next = NULL;

        if (*head == NULL)
        {
            *head = new_car;
        }
        else
        {
            (*head)->next = new_car;
            *head = new_car;
        }
    }
}

void simulate_traffic(Car** head)
{
    time_t start_time = time(NULL);

    while (time(NULL) - start_time < 10)
    {
        for (Car* current_car = *head; current_car; current_car = current_car->next)
        {
            switch (current_car->direction)
            {
                case 1:
                    current_car->x++;
                    break;
                case 2:
                    current_car->x--;
                    break;
                case 3:
                    current_car->y++;
                    break;
                case 4:
                    current_car->y--;
                    break;
            }

            current_car->speed++;

            if (current_car->speed > 5)
            {
                current_car->speed = 5;
            }
        }

        sleep(1);
    }
}

int main()
{
    Car* head = NULL;
    initialize_cars(&head);
    simulate_traffic(&head);

    return 0;
}