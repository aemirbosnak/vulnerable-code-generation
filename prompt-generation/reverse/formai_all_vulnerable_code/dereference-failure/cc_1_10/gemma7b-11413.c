//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1024

typedef struct spaceship
{
    int x, y, z;
    char name[20];
    struct spaceship *next;
} spaceship;

void initialize_ship(spaceship *ship)
{
    ship->x = 0;
    ship->y = 0;
    ship->z = 0;
    ship->next = NULL;
    ship->name[0] = '\0';
}

void move_ship(spaceship *ship, int dx, int dy, int dz)
{
    ship->x += dx;
    ship->y += dy;
    ship->z += dz;
}

void battle_ship(spaceship *ship)
{
    printf("The ship %s has been destroyed!", ship->name);
}

int main()
{
    spaceship *head = NULL;

    // Create a few ships
    spaceship *ship1 = malloc(sizeof(spaceship));
    initialize_ship(ship1);
    strcpy(ship1->name, "The Millennium Falcon");
    move_ship(ship1, 10, 20, 30);

    spaceship *ship2 = malloc(sizeof(spaceship));
    initialize_ship(ship2);
    strcpy(ship2->name, "The Death Star");
    move_ship(ship2, -5, -10, 15);

    spaceship *ship3 = malloc(sizeof(spaceship));
    initialize_ship(ship3);
    strcpy(ship3->name, "The Razor Crest");
    move_ship(ship3, 20, 0, -20);

    // Link the ships together
    ship1->next = ship2;
    ship2->next = ship3;

    // Simulate battle
    battle_ship(ship2);

    // Print the remaining ships
    spaceship *current_ship = head;
    while (current_ship)
    {
        printf("The ship %s is still alive!\n", current_ship->name);
        current_ship = current_ship->next;
    }

    return 0;
}