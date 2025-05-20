//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 255

typedef struct Ship
{
    char name[MAX_NAME_SIZE];
    int hull_strength;
    int weapon_strength;
    int crew_size;
    struct Ship* next;
} Ship;

Ship* create_ship(char* name, int hull_strength, int weapon_strength, int crew_size)
{
    Ship* new_ship = (Ship*)malloc(sizeof(Ship));
    strcpy(new_ship->name, name);
    new_ship->hull_strength = hull_strength;
    new_ship->weapon_strength = weapon_strength;
    new_ship->crew_size = crew_size;
    new_ship->next = NULL;
    return new_ship;
}

void print_ship(Ship* ship)
{
    printf("Name: %s\n", ship->name);
    printf("Hull Strength: %d\n", ship->hull_strength);
    printf("Weapon Strength: %d\n", ship->weapon_strength);
    printf("Crew Size: %d\n", ship->crew_size);
    printf("\n");
}

int main()
{
    Ship* fleet = NULL;
    Ship* new_ship = create_ship("The Eagle", 10, 8, 50);
    fleet = new_ship;

    print_ship(fleet);

    new_ship = create_ship("The Kraken", 12, 10, 60);
    fleet = new_ship;

    print_ship(fleet);

    new_ship = create_ship("The Phoenix", 14, 9, 70);
    fleet = new_ship;

    print_ship(fleet);

    return 0;
}