//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define NUM_FLOORS 5
#define BUTTON_COUNT 4

typedef struct Elevator
{
    int currentFloor;
    int direction;
    int passengers;
    struct Elevator *next;
} Elevator;

Elevator *head = NULL;

void addPassenger(int floor, int numPassengers)
{
    Elevator *newElevator = (Elevator *)malloc(sizeof(Elevator));
    newElevator->currentFloor = floor;
    newElevator->direction = 0;
    newElevator->passengers = numPassengers;
    newElevator->next = NULL;

    if (head == NULL)
    {
        head = newElevator;
    }
    else
    {
        Elevator *prev = head;
        while (prev->next)
        {
            prev = prev->next;
        }
        prev->next = newElevator;
    }
}

void moveElevator(int destinationFloor)
{
    Elevator *current = head;

    while (current)
    {
        if (current->currentFloor == destinationFloor)
        {
            current->direction = 0;
            printf("Elevator reached floor %d.\n", current->currentFloor);
            return;
        }
        else if (current->direction == 0)
        {
            int direction = destinationFloor - current->currentFloor;
            current->direction = direction;
            current->currentFloor += direction;
            printf("Elevator moving towards floor %d.\n", current->currentFloor);
        }
        current = current->next;
    }

    printf("Error: elevator not found.\n");
}

int main()
{
    addPassenger(2, 3);
    addPassenger(4, 2);
    addPassenger(3, 1);

    moveElevator(3);

    return 0;
}