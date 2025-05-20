//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: immersive
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 5
#define MAX_LANE 3

typedef struct Car
{
    int lane;
    int position;
    int speed;
    int direction;
    struct Car* next;
} Car;

Car* createCar()
{
    Car* car = malloc(sizeof(Car));
    car->lane = rand() % MAX_LANE;
    car->position = rand() % 100;
    car->speed = rand() % 5;
    car->direction = rand() % 2;
    car->next = NULL;
    return car;
}

void moveCars(Car* head)
{
    Car* current = head;
    while (current)
    {
        switch (current->direction)
        {
            case 0:
                current->position++;
                break;
            case 1:
                current->position--;
                break;
        }

        current = current->next;
    }
}

void drawCars(Car* head)
{
    Car* current = head;
    while (current)
    {
        printf("Car at lane %d, position %d, speed %d, direction %d\n", current->lane, current->position, current->speed, current->direction);
        current = current->next;
    }
}

int main()
{
    srand(time(NULL));

    Car* head = createCar();
    head = createCar();
    head = createCar();

    moveCars(head);
    drawCars(head);

    return 0;
}