//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct {
    int x, y;
} point;

typedef struct {
    point pos;
    int dir;
} snake;

typedef struct {
    int width, height;
    snake *snakes;
    int num_snakes;
    point food;
} game;

void init_game(game *g, int w, int h, int num) {
    g->width = w;
    g->height = h;
    g->num_snakes = num;
    g->snakes = malloc(sizeof(snake) * num);
    for (int i = 0; i < num; i++) {
        g->snakes[i].pos.x = rand() % w;
        g->snakes[i].pos.y = rand() % h;
        g->snakes[i].dir = rand() % 4;
    }
    g->food.x = rand() % w;
    g->food.y = rand() % h;
}

void draw_game(game *g) {
    for (int y = 0; y < g->height; y++) {
        for (int x = 0; x < g->width; x++) {
            int found = 0;
            for (int i = 0; i < g->num_snakes; i++) {
                if (g->snakes[i].pos.x == x && g->snakes[i].pos.y == y) {
                    putchar('#');
                    found = 1;
                    break;
                }
            }
            if (!found) {
                if (g->food.x == x && g->food.y == y) {
                    putchar('*');
                } else {
                    putchar(' ');
                }
            }
        }
        putchar('\n');
    }
}

void update_game(game *g) {
    for (int i = 0; i < g->num_snakes; i++) {
        snake *s = &g->snakes[i];
        switch (s->dir) {
            case 0:  // up
                s->pos.y--;
                break;
            case 1:  // right
                s->pos.x++;
                break;
            case 2:  // down
                s->pos.y++;
                break;
            case 3:  // left
                s->pos.x--;
                break;
        }

        // wrap around
        if (s->pos.x < 0) {
            s->pos.x = g->width - 1;
        } else if (s->pos.x >= g->width) {
            s->pos.x = 0;
        }
        if (s->pos.y < 0) {
            s->pos.y = g->height - 1;
        } else if (s->pos.y >= g->height) {
            s->pos.y = 0;
        }

        // check for collision
        for (int j = 0; j < g->num_snakes; j++) {
            if (i != j && s->pos.x == g->snakes[j].pos.x && s->pos.y == g->snakes[j].pos.y) {
                // game over
                printf("Game over!\n");
                exit(0);
            }
        }

        // check for food
        if (s->pos.x == g->food.x && s->pos.y == g->food.y) {
            // grow snake
            s->pos.x += (s->dir == 1) - (s->dir == 3);
            s->pos.y += (s->dir == 0) - (s->dir == 2);

            // place new food
            g->food.x = rand() % g->width;
            g->food.y = rand() % g->height;
        }
    }
}

void get_input(game *g) {
    char c = getchar();
    switch (c) {
        case 'w':
            g->snakes[0].dir = 0;
            break;
        case 'd':
            g->snakes[0].dir = 1;
            break;
        case 's':
            g->snakes[0].dir = 2;
            break;
        case 'a':
            g->snakes[0].dir = 3;
            break;
        case 'q':
            exit(0);
            break;
    }
}

int main() {
    srand(time(NULL));

    game g;
    init_game(&g, 40, 20, 2);

    while (1) {
        draw_game(&g);
        update_game(&g);
        get_input(&g);
        usleep(100000);
    }

    return 0;
}