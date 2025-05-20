//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMY_COUNT 5

typedef struct Enemy {
    char name[20];
    int health;
    int attack;
} Enemy;

void generate_enemies(Enemy **enemies, int count) {
    for (int i = 0; i < count; i++) {
        enemies[i] = malloc(sizeof(Enemy));
        enemies[i]->name[0] = 'A' + i;
        enemies[i]->health = rand() % 100;
        enemies[i]->attack = rand() % 20 + 1;
    }
}

void battle(Enemy *enemy, int player_health) {
    printf("You are facing %s.\n", enemy->name);
    printf("Their health is %d.\n", enemy->health);

    int player_damage = rand() % enemy->attack + 1;
    enemy->health -= player_damage;

    if (enemy->health <= 0) {
        printf("You have defeated %s!\n", enemy->name);
    } else {
        printf("They have taken %d damage.\n", player_damage);
        printf("Their remaining health is %d.\n", enemy->health);
    }

    if (enemy->health > 0) {
        battle(enemy, player_health);
    }
}

int main() {
    Enemy **enemies = NULL;

    generate_enemies(enemies, MAX_ENEMY_COUNT);

    int player_health = 100;

    for (int i = 0; enemies[i] && player_health > 0; i++) {
        battle(enemies[i], player_health);
    }

    if (player_health <= 0) {
        printf("You have perished in battle.\n");
    } else {
        printf("You have survived the encounter.\n");
    }

    return 0;
}