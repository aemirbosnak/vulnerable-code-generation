//Gemma-7B DATASET v1.0 Category: System administration ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_CASTLES 10
#define MAX_TROOPS 20

typedef struct Castle {
    char name[20];
    int troops;
    struct Castle *next;
} Castle;

typedef struct Troop {
    char name[20];
    int strength;
    struct Troop *next;
} Troop;

Castle *head = NULL;

void createCastle(char *name, int troops) {
    Castle *newCastle = malloc(sizeof(Castle));
    strcpy(newCastle->name, name);
    newCastle->troops = troops;
    newCastle->next = NULL;

    if (head == NULL) {
        head = newCastle;
    } else {
        head->next = newCastle;
    }
}

void createTroop(char *name, int strength) {
    Troop *newTroop = malloc(sizeof(Troop));
    strcpy(newTroop->name, name);
    newTroop->strength = strength;
    newTroop->next = NULL;

    Castle *currentCastle = head;
    while (currentCastle) {
        if (strcmp(newTroop->name, currentCastle->name) == 0) {
            currentCastle->troops++;
            break;
        }
        currentCastle = currentCastle->next;
    }
}

void battle(Castle *castleA, Castle *castleB) {
    Troop *troopA = castleA->troops;
    Troop *troopB = castleB->troops;

    while (troopA && troopB) {
        if (troopA->strength > troopB->strength) {
            troopB->strength = 0;
        } else {
            troopA->strength = 0;
        }

        troopA = troopA->next;
        troopB = troopB->next;
    }

    if (troopA->strength == 0) {
        printf("%s has won the battle!\n", castleA->name);
    } else {
        printf("%s has won the battle!\n", castleB->name);
    }
}

int main() {
    createCastle("Castle A", 10);
    createCastle("Castle B", 15);
    createTroop("John", 8);
    createTroop("Mary", 6);
    battle(head, head->next);

    return 0;
}