//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car
{
    int lane;
    int position;
    int direction;
    struct Car* next;
} Car;

void createCar(Car** head)
{
    *head = malloc(sizeof(Car));
    (*head)->lane = rand() % MAX_LANE;
    (*head)->position = rand() % 100;
    (*head)->direction = rand() % 2;
    (*head)->next = NULL;
}

void moveCar(Car* car)
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
        car->position = 0;
    }
    else if (car->position < 0)
    {
        car->position = 99;
    }
}

void printCars(Car* head)
{
    Car* currentCar = head;

    while (currentCar)
    {
        printf("Car: lane %d, position %d, direction %d\n", currentCar->lane, currentCar->position, currentCar->direction);
        currentCar = currentCar->next;
    }
}

int main()
{
    Car* head = NULL;
    createCar(&head);
    createCar(&head);
    createCar(&head);
    moveCar(head);
    printCars(head);

    return 0;
}