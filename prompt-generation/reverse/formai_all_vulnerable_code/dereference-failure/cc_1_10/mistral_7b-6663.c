//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct MagicalCreature {
    char name[30];
    int mana;
    float health;
} Creature;

Creature* SummonCreature() {
    Creature* newCreature = (Creature*) malloc(sizeof(Creature));
    strcpy(newCreature->name, "Curious Goblin");
    newCreature->mana = rand() % 100 + 1;
    newCreature->health = (float) rand() / (float) RAND_MAX * 100.0;
    srand(time(NULL));
    return newCreature;
}

void DestroyCreature(Creature* creature) {
    free(creature);
    printf("\n%s disappears in a puff of smoke.\n", creature->name);
}

void PrintCreatureStats(Creature* creature) {
    printf("\nName: %s", creature->name);
    printf("\nMana: %d", creature->mana);
    printf("\nHealth: %.2f%%", creature->health);
}

int main() {
    Creature* myCreature = SummonCreature();
    PrintCreatureStats(myCreature);
    printf("\n%s casts a powerful spell, consuming %d mana points...", myCreature->name, myCreature->mana);
    myCreature->mana -= 50;
    printf("\n%d mana points remaining.\n", myCreature->mana);
    if (myCreature->mana <= 0) {
        printf("\n%s is weakened and cannot cast any more spells.\n", myCreature->name);
        DestroyCreature(myCreature);
    } else {
        printf("\n%s continues to fight.\n", myCreature->name);
        int damage = rand() % 10 + 1;
        myCreature->health -= damage;
        printf("\n%s takes %d damage and now has %.2f%% health remaining.\n", myCreature->name, damage, myCreature->health);
        if (myCreature->health <= 0) {
            printf("\n%s has been defeated!\n", myCreature->name);
            DestroyCreature(myCreature);
        }
    }
    return 0;
}