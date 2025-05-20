//Gemma-7B DATASET v1.0 Category: System administration ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_CASTLES 10
#define MAX_SOLDIERS 100

typedef struct Castle {
    char name[20];
    int soldiers;
    struct Castle *next;
} Castle;

typedef struct Soldier {
    char name[20];
    int strength;
    struct Soldier *next;
} Soldier;

Castle *headCastle = NULL;
Soldier *headSoldier = NULL;

void createCastle(char *name, int soldiers) {
    Castle *newCastle = (Castle *)malloc(sizeof(Castle));
    strcpy(newCastle->name, name);
    newCastle->soldiers = soldiers;
    newCastle->next = headCastle;
    headCastle = newCastle;
}

void createSoldier(char *name, int strength) {
    Soldier *newSoldier = (Soldier *)malloc(sizeof(Soldier));
    strcpy(newSoldier->name, name);
    newSoldier->strength = strength;
    newSoldier->next = headSoldier;
    headSoldier = newSoldier;
}

void listCastles() {
    Castle *currentCastle = headCastle;
    while (currentCastle) {
        printf("%s has %d soldiers\n", currentCastle->name, currentCastle->soldiers);
        currentCastle = currentCastle->next;
    }
}

void listSoldiers() {
    Soldier *currentSoldier = headSoldier;
    while (currentSoldier) {
        printf("%s has strength %d\n", currentSoldier->name, currentSoldier->strength);
        currentSoldier = currentSoldier->next;
    }
}

int main() {
    createCastle("Castle A", 50);
    createCastle("Castle B", 20);
    createCastle("Castle C", 10);

    createSoldier("John", 15);
    createSoldier("Mary", 10);
    createSoldier("Bob", 12);

    listCastles();
    listSoldiers();

    return 0;
}