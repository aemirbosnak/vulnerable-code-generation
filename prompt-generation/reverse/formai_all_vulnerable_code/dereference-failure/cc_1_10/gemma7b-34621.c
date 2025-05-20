//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 10
#define MAX_BULLETS 50

typedef struct Enemy {
    int health;
    char name[20];
    struct Enemy* next;
} Enemy;

typedef struct Bullet {
    int x;
    int y;
    struct Bullet* next;
} Bullet;

Enemy* enemy_create(char* name, int health) {
    Enemy* enemy = malloc(sizeof(Enemy));
    enemy->health = health;
    strcpy(enemy->name, name);
    enemy->next = NULL;
    return enemy;
}

Bullet* bullet_create(int x, int y) {
    Bullet* bullet = malloc(sizeof(Bullet));
    bullet->x = x;
    bullet->y = y;
    bullet->next = NULL;
    return bullet;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the enemy list
    Enemy* head = enemy_create("Bob", 100);
    head->next = enemy_create("Alice", 80);
    head->next->next = enemy_create("Tom", 60);

    // Create the bullet list
    Bullet* tail = bullet_create(10, 10);
    tail->next = bullet_create(20, 20);
    tail->next->next = bullet_create(30, 30);

    // Simulate combat
    while (head && tail) {
        // Randomly select an enemy
        int enemy_index = rand() % MAX_ENEMIES;
        Enemy* enemy = head;
        for (int i = 0; i < enemy_index; i++) {
            enemy = enemy->next;
        }

        // Randomly select a bullet
        int bullet_index = rand() % MAX_BULLETS;
        Bullet* bullet = tail;
        for (int i = 0; i < bullet_index; i++) {
            bullet = bullet->next;
        }

        // Check if the bullet hits the enemy
        if (bullet->x >= enemy->health) {
            printf("%s has been defeated!\n", enemy->name);
            free(enemy);
            enemy = NULL;
        } else {
            printf("Bullet missed %s.\n", enemy->name);
        }

        // Move the bullet
        bullet->x++;
        tail = bullet;
    }

    // Print the remaining enemies
    if (head) {
        printf("Remaining enemies:\n");
        for (Enemy* enemy = head; enemy; enemy = enemy->next) {
            printf("%s (health: %d)\n", enemy->name, enemy->health);
        }
    }

    return 0;
}