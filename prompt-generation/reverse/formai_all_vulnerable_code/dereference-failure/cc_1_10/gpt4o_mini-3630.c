//GPT-4o-mini DATASET v1.0 Category: Space Invaders Game Clone ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20
#define MAX_ENEMIES 10

typedef struct {
    int x, y;
    int alive;
} Enemy;

typedef struct {
    int x, y;
    int alive;
} Player;

void init(Player *player, Enemy enemies[], int *enemy_count) {
    player->x = WIDTH / 2;
    player->y = HEIGHT - 1;
    player->alive = 1;

    srand(time(NULL));
    *enemy_count = rand() % MAX_ENEMIES + 1;

    for (int i = 0; i < *enemy_count; i++) {
        enemies[i].x = rand() % WIDTH;
        enemies[i].y = i;
        enemies[i].alive = 1;
    }
}

void draw(Player player, Enemy enemies[], int enemy_count) {
    clear();
    mvprintw(player.y, player.x, "A");

    for (int i = 0; i < enemy_count; i++) {
        if (enemies[i].alive) {
            mvprintw(enemies[i].y, enemies[i].x, "M");
        }
    }

    refresh();
}

void move_enemies(Enemy enemies[], int enemy_count) {
    for (int i = 0; i < enemy_count; i++) {
        if (enemies[i].alive) {
            enemies[i].y++;
            if (enemies[i].y >= HEIGHT) {
                enemies[i].alive = 0; // Enemy goes off-screen
            }
        }
    }
}

void shoot(int bullets[][2], int *bullet_count, Player player) {
    if (*bullet_count < 1) { // Keep one bullet at a time
        bullets[*bullet_count][0] = player.x;
        bullets[*bullet_count][1] = player.y - 1;
        (*bullet_count)++;
    }
}

void move_bullets(int bullets[][2], int *bullet_count) {
    for (int i = 0; i < *bullet_count; i++) {
        bullets[i][1]--;
    }
    if (bullets[0][1] < 0) {
        (*bullet_count)--;
        for (int i = 0; i < *bullet_count; i++) {
            bullets[i][0] = bullets[i + 1][0];
            bullets[i][1] = bullets[i + 1][1];
        }
    }
}

void check_collisions(Enemy enemies[], int enemy_count, int bullets[][2], int *bullet_count) {
    for (int i = 0; i < *bullet_count; i++) {
        for (int j = 0; j < enemy_count; j++) {
            if (bullets[i][0] == enemies[j].x && bullets[i][1] == enemies[j].y && enemies[j].alive) {
                enemies[j].alive = 0; // Mark enemy as hit
                *bullet_count = 0; // Reset bullet count
                break;
            }
        }
    }
}

int main() {
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    Player player;
    Enemy enemies[MAX_ENEMIES];
    int enemy_count = 0;
    int bullets[1][2]; // Store one bullet
    int bullet_count = 0;

    init(&player, enemies, &enemy_count);

    while (player.alive) {
        draw(player, enemies, enemy_count);
        move_enemies(enemies, enemy_count);
        move_bullets(bullets, &bullet_count);
        check_collisions(enemies, enemy_count, bullets, &bullet_count);

        int ch = getch();
        switch (ch) {
            case KEY_LEFT:
                if (player.x > 0) player.x--;
                break;
            case KEY_RIGHT:
                if (player.x < WIDTH - 1) player.x++;
                break;
            case ' ':
                shoot(bullets, &bullet_count, player);
                break;
        }

        usleep(100000); // Sleep to control game speed
    }

    endwin();
    printf("Game Over\n");
    return 0;
}