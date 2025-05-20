//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_CASTLES 10
#define MAX_TROOPS 100

typedef struct Castle {
    char name[20];
    int troops;
    struct Castle* next;
} Castle;

typedef struct Troop {
    char name[20];
    int strength;
    struct Troop* next;
} Troop;

Castle* createCastle(char* name, int troops) {
    Castle* newCastle = malloc(sizeof(Castle));
    strcpy(newCastle->name, name);
    newCastle->troops = troops;
    newCastle->next = NULL;
    return newCastle;
}

Troop* createTroop(char* name, int strength) {
    Troop* newTroop = malloc(sizeof(Troop));
    strcpy(newTroop->name, name);
    newTroop->strength = strength;
    newTroop->next = NULL;
    return newTroop;
}

void battle(Castle* attacker, Castle* defender) {
    Troop* attackerTroops = attacker->troops;
    Troop* defenderTroops = defender->troops;

    while (attackerTroops && defenderTroops) {
        int attackerStrength = attackerTroops->strength;
        int defenderStrength = defenderTroops->strength;

        if (attackerStrength > defenderStrength) {
            defenderTroops->strength = 0;
            printf("%s has won the battle!\n", attacker->name);
        } else if (defenderStrength > attackerStrength) {
            attackerTroops->strength = 0;
            printf("%s has won the battle!\n", defender->name);
        } else {
            attackerTroops->strength = 0;
            defenderTroops->strength = 0;
            printf("%s and %s have drawn the battle.\n", attacker->name, defender->name);
        }

        attackerTroops = attackerTroops->next;
        defenderTroops = defenderTroops->next;
    }

    if (attackerTroops == NULL && defenderTroops == NULL) {
        printf("The battle has ended.\n");
    }
}

int main() {
    Castle* castleList = NULL;
    Troop* troopList = NULL;

    // Create some castles
    castleList = createCastle("Castle A", 50);
    castleList = createCastle("Castle B", 30);
    castleList = createCastle("Castle C", 20);

    // Create some troops
    troopList = createTroop("Knight A", 10);
    troopList = createTroop("Knight B", 8);
    troopList = createTroop("Knight C", 6);

    // Battle
    battle(castleList, castleList);

    return 0;
}