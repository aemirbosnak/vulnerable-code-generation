//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_SHIP_SIZE 10

typedef struct Ship
{
    char name[MAX_NAME_LENGTH];
    int size;
    struct Ship* next;
} Ship;

typedef struct Universe
{
    Ship* head;
    int numShips;
} Universe;

void createShip(Universe* universe, char* name, int size)
{
    Ship* newShip = malloc(sizeof(Ship));
    strcpy(newShip->name, name);
    newShip->size = size;
    newShip->next = NULL;

    if (universe->head == NULL)
    {
        universe->head = newShip;
    }
    else
    {
        universe->head->next = newShip;
    }
    universe->numShips++;
}

void exploreUniverse(Universe* universe)
{
    Ship* currentShip = universe->head;
    while (currentShip)
    {
        printf("Name: %s, Size: %d\n", currentShip->name, currentShip->size);
        currentShip = currentShip->next;
    }
}

int main()
{
    Universe* universe = malloc(sizeof(Universe));
    universe->head = NULL;
    universe->numShips = 0;

    createShip(universe, "The Millenium Falcon", 5);
    createShip(universe, "The Death Star", 10);
    createShip(universe, "The Millennium Falcon", 5);

    exploreUniverse(universe);

    return 0;
}