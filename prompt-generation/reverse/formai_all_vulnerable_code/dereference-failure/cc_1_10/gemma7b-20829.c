//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

#define MAX_ENEMY_ROWS 5
#define MAX_ENEMY_COLS 10

typedef struct Enemy {
    int x, y;
    int direction;
    struct Enemy* next;
} Enemy;

Enemy* createEnemy(int x, int y, int direction) {
    Enemy* enemy = malloc(sizeof(Enemy));
    enemy->x = x;
    enemy->y = y;
    enemy->direction = direction;
    enemy->next = NULL;
    return enemy;
}

void moveEnemy(Enemy* enemy) {
    switch (enemy->direction) {
        case LEFT:
            enemy->x--;
            break;
        case RIGHT:
            enemy->x++;
            break;
        case UP:
            enemy->y--;
            break;
        case DOWN:
            enemy->y++;
            break;
    }
}

void drawEnemy(Enemy* enemy) {
    printf("(");
    printf("%d, %d)", enemy->x, enemy->y);
    printf(")");
}

int main() {
    // Initialize the game board
    int board[MAX_ENEMY_ROWS][MAX_ENEMY_COLS] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Create the enemy
    Enemy* enemy = createEnemy(1, 1, RIGHT);

    // Move the enemy
    moveEnemy(enemy);

    // Draw the enemy
    drawEnemy(enemy);

    // Print the board
    for (int r = 0; r < MAX_ENEMY_ROWS; r++) {
        for (int c = 0; c < MAX_ENEMY_COLS; c++) {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    return 0;
}