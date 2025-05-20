//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_TREASURES 5

typedef struct {
    char name[20];
    int treasures[MAX_TREASURES];
    int treasure_count;
} Planet;

typedef struct {
    char name[20];
    int health;
    int energy;
} Spaceship;

void initialize_planet(Planet *planet, const char *name) {
    strncpy(planet->name, name, sizeof(planet->name));
    planet->treasure_count = rand() % (MAX_TREASURES + 1);
    for (int i = 0; i < planet->treasure_count; i++) {
        planet->treasures[i] = rand() % 100 + 1; // Treasures between 1 and 100
    }
}

void initialize_spaceship(Spaceship *ship, const char *name) {
    strncpy(ship->name, name, sizeof(ship->name));
    ship->health = 100;
    ship->energy = 100;
}

void print_planet(const Planet *planet) {
    printf("Welcome to the planet %s! It has the following treasures:\n", planet->name);
    for (int i = 0; i < planet->treasure_count; i++) {
        printf("Treasure %d: %d units\n", i + 1, planet->treasures[i]);
    }
}

void encounter_spaceship(Spaceship *player_ship, Spaceship *enemy_ship) {
    printf("You encounter a hostile spaceship: %s!\n", enemy_ship->name);
    while (player_ship->health > 0 && enemy_ship->health > 0) {
        printf("You attack %s!\n", enemy_ship->name);
        enemy_ship->health -= 20; // Fixed damage
        printf("%s's health: %d\n", enemy_ship->name, enemy_ship->health);
        
        if (enemy_ship->health <= 0) {
            printf("You destroyed %s!\n", enemy_ship->name);
            return;
        }

        printf("The enemy attacks you!\n");
        player_ship->health -= 15; // Fixed damage
        printf("Your health: %d\n", player_ship->health);
        
        if (player_ship->health <= 0) {
            printf("Your spaceship is destroyed! Game Over!\n");
            exit(0);
        }
        
        // Simulate energy consumption
        player_ship->energy -= 10; 
        if (player_ship->energy <= 0) {
            printf("You have run out of energy and can't fight back!\n");
            exit(0);
        }
    }
}

int main() {
    srand(time(NULL));
    Planet *planets = malloc(MAX_PLANETS * sizeof(Planet));
    Spaceship player_ship = {"Space Explorer", 100, 100};

    // Initialize planets
    initialize_planet(&planets[0], "Planet A");
    initialize_planet(&planets[1], "Planet B");
    initialize_planet(&planets[2], "Planet C");
    
    printf("Welcome to the Space Adventure!\n");
    printf("Your spaceship is named: %s\n", player_ship.name);
    
    for (int i = 0; i < 3; i++) {
        print_planet(&planets[i]);
        
        // Decide if player wants to collect treasures
        char choice;
        printf("Do you want to collect treasures from %s? (y/n): ", planets[i].name);
        scanf(" %c", &choice);
        
        if (choice == 'y') {
            for (int j = 0; j < planets[i].treasure_count; j++) {
                printf("You collected %d units of treasure!\n", planets[i].treasures[j]);
            }
        }

        // Randomly encounter an enemy spaceship
        if (rand() % 2 == 0) {
            Spaceship enemy_ship = {"Hostile Ship", 100, 100};
            encounter_spaceship(&player_ship, &enemy_ship);
        }
    }

    printf("Adventurer, you've successfully explored the space!\n");
    free(planets);
    return 0;
}