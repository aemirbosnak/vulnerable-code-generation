//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMY_COUNT 5

typedef struct Enemy {
    char name[20];
    int health;
    int attack;
    int defense;
} Enemy;

void initializeEnemies(Enemy **enemies, int num) {
    for (int i = 0; i < num; i++) {
        enemies[i] = malloc(sizeof(Enemy));
        enemies[i]->name[0] = '\0';
        enemies[i]->health = 100;
        enemies[i]->attack = rand() % 10 + 1;
        enemies[i]->defense = rand() % 5 + 1;
    }
}

void battle(Enemy **enemies, int num) {
    for (int i = 0; i < num; i++) {
        printf("You are facing %s.\n", enemies[i]->name);
        printf("Health: %d, Attack: %d, Defense: %d\n", enemies[i]->health, enemies[i]->attack, enemies[i]->defense);

        int your_turn = rand() % 2;
        switch (your_turn) {
            case 0:
                printf("You attack!\n");
                enemies[i]->health -= rand() % enemies[i]->defense + 1;
                break;
            case 1:
                printf("You defend.\n");
                break;
        }

        if (enemies[i]->health <= 0) {
            printf("%s has been defeated.\n", enemies[i]->name);
            free(enemies[i]);
        } else {
            printf("Enemy's turn.\n");
            int enemy_attack = rand() % enemies[i]->attack + 1;
            printf("Enemy attacks for %d damage.\n", enemy_attack);
            enemies[i]->health -= enemy_attack;
            if (enemies[i]->health <= 0) {
                printf("%s has been defeated.\n", enemies[i]->name);
                free(enemies[i]);
            }
        }
    }
}

int main() {
    Enemy **enemies = NULL;
    initializeEnemies(enemies, MAX_ENEMY_COUNT);
    battle(enemies, MAX_ENEMY_COUNT);
    return 0;
}