//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct car
{
    int x, y, lane, speed, direction;
    struct car* next;
} car;

void create_car(car** head)
{
    *head = malloc(sizeof(car));
    (*head)->x = 0;
    (*head)->y = 0;
    (*head)->lane = 1;
    (*head)->speed = 1;
    (*head)->direction = 1;
    (*head)->next = NULL;
}

void move_car(car* car)
{
    switch (car->direction)
    {
        case 1:
            car->x++;
            break;
        case 2:
            car->x--;
            break;
        case 3:
            car->y++;
            break;
        case 4:
            car->y--;
            break;
    }

    switch (car->lane)
    {
        case 1:
            car->y = 0;
            break;
        case 2:
            car->y = 1;
            break;
        case 3:
            car->y = 2;
            break;
    }
}

void simulate_traffic(car** head)
{
    time_t t;
    int i;

    t = time(NULL);

    for (i = 0; i < MAX_CARS; i++)
    {
        move_car(*head);
        sleep(t);
    }

    printf("Simulation complete!\n");
}

int main()
{
    car* head = NULL;

    create_car(&head);
    create_car(&head);
    create_car(&head);

    simulate_traffic(&head);

    return 0;
}