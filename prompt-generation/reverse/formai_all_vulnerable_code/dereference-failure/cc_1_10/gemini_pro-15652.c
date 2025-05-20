//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char *name;
    int health;
    int attack;
    int defence;
} Character;

typedef struct {
    char *name;
    int x;
    int y;
} Location;

typedef struct {
    char *name;
    Location *location;
    Character *characters[10];
} Sector;

typedef struct {
    Sector *sectors[10];
} Galaxy;

Character *createCharacter(char *name, int health, int attack, int defence) {
    Character *character = malloc(sizeof(Character));
    character->name = name;
    character->health = health;
    character->attack = attack;
    character->defence = defence;
    return character;
}

Location *createLocation(char *name, int x, int y) {
    Location *location = malloc(sizeof(Location));
    location->name = name;
    location->x = x;
    location->y = y;
    return location;
}

Sector *createSector(char *name, Location *location) {
    Sector *sector = malloc(sizeof(Sector));
    sector->name = name;
    sector->location = location;
    return sector;
}

Galaxy *createGalaxy() {
    Galaxy *galaxy = malloc(sizeof(Galaxy));
    return galaxy;
}

void addCharacterToSector(Sector *sector, Character *character) {
    for (int i = 0; i < 10; i++) {
        if (sector->characters[i] == NULL) {
            sector->characters[i] = character;
            break;
        }
    }
}

void addSectorToGalaxy(Galaxy *galaxy, Sector *sector) {
    for (int i = 0; i < 10; i++) {
        if (galaxy->sectors[i] == NULL) {
            galaxy->sectors[i] = sector;
            break;
        }
    }
}

void printCharacter(Character *character) {
    printf("Name: %s\n", character->name);
    printf("Health: %d\n", character->health);
    printf("Attack: %d\n", character->attack);
    printf("Defence: %d\n", character->defence);
}

void printLocation(Location *location) {
    printf("Name: %s\n", location->name);
    printf("X: %d\n", location->x);
    printf("Y: %d\n", location->y);
}

void printSector(Sector *sector) {
    printf("Name: %s\n", sector->name);
    printLocation(sector->location);
    for (int i = 0; i < 10; i++) {
        if (sector->characters[i] != NULL) {
            printCharacter(sector->characters[i]);
        }
    }
}

void printGalaxy(Galaxy *galaxy) {
    for (int i = 0; i < 10; i++) {
        if (galaxy->sectors[i] != NULL) {
            printSector(galaxy->sectors[i]);
        }
    }
}

int main() {
    Character *player = createCharacter("Player", 100, 10, 10);

    Location *location1 = createLocation("Location 1", 0, 0);
    Sector *sector1 = createSector("Sector 1", location1);
    addCharacterToSector(sector1, player);

    Location *location2 = createLocation("Location 2", 100, 100);
    Sector *sector2 = createSector("Sector 2", location2);

    Galaxy *galaxy = createGalaxy();
    addSectorToGalaxy(galaxy, sector1);
    addSectorToGalaxy(galaxy, sector2);

    printGalaxy(galaxy);

    return 0;
}