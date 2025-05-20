//GEMINI-pro DATASET v1.0 Category: Space Invaders Game Clone ; Style: all-encompassing
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define CELL_SIZE  5
#define CELL_COUNT 20

typedef struct {
    int x, y;
} coord_t;

char *screen[CELL_COUNT];
int  aliens[CELL_COUNT];
int  bullets[CELL_COUNT];
int  score   = 0;

void
init_screen(void)
{
    int i;

    for (i = 0; i < CELL_COUNT; i++) {
        screen[i] = malloc(CELL_COUNT);
        memset(screen[i], ' ', CELL_COUNT);
    }
}

void
clear_screen(void)
{
    for (int i = 0; i < CELL_COUNT; i++) {
        memset(screen[i], ' ', CELL_COUNT);
    }
}

void
render_screen(void)
{
    for (int i = 0; i < CELL_COUNT; i++) {
        printf("%s\n", screen[i]);
    }
}

void
init_aliens(void)
{
    for (int i = 0; i < CELL_COUNT; i++) {
        aliens[i] = 1;
    }
}

void
move_aliens(void)
{
    for (int i = 0; i < CELL_COUNT; i++) {
        if (aliens[i]) {
            aliens[i] += 1;
        }
    }
}

void
init_bullets(void)
{
    for (int i = 0; i < CELL_COUNT; i++) {
        bullets[i] = 0;
    }
}

void
fire_bullet(coord_t *pos)
{
    for (int i = 0; i < CELL_COUNT; i++) {
        if (!bullets[i]) {
            bullets[i] = pos->y;
            break;
        }
    }
}

void
move_bullets(void)
{
    for (int i = 0; i < CELL_COUNT; i++) {
        if (bullets[i]) {
            bullets[i] -= 1;
        }
    }
}

int
check_collisions(void)
{
    int hit = 0;

    for (int i = 0; i < CELL_COUNT; i++) {
        if (bullets[i] && aliens[i]) {
            hit = 1;
            bullets[i] = 0;
            aliens[i]   = 0;
            score++;
        }
    }

    return hit;
}

int
main(void)
{
    coord_t player;
    int  quit = 0;
    int  hit;

    player.x = CELL_COUNT / 2;
    player.y = CELL_COUNT - 1;

    init_screen();
    init_aliens();
    init_bullets();

    srand(time(NULL));

    while (!quit) {
        clear_screen();

        screen[player.y][player.x] = 'X';

        for (int i = 0; i < CELL_COUNT; i++) {
            if (aliens[i]) {
                screen[CELL_COUNT - aliens[i]][i] = 'O';
            }
            if (bullets[i]) {
                screen[bullets[i]][i] = '|';
            }
        }

        render_screen();

        move_aliens();
        move_bullets();
        hit = check_collisions();

        if (hit) {
            printf("Score: %d\n", score);
        }

        if (aliens[0]) {
            printf("Game over!\n");
            quit = 1;
        }

        char c = getchar();
        switch (c) {
            case 'a':
                if (player.x > 0) {
                    player.x -= 1;
                }
                break;
            case 'd':
                if (player.x < CELL_COUNT - 1) {
                    player.x += 1;
                }
                break;
            case 'w':
                if (player.y > 0) {
                    player.y -= 1;
                }
                break;
            case 's':
                if (player.y < CELL_COUNT - 1) {
                    player.y += 1;
                }
                break;
            case 'f':
                fire_bullet(&player);
                break;
            case 'q':
                quit = 1;
                break;
        }
    }

    for (int i = 0; i < CELL_COUNT; i++) {
        free(screen[i]);
    }

    return 0;
}