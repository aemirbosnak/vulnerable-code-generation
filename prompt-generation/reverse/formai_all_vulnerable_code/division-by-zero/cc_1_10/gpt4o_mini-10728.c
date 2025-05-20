//GPT-4o-mini DATASET v1.0 Category: Space Invaders Game Clone ; Style: future-proof
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_ENEMIES 20
#define ENEMY_WIDTH 3
#define PLAYER_WIDTH 3

typedef struct {
    int x, y;
    int alive;
} Enemy;

typedef struct {
    int x, y;
} Player;

Player player;
Enemy enemies[MAX_ENEMIES];

void initialize_game() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    timeout(100);
    // Initialize player
    player.x = COLS / 2 - PLAYER_WIDTH / 2;
    player.y = LINES - 2;

    // Initialize enemies
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].x = rand() % (COLS - ENEMY_WIDTH);
        enemies[i].y = rand() % (LINES / 2);
        enemies[i].alive = 1;
    }
}

void draw_player() {
    mvprintw(player.y, player.x, "<<<");
}

void draw_enemies() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].alive) {
            mvprintw(enemies[i].y, enemies[i].x, "XXX");
        }
    }
}

void move_player(int direction) {
    if (direction == KEY_LEFT && player.x > 0) {
        player.x -= 1;
    } else if (direction == KEY_RIGHT && player.x < COLS - PLAYER_WIDTH) {
        player.x += 1;
    }
}

void update_game() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].alive) {
            enemies[i].y += 1; // Simulate enemy falling
            if (enemies[i].y >= LINES) {
                enemies[i].alive = 0; // Mark enemy as dead
            }
        }
    }
}

void shoot(int bullet_x, int bullet_y) {
    while (bullet_y > 0) {
        mvprintw(bullet_y, bullet_x, "|");
        refresh();
        usleep(100000); // Control the speed of the bullet
        mvprintw(bullet_y, bullet_x, " ");
        bullet_y--;
        
        // Check for collisions
        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (enemies[i].alive && bullet_x >= enemies[i].x && bullet_x < enemies[i].x + ENEMY_WIDTH &&
                bullet_y == enemies[i].y) {
                enemies[i].alive = 0; // Mark enemy as dead
                goto end_shooting;
            }
        }
    }
end_shooting:
    mvprintw(bullet_y, bullet_x, " ");
    refresh();
}

int main() {
    srand(time(NULL));
    initialize_game();
    while (1) {
        clear();
        draw_player();
        draw_enemies();
        
        int ch = getch();
        switch (ch) {
            case KEY_LEFT:
            case KEY_RIGHT:
                move_player(ch);
                break;
            case ' ':
                shoot(player.x + PLAYER_WIDTH / 2, player.y - 1);
                break;
            case 'q':
                endwin();
                return 0; // Exit the game
        }
        update_game();
        refresh();
    }
    endwin();
    return 0;
}