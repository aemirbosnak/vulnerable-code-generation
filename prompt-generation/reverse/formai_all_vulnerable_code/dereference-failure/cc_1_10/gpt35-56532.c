//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SHIP_ENERGY_MAX 100
#define PLANET_ENERGY_MAX 50

int ship_energy = SHIP_ENERGY_MAX;
int planet_energy = PLANET_ENERGY_MAX;

typedef enum EntityType {
    ENTITY_PLANET,
    ENTITY_SHIP
} EntityType;

typedef struct Entity {
    EntityType type;
    char* name;
    int energy;
} Entity;

void print_status(Entity* ship, Entity* planet) {
    printf("\nShip Energy: %d/%d\n", ship_energy, SHIP_ENERGY_MAX);
    printf("Planet Energy: %d/%d\n", planet_energy, PLANET_ENERGY_MAX);
    printf("Current Location: %s\n", planet->name);
}

void land(Entity* ship, Entity* planet) {
    print_status(ship, planet);
    if (ship_energy <= 0) {
        printf("\nYour ship is out of energy! Game over.\n");
        exit(0);
    }
    if (planet_energy <= 0) {
        printf("\nThe planet is out of energy! You cannot land here.\n");
        return;
    }
    printf("\nLanding on %s...\n", planet->name);
    planet_energy--;
    ship_energy -= 5;
    print_status(ship, planet);
    printf("\nYou gained 10 energy on %s.\n", planet->name);
    ship_energy += 10;
    print_status(ship, planet);
}

void travel(Entity* ship, Entity* planet_array[], int planet_count) {
    printf("\nAvailable planets to travel to:");
    for (int i = 0; i < planet_count; i++) {
        if (planet_array[i]->energy > 0) {
            printf(" %d. %s", i+1, planet_array[i]->name);
        }
    }
    printf("\nChoose a planet to travel to: ");
    int choice;
    scanf("%d", &choice);
    if (choice > planet_count || planet_array[choice-1]->energy <= 0) {
        printf("\nInvalid choice. Try again.\n");
        return;
    }
    Entity* target_planet = planet_array[choice-1];
    printf("\nTraveling to %s...\n", target_planet->name);
    ship_energy -= 10;
    print_status(ship, target_planet);
    printf("\nYou have successfully arrived at %s.\n", target_planet->name);
    land(ship, target_planet);
}

int main() {
    Entity* ship = malloc(sizeof(Entity));
    Entity* earth = malloc(sizeof(Entity));
    Entity* mars = malloc(sizeof(Entity));
    Entity* neptune = malloc(sizeof(Entity));
    Entity* solar_system[] = {earth, mars, neptune};
    int planet_count = sizeof(solar_system) / sizeof(solar_system[0]);

    // Initialize entities
    ship->type = ENTITY_SHIP;
    ship->name = "Your Ship";
    ship->energy = SHIP_ENERGY_MAX;

    earth->type = ENTITY_PLANET;
    earth->name = "Earth";
    earth->energy = PLANET_ENERGY_MAX;
    
    mars->type = ENTITY_PLANET;
    mars->name = "Mars";
    mars->energy = PLANET_ENERGY_MAX;

    neptune->type = ENTITY_PLANET;
    neptune->name = "Neptune";
    neptune->energy = 0;

    // Start game loop
    printf("Welcome to the Procedural Space Adventure!\n");
    while (true) {
        print_status(ship, earth);
        printf("\nWhat do you want to do? 1. Land on this planet 2. Travel to another planet\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                land(ship, earth);
                break;
            case 2:
                travel(ship, solar_system, planet_count);
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    }

    free(ship);
    free(earth);
    free(mars);
    free(neptune);
    return 0;
}