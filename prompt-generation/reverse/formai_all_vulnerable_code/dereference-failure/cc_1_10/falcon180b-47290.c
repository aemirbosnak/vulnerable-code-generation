//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
    char *name;
    int health;
    int attack;
    int defense;
    int speed;
} Creature;

void generateCreature(Creature *creature) {
    creature->name = (char *)malloc(20 * sizeof(char));
    sprintf(creature->name, "Creature %d", rand() % 1000);
    creature->health = rand() % 100 + 1;
    creature->attack = rand() % 100 + 1;
    creature->defense = rand() % 100 + 1;
    creature->speed = rand() % 100 + 1;
}

void printCreatureStats(Creature creature) {
    printf("Name: %s\n", creature.name);
    printf("Health: %d\n", creature.health);
    printf("Attack: %d\n", creature.attack);
    printf("Defense: %d\n", creature.defense);
    printf("Speed: %d\n", creature.speed);
}

int main() {
    srand(time(NULL));

    Creature player;
    generateCreature(&player);
    printf("You are %s.\n", player.name);

    Creature enemy;
    generateCreature(&enemy);
    printf("You encounter %s.\n", enemy.name);

    int playerAttack = player.attack;
    int enemyDefense = enemy.defense;

    if (playerAttack > enemyDefense) {
        printf("You defeat %s!\n", enemy.name);
    } else {
        printf("You are defeated by %s.\n", enemy.name);
    }

    return 0;
}