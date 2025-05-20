//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SURVIVORS 10

typedef struct Survivor {
    char name[20];
    int health;
    int strength;
    int agility;
    struct Survivor* next;
} Survivor;

Survivor* createSurvivor(char* name, int health, int strength, int agility) {
    Survivor* survivor = malloc(sizeof(Survivor));
    strcpy(survivor->name, name);
    survivor->health = health;
    survivor->strength = strength;
    survivor->agility = agility;
    survivor->next = NULL;
    return survivor;
}

void battle(Survivor* survivor1, Survivor* survivor2) {
    int damage = 0;
    while (survivor1->health > 0 && survivor2->health > 0) {
        damage = survivor1->strength * rand() % survivor2->agility;
        survivor2->health -= damage;
        printf("%s attacks %s and deals %d damage!\n", survivor1->name, survivor2->name, damage);
    }

    if (survivor1->health > survivor2->health) {
        printf("%s has won the battle!\n", survivor1->name);
    } else if (survivor2->health > survivor1->health) {
        printf("%s has won the battle!\n", survivor2->name);
    } else {
        printf("It's a draw!\n");
    }
}

int main() {
    time_t t = time(NULL);
    srand(t);

    Survivor* head = createSurvivor("John", 100, 15, 12);
    Survivor* second = createSurvivor("Alice", 80, 12, 14);

    battle(head, second);

    return 0;
}