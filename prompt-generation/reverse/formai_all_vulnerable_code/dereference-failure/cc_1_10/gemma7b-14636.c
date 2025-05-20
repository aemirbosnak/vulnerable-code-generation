//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

typedef struct spaceship
{
    char name[20];
    int fuel;
    int crew;
    struct spaceship* next;
} spaceship;

void createSpaceship( spaceship** head )
{
    *head = malloc( sizeof(spaceship) );
    (*head)->name[0] = '\0';
    (*head)->fuel = 0;
    (*head)->crew = 0;
    (*head)->next = NULL;
}

void addSpaceship( spaceship** head, char* name, int fuel, int crew )
{
    spaceship* newShip = malloc( sizeof(spaceship) );
    newShip->name[0] = '\0';
    newShip->fuel = fuel;
    newShip->crew = crew;
    newShip->next = NULL;

    if (*head == NULL)
    {
        *head = newShip;
    }
    else
    {
        (*head)->next = newShip;
        *head = newShip;
    }
}

int main()
{
    spaceship* head = NULL;

    createSpaceship( &head );
    addSpaceship( &head, "The Millennium Falcon", 100, 5 );
    addSpaceship( &head, "The Death Star", 50, 2 );
    addSpaceship( &head, "The X-wing", 25, 3 );

    spaceship* currentShip = head;

    while (currentShip)
    {
        printf("Name: %s\n", currentShip->name );
        printf("Fuel: %d\n", currentShip->fuel );
        printf("Crew: %d\n", currentShip->crew );
        printf("\n");

        currentShip = currentShip->next;
    }

    return 0;
}