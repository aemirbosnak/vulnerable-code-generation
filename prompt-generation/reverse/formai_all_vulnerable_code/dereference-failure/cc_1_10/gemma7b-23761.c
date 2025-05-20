//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car
{
    int position;
    int direction;
    struct Car* next;
} Car;

void createCar(Car** head)
{
    *head = malloc(sizeof(Car));
    (*head)->position = 0;
    (*head)->direction = 1;
    (*head)->next = NULL;
}

void moveCar(Car* car)
{
    switch (car->direction)
    {
        case 1:
            car->position++;
            break;
        case 2:
            car->position--;
            break;
    }
}

void displayCars(Car* head)
{
    while (head)
    {
        printf("Car position: %d, direction: %d\n", head->position, head->direction);
        head = head->next;
    }
}

int main()
{
    Car* head = NULL;
    createCar(&head);

    for (int i = 0; i < MAX_CARS; i++)
    {
        createCar(&head);
    }

    displayCars(head);

    time_t t = time(NULL);
    while (time(NULL) - t < 10)
    {
        for (Car* car = head; car; car = car->next)
        {
            moveCar(car);
        }

        displayCars(head);

        sleep(1);
    }

    return 0;
}