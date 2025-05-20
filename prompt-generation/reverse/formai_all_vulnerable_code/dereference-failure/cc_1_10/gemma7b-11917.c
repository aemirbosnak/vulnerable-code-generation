//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 10

typedef struct Enemy {
    char name[20];
    int health;
    int attack;
} Enemy;

void generate_enemies(Enemy **enemies, int num_enemies) {
    for (int i = 0; i < num_enemies; i++) {
        enemies[i] = malloc(sizeof(Enemy));
        enemies[i]->name[0] = 'A' + i;
        enemies[i]->health = rand() % 100 + 10;
        enemies[i]->attack = rand() % 20 + 1;
    }
}

void battle(Enemy *enemy) {
    printf("You are battling %s.\n", enemy->name);
    printf("Enemy health: %d\n", enemy->health);
    printf("Your turn:\n");

    int choice = rand() % 3;
    switch (choice) {
        case 0:
            printf("You attacked with your sword.\n");
            enemy->health -= enemy->attack;
            break;
        case 1:
            printf("You cast a spell.\n");
            enemy->health -= enemy->attack / 2;
            break;
        case 2:
            printf("You used a potion.\n");
            enemy->health += rand() % 20;
            break;
    }

    printf("Enemy health: %d\n", enemy->health);

    if (enemy->health <= 0) {
        printf("You have defeated %s!\n", enemy->name);
    } else {
        printf("The enemy is still alive. Prepare for battle again.\n");
    }
}

int main() {
    srand(time(NULL));

    Enemy **enemies = NULL;
    generate_enemies(enemies, MAX_ENEMIES);

    for (int i = 0; i < MAX_ENEMIES; i++) {
        battle(enemies[i]);
    }

    return 0;
}