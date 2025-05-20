//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Enemies 10
#define BOARD_SIZE 20

typedef struct Enemy {
    int x;
    int y;
    int direction;
    int speed;
} Enemy;

void initializeEnemies(Enemy **enemies) {
    for (int i = 0; i < MAX_Enemies; i++) {
        enemies[i] = malloc(sizeof(Enemy));
        enemies[i]->x = rand() % BOARD_SIZE;
        enemies[i]->y = rand() % BOARD_SIZE;
        enemies[i]->direction = rand() % 2;
        enemies[i]->speed = rand() % 3;
    }
}

void moveEnemies(Enemy **enemies) {
    for (int i = 0; i < MAX_Enemies; i++) {
        switch (enemies[i]->direction) {
            case 0:
                enemies[i]->x++;
                break;
            case 1:
                enemies[i]->x--;
                break;
            case 2:
                enemies[i]->y++;
                break;
            case 3:
                enemies[i]->y--;
                break;
        }

        if (enemies[i]->x >= BOARD_SIZE || enemies[i]->x < 0) {
            enemies[i]->direction *= -1;
        }

        if (enemies[i]->y >= BOARD_SIZE || enemies[i]->y < 0) {
            enemies[i]->direction *= -1;
        }
    }
}

int main() {
    Enemy **enemies = malloc(MAX_Enemies * sizeof(Enemy));
    initializeEnemies(enemies);

    for (int i = 0; i < 100; i++) {
        moveEnemies(enemies);
        printf("Enemy positions:");
        for (int j = 0; j < MAX_Enemies; j++) {
            printf(" (%d, %d)", enemies[j]->x, enemies[j]->y);
        }
        printf("\n");
    }

    free(enemies);
    return 0;
}