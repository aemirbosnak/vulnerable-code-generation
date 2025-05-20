//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1024

typedef struct Ship
{
    char name[MAX_SIZE];
    int size;
    int crew;
    struct Ship* next;
} Ship;

void spawnShips(Ship** head)
{
    time_t t = time(NULL);
    srand(t);

    int numShips = rand() % 5 + 1;
    for (int i = 0; i < numShips; i++)
    {
        Ship* newShip = malloc(sizeof(Ship));
        newShip->size = rand() % 3 + 1;
        newShip->crew = rand() % 5 + 1;
        newShip->name[0] = 'S' + i;
        newShip->next = *head;
        *head = newShip;
    }
}

void battle(Ship* ship, Ship* enemy)
{
    printf("Battle between %s and %s!\n", ship->name, enemy->name);

    int damage = rand() % ship->size + 1;
    enemy->crew -= damage;

    if (enemy->crew <= 0)
    {
        printf("%s has been destroyed!\n", enemy->name);
        free(enemy);
    }
    else
    {
        printf("%s has taken damage. Remaining crew: %d\n", enemy->name, enemy->crew);
    }
}

int main()
{
    Ship* head = NULL;
    spawnShips(&head);

    Ship* currentShip = head;
    while (currentShip)
    {
        battle(currentShip, head);
        currentShip = currentShip->next;
    }

    return 0;
}