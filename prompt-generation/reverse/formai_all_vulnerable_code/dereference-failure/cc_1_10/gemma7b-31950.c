//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: mind-bending
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car
{
    int lane;
    int position;
    int direction;
    struct Car* next;
} Car;

void initialize_cars(Car* head)
{
    head = malloc(MAX_CARS * sizeof(Car));
    for (int i = 0; i < MAX_CARS; i++)
    {
        head[i].lane = rand() % MAX_LANE;
        head[i].position = rand() % 1000;
        head[i].direction = rand() % 2;
        head[i].next = NULL;
    }
}

void simulate_traffic(Car* head)
{
    time_t start = time(NULL);
    while (time(NULL) - start < 60)
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

            if (car->position >= 1000)
            {
                car->direction = 1;
                car->position = 0;
            }
            else if (car->position <= 0)
            {
                car->direction = 0;
                car->position = 1000;
            }
        }

        sleep(1);
    }
}

int main()
{
    Car* head = NULL;
    initialize_cars(head);
    simulate_traffic(head);

    return 0;
}