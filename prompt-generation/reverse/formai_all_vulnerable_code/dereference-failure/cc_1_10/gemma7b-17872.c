//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENEMY_ROWS 5
#define MAX_ENEMY_COLS 10

typedef struct Enemy {
    int row;
    int col;
    int direction;
    struct Enemy* next;
} Enemy;

void initialize_enemies(Enemy** enemies) {
    *enemies = NULL;
    for (int r = 0; r < MAX_ENEMY_ROWS; r++) {
        for (int c = 0; c < MAX_ENEMY_COLS; c++) {
            Enemy* new_enemy = malloc(sizeof(Enemy));
            new_enemy->row = r;
            new_enemy->col = c;
            new_enemy->direction = 0;
            new_enemy->next = *enemies;
            *enemies = new_enemy;
        }
    }
}

void move_enemies(Enemy* enemies) {
    for (Enemy* enemy = enemies; enemy; enemy = enemy->next) {
        switch (enemy->direction) {
            case 0:
                enemy->row--;
                break;
            case 1:
                enemy->col++;
                break;
            case 2:
                enemy->row++;
                break;
            case 3:
                enemy->col--;
                break;
        }

        if (enemy->row < 0 || enemy->row >= MAX_ENEMY_ROWS) {
            enemy->direction = (enemy->direction + 1) % 4;
        }

        if (enemy->col < 0 || enemy->col >= MAX_ENEMY_COLS) {
            enemy->direction = (enemy->direction + 1) % 4;
        }
    }
}

int main() {
    Enemy** enemies = NULL;
    initialize_enemies(enemies);

    for (int i = 0; i < 10; i++) {
        move_enemies(enemies);
    }

    return 0;
}