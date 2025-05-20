//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARS 10
#define ROAD_LENGTH 100

typedef struct Car
{
    int position;
    int direction;
    struct Car* next;
} Car;

Car* createCar(int position, int direction)
{
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->position = position;
    newCar->direction = direction;
    newCar->next = NULL;
    return newCar;
}

void moveCars(Car* head)
{
    Car* currentCar = head;
    while (currentCar)
    {
        switch (currentCar->direction)
        {
            case 0:
                currentCar->position++;
                break;
            case 1:
                currentCar->position--;
                break;
            case 2:
                currentCar->position++;
                currentCar->direction = 0;
                break;
            case 3:
                currentCar->position--;
                currentCar->direction = 1;
                break;
        }

        currentCar = currentCar->next;
    }
}

int main()
{
    Car* head = createCar(0, 0);
    Car* secondCar = createCar(ROAD_LENGTH - 1, 1);

    head->next = secondCar;

    moveCars(head);

    printf("Car 1 position: %d\n", head->position);
    printf("Car 2 position: %d\n", secondCar->position);

    return 0;
}