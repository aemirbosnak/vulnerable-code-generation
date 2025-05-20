//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    char *description;
    int health;
    int attack;
} Enemy;

typedef struct {
    char *name;
    int health;
    int attack;
    int defense;
} Player;

void generateEnemy(Enemy *enemy) {
    enemy->name = malloc(10 * sizeof(char));
    sprintf(enemy->name, "Bandit %d", rand() % 10 + 1);
    enemy->description = malloc(50 * sizeof(char));
    sprintf(enemy->description, "A ruthless bandit looking for an easy target.");
    enemy->health = rand() % 30 + 10;
    enemy->attack = rand() % 10 + 1;
}

void generatePlayer(Player *player) {
    player->name = malloc(10 * sizeof(char));
    sprintf(player->name, "Survivor");
    player->health = 100;
    player->attack = 5;
    player->defense = 3;
}

void printEnemy(Enemy enemy) {
    printf("Enemy: %s\n", enemy.name);
    printf("Description: %s\n", enemy.description);
    printf("Health: %d\n", enemy.health);
    printf("Attack: %d\n", enemy.attack);
}

void printPlayer(Player player) {
    printf("Player:\n");
    printf("Name: %s\n", player.name);
    printf("Health: %d\n", player.health);
    printf("Attack: %d\n", player.attack);
    printf("Defense: %d\n", player.defense);
}

int fight(Enemy enemy, Player player) {
    int playerAttack = rand() % player.attack + 1;
    int enemyAttack = rand() % enemy.attack + 1;

    player.health -= enemyAttack;
    enemy.health -= playerAttack;

    if (player.health <= 0) {
        printf("You have been defeated by the %s.\n", enemy.name);
        return 0;
    } else if (enemy.health <= 0) {
        printf("You have defeated the %s.\n", enemy.name);
        return 1;
    }

    return 2;
}

int main() {
    srand(time(NULL));

    Enemy enemy;
    generateEnemy(&enemy);
    printEnemy(enemy);

    Player player;
    generatePlayer(&player);
    printPlayer(player);

    int result = fight(enemy, player);

    if (result == 1) {
        printf("You have survived the encounter.\n");
    } else {
        printf("You have been defeated.\n");
    }

    return 0;
}